/*
  Rakarrack Audio FX
  Valve DSP Code based Steve Harris valve LADSPA plugin(swh-plugins).
  ZynAddSubFX effect structure - Copyright (C) 2002-2005 Nasca Octavian Paul
  Modified and adapted for rakarrack by Josep Andreu

  Valve.C - Distorsion effect

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Valve.h"

Valve::Valve(double sample_rate, uint32_t intermediate_bufsize) :
    Ppreset(),
    outvolume(0.5f),
    PERIOD(intermediate_bufsize),
    fSAMPLE_RATE(sample_rate),
    Pvolume(50),
    Ppanning(),
    Plrcross(40),
    Pdrive(90),
    Plevel(64),
    Pnegate(),
    Plpf(127),
    Phpf(),
    Pstereo(),
    Pprefiltering(),
    Q_q(64),
    Ped(),
    Presence(),
    panning(),
    lrcross((float) Plrcross / 127.0f * 1.0f),
    q((float) Q_q / 127.0f - 1.0f),
    dist((float) Pdrive / 127.0f * 40.0f + .5f),
    otml(),
    otmr(),
    itml(),
    itmr(),
    factor(1.0f - ((float) Q_q / 128.0f)),
    atk(1.0f - 40.0f / sample_rate),
    rm(),               // initialized to 0.0 here
    coef(),
    qcoef(),
    fdist(),
    inputvol(),
    interpbuf(NULL),
    lpfl(NULL),
    lpfr(NULL),
    hpfl(NULL),
    hpfr(NULL),
    harm(NULL),
    Fpre(NULL)
{
    initialize();

    rm[0] = 1.0f;
    rm[2] = -1.0f;
    rm[4] = 1.0f;
    rm[6] = -1.0f;
    rm[8] = 1.0f;

    harm = new HarmEnhancer(rm, 20.0f, 20000.0f, 1.0f, sample_rate, PERIOD);

    setlpf(127);
    sethpf(1);
    init_coefs();

    setpreset(Ppreset);
    cleanup();
}

Valve::~Valve()
{
    clear_initialize();
    delete harm;
}

/*
 * Cleanup the effect
 */
void
Valve::cleanup()
{
    lpfl->cleanup();
    hpfl->cleanup();
    lpfr->cleanup();
    hpfr->cleanup();
    otml = 0.0f;
    itml = 0.0f;
    otmr = 0.0f;
    itmr = 0.0f;
}

#ifdef LV2_SUPPORT
void
Valve::lv2_update_params(uint32_t period)
{
    if (period > PERIOD) // only re-initialize if period > intermediate_bufsize of declaration
    {
        PERIOD = period;
        clear_initialize();
        initialize();
        cleanup();
        setlpf(Plpf);
        sethpf(Phpf);
        //cleanup();
    }
    else
    {
        PERIOD = period;
    }

    harm->lv2_update_params(period);
}
#endif // LV2

void
Valve::initialize()
{
    interpbuf = new float[PERIOD];
    lpfl = new AnalogFilter(2, 22000.0f, 1.0f, 0, fSAMPLE_RATE, interpbuf);
    lpfr = new AnalogFilter(2, 22000.0f, 1.0f, 0, fSAMPLE_RATE, interpbuf);
    hpfl = new AnalogFilter(3, 20.0f, 1.0f, 0, fSAMPLE_RATE, interpbuf);
    hpfr = new AnalogFilter(3, 20.0f, 1.0f, 0, fSAMPLE_RATE, interpbuf);
}

void
Valve::clear_initialize()
{
    delete[] interpbuf;
    delete lpfl;
    delete lpfr;
    delete hpfl;
    delete hpfr;
}

/*
 * Apply the filters
 */

void
Valve::applyfilters(float * efxoutl, float * efxoutr)
{
    lpfl->filterout(efxoutl, PERIOD);
    hpfl->filterout(efxoutl, PERIOD);

    if (Pstereo != 0)
    {
        //stereo
        lpfr->filterout(efxoutr, PERIOD);
        hpfr->filterout(efxoutr, PERIOD);
    }
}

float
Valve::Wshape(float x)
{
    if (x < factor)
        return (x);

    if (x > factor)
        return (factor + (x - factor) / powf(1.0f + ((x - factor) / (1.0f - factor)), 2.0f));

    if (x > 1.0f)
        return ((factor + 1.0f)*.5f);
    
    return (0.0);
}

/*
 * Effect output
 */
void
Valve::out(float * efxoutl, float * efxoutr)
{
    if (Pstereo != 0)
    {
        //Stereo
        for (unsigned int i = 0; i < PERIOD; i++)
        {
            efxoutl[i] = efxoutl[i] * inputvol;
            efxoutr[i] = efxoutr[i] * inputvol;
        }
    }
    else
    {
        for (unsigned int i = 0; i < PERIOD; i++)
        {
            efxoutl[i] = (efxoutl[i] + efxoutr[i]) * inputvol;
        }
    }

    harm->harm_out(efxoutl, efxoutr);

    if (Pprefiltering != 0)
    {
        applyfilters(efxoutl, efxoutr);
    }

    if (Ped)
    {
        for (unsigned int i = 0; i < PERIOD; i++)
        {
            efxoutl[i] = Wshape(efxoutl[i]);
            
            if (Pstereo != 0)
            {
                efxoutr[i] = Wshape(efxoutr[i]);
            }
        }
    }

    float fx = 0.0f;
    
    for (unsigned int i = 0; i < PERIOD; i++)
    { //soft limiting to 3.0 (max)
        fx = efxoutl[i];
        
        if (fx > 1.0f)
        {
            fx = 3.0f - 2.0f / sqrtf(fx);
        }

        efxoutl[i] = fx;
        fx = efxoutr[i];

        if (fx > 1.0f)
        {
            fx = 3.0f - 2.0f / sqrtf(fx);
        }

        efxoutr[i] = fx;
    }

    if (q == 0.0f)
    {
        for (unsigned int i = 0; i < PERIOD; i++)
        {
            //            if (efxoutl[i] == q) fx = fdist;
            if ((fabs(efxoutl[i] - 0.0f) <= 1.19e-7f))
            {
                fx = fdist; // float comparison to zero (1.19e-7f) otherwise we get inf & no sound
            }
            else
            {
                fx = efxoutl[i] / (1.0f - powf(2.0f, -dist * efxoutl[i]));
            }

            otml = atk * otml + fx - itml;
            itml = fx;
            efxoutl[i] = otml;
        }
    }
    else
    {
        for (unsigned int i = 0; i < PERIOD; i++)
        {
            if (efxoutl[i] == q)
            {
                fx = fdist + qcoef;
            }
            else
            {
                fx = (efxoutl[i] - q) / (1.0f - powf(2.0f, -dist * (efxoutl[i] - q))) + qcoef;
            }

            otml = atk * otml + fx - itml;
            itml = fx;
            efxoutl[i] = otml;
        }
    }

    if (Pstereo != 0)
    {
        if (q == 0.0f)
        {
            for (unsigned int i = 0; i < PERIOD; i++)
            {
                //                if (efxoutr[i] == q) fx = fdist;
                if ((fabs(efxoutr[i] - 0.0f) <= 1.19e-7f))
                {
                    fx = fdist; // float comparison to zero (1.19e-7f) otherwise we get inf & no sound
                }
                else
                {
                    fx = efxoutr[i] / (1.0f - powf(2.0f, -dist * efxoutr[i]));
                }

                otmr = atk * otmr + fx - itmr;
                itmr = fx;
                efxoutr[i] = otmr;

            }
        }
        else
        {
            for (unsigned int i = 0; i < PERIOD; i++)
            {
                if (efxoutr[i] == q)
                {
                    fx = fdist + qcoef;
                }
                else
                {
                    fx = (efxoutr[i] - q) / (1.0f - powf(2.0f, -dist * (efxoutr[i] - q))) + qcoef;
                }

                otmr = atk * otmr + fx - itmr;
                itmr = fx;
                efxoutr[i] = otmr;
            }
        }
    }

    if (Pprefiltering == 0)
    {
        applyfilters(efxoutl, efxoutr);
    }

    if (Pstereo == 0)
    {
        memcpy(efxoutr, efxoutl, PERIOD * sizeof (float));
    }

    float level = dB2rap(60.0f * (float) Plevel / 127.0f - 40.0f);
    float lout, rout, l, r;     // initialize o.k.
    
    for (unsigned int i = 0; i < PERIOD; i++)
    {
        lout = efxoutl[i];
        rout = efxoutr[i];

        l = lout * (1.0f - lrcross) + rout * lrcross;
        r = rout * (1.0f - lrcross) + lout * lrcross;

        lout = l;
        rout = r;

        efxoutl[i] = lout * 2.0f * level * (1.0f - panning);
        efxoutr[i] = rout * 2.0f * level * panning;
    }
}

/*
 * Parameter control
 */
void
Valve::init_coefs()
{
    coef = 1.0 / (1.0f - powf(2.0f, dist * q));
    qcoef = q * coef;
    fdist = 1.0f / dist;
    inputvol = powf(4.0f, ((float) Pdrive - 32.0f) / 127.0f);
    
    if (Pnegate != 0)
    {
        inputvol *= -1.0f;
    }
}

void
Valve::setvolume(int Pvolume)
{
    this->Pvolume = Pvolume;

    outvolume = (float) Pvolume / 127.0f;
    
    if (Pvolume == 0)
    {
        cleanup();
    }
}

void
Valve::setpanning(int Ppanning)
{
    this->Ppanning = Ppanning;
    panning = ((float) Ppanning + 0.5f) / 127.0f;
}

void
Valve::setlrcross(int Plrcross)
{
    this->Plrcross = Plrcross;
    lrcross = (float) Plrcross / 127.0f * 1.0f;
}

void
Valve::setlpf(int value)
{
    Plpf = value;
    float fr = (float) Plpf;

    lpfl->setfreq(fr);
    lpfr->setfreq(fr);
}

void
Valve::sethpf(int value)
{
    Phpf = value;
    float fr = (float) Phpf;

    hpfl->setfreq(fr);
    hpfr->setfreq(fr);

    //Prefiltering of 51 is approx 630 Hz. 50 - 60 generally good for OD pedal.
}

void
Valve::setpresence(int value)
{
    float freq = 5.0f * (100.0f - (float) value);
    float nvol = (float) (value * .01f);

    harm->set_freqh(1, freq);
    harm->set_vol(1, nvol);
}

void
Valve::setpreset(int npreset)
{
    const int PRESET_SIZE = 13;
    const int NUM_PRESETS = 4;
    int pdata[MAX_PDATA_SIZE];
    int presets[NUM_PRESETS][PRESET_SIZE] = {
        //Valve 1
        {0, 64, 64, 127, 64, 0, 5841, 61, 1, 0, 69, 1, 84},
        //Valve 2
        {0, 64, 64, 127, 64, 0, 5078, 61, 1, 0, 112, 0, 30},
        //Valve 3
        {0, 64, 35, 80, 64, 1, 3134, 358, 1, 1, 100, 1, 30},
        //Valve 4
        {84, 64, 87, 56, 40, 0, 6703, 21, 0, 0, 52, 1, 18}

    };

    if (npreset > NUM_PRESETS - 1)
    {
        Fpre->ReadPreset(19, npreset - NUM_PRESETS + 1, pdata);
        
        for (int n = 0; n < PRESET_SIZE; n++)
            changepar(n, pdata[n]);
    }
    else
    {
        for (int n = 0; n < PRESET_SIZE; n++)
            changepar(n, presets[npreset][n]);
    }
    
    Ppreset = npreset;
    cleanup();
}

void
Valve::changepar(int npar, int value)
{
    switch (npar)
    {
    case 0:
        setvolume(value);
        break;
    case 1:
        setpanning(value);
        break;
    case 2:
        setlrcross(value);
        break;
    case 3:
        Pdrive = value;
        dist = (float) Pdrive / 127.0f * 40.0f + .5f;
        break;
    case 4:
        Plevel = value;
        break;
    case 5:
        if (value > 1)
            value = 1;
        Pnegate = value;
        break;
    case 6:
        setlpf(value);
        break;
    case 7:
        sethpf(value);
        break;
    case 8:
        if (value > 1)
            value = 1;
        Pstereo = value;
        break;
    case 9:
        Pprefiltering = value;
        break;
    case 10:
        Q_q = value;
        q = (float) Q_q / 127.0f - 1.0f;
        factor = 1.0f - ((float) Q_q / 128.0f);
        break;
    case 11:
        Ped = value;
        break;
    case 12:
        Presence = value;
        setpresence(value);
        break;
    }
    init_coefs();
}

int
Valve::getpar(int npar)
{
    switch (npar)
    {
    case 0:
        return (Pvolume);
        break;
    case 1:
        return (Ppanning);
        break;
    case 2:
        return (Plrcross);
        break;
    case 3:
        return (Pdrive);
        break;
    case 4:
        return (Plevel);
        break;
    case 5:
        return (Pnegate);
        break;
    case 6:
        return (Plpf);
        break;
    case 7:
        return (Phpf);
        break;
    case 8:
        return (Pstereo);
        break;
    case 9:
        return (Pprefiltering);
        break;
    case 10:
        return (Q_q);
        break;
    case 11:
        return (Ped);
    case 12:
        return (Presence);
        break;
    }
    return (0); //in case of bogus parameter number
}

