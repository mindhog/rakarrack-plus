/*
  rakarrack - a guitar effects software

 Opticaltrem.C  -  Optical tremolo effect

  Copyright (C) 2008-2010 Ryan Billing
  Author: Josep Andreu


 This program is free software; you can redistribute it and/or modify
 it under the terms of version 2 of the GNU General Public License
 as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License (version 2) for more details.

 You should have received a copy of the GNU General Public License
 (version2)  along with this program; if not, write to the Free Software
 Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

 */

#include <math.h>
#include "Opticaltrem.h"

Opticaltrem::Opticaltrem(double sample_rate, uint32_t intermediate_bufsize) :
    cSAMPLE_RATE(1.0f / sample_rate),
    PERIOD(intermediate_bufsize),
    Pdepth(127),
    Ppanning(64),
    Pinvert(),
    Ra(logf(1000000.0f)),       //  Cds cell dark resistance.
    Rb(300.0f),                 //  Cds cell full illumination
    R1(2700.0f),                //  tremolo circuit series resistance
    Rp(100000.0f),              //  Resistor in parallel with Cds cell
    b(exp(Ra / logf(Rb)) - CNST_E),
    dTC(0.03f),
    dRCl(dTC),
    dRCr(dTC),                  //  Right & left channel dynamic time constants
    minTC(logf(0.005f / dTC)),
    alphal(1.0f - cSAMPLE_RATE / (dRCl + cSAMPLE_RATE)),
    alphar(alphal),
    stepl(),
    stepr(),
    oldstepl(),
    oldstepr(),
    fdepth(1.0f),
    lstep(),
    rstep(),
    cperiod(),
    gl(),
    oldgl(),
    gr(),
    oldgr(),
    rpanning(1.0f),
    lpanning(1.0f),
    lfo(NULL),
    Fpre(NULL)
{
    /*  From original constructor
    Ra = 1000000.0f;    //  Cds cell dark resistance.
    Ra = logf(Ra);      //  this is done for clarity
    Rb = 300.0f;        //  Cds cell full illumination
    Rp = 100000.0f;     //  Resistor in parallel with Cds cell
    b = exp(Ra / logf(Rb)) - CNST_E;
    */
    
    lfo = new EffectLFO(sample_rate);
}

Opticaltrem::~Opticaltrem()
{
    delete lfo;
}

void
Opticaltrem::cleanup()
{
}

#ifdef LV2_SUPPORT
void
Opticaltrem::lv2_update_params(uint32_t period)
{
    PERIOD = period;
    lfo->updateparams(period);
}
#endif // LV2

void
Opticaltrem::out(float *efxoutl, float *efxoutr)
{
    float lfol, lfor;
    lfo->effectlfoout(&lfol, &lfor);

    if (Pinvert)
    {
        lfol = lfol*fdepth;
        lfor = lfor*fdepth;
    }
    else
    {
        lfor = 1.0f - lfor*fdepth;
        lfol = 1.0f - lfol*fdepth;
    }

    if (lfol > 1.0f)
    {
        lfol = 1.0f;
    }
    else if (lfol < 0.0f)
    {
        lfol = 0.0f;
    }
    
    if (lfor > 1.0f)
    {
        lfor = 1.0f;
    }
    else if (lfor < 0.0f)
    {
        lfor = 0.0f;
    }

    lfor = powf(lfor, 1.9f);
    lfol = powf(lfol, 1.9f); //emulate lamp turn on/off characteristic

    //lfo interpolation
    float rdiff = (lfor - oldgr) / (float) PERIOD;
    float ldiff = (lfol - oldgl) / (float) PERIOD;
    gr = lfor;
    gl = lfol;
    oldgr = lfor;
    oldgl = lfol;

    for (unsigned int i = 0; i < PERIOD; i++)
    {
        //Left Cds
        stepl = gl * (1.0f - alphal) + alphal*oldstepl;
        oldstepl = stepl;
        dRCl = dTC * f_exp(stepl * minTC);
        alphal = 1.0f - cSAMPLE_RATE / (dRCl + cSAMPLE_RATE);
        float xl = CNST_E + stepl*b;
        float fxl = f_exp(Ra / logf(xl));
        
        if (Pinvert)
        {
            fxl = fxl * Rp / (fxl + Rp); //Parallel resistance
            fxl = fxl / (fxl + R1);
        }
        else
        {
            fxl = R1 / (fxl + R1);
        }

        //Right Cds
        stepr = gr * (1.0f - alphar) + alphar*oldstepr;
        oldstepr = stepr;
        dRCr = dTC * f_exp(stepr * minTC);
        alphar = 1.0f - cSAMPLE_RATE / (dRCr + cSAMPLE_RATE);
        float xr = CNST_E + stepr*b;
        float fxr = f_exp(Ra / logf(xr));
        
        if (Pinvert)
        {
            fxr = fxr * Rp / (fxr + Rp); //Parallel resistance
            fxr = fxr / (fxr + R1);
        }
        else
        {
            fxr = R1 / (fxr + R1);
        }

        //Modulate input signal
        efxoutl[i] = lpanning * fxl * efxoutl[i];
        efxoutr[i] = rpanning * fxr * efxoutr[i];

        gl += ldiff;
        gr += rdiff; //linear interpolation of LFO
    }
}

void
Opticaltrem::setpanning(int value)
{
    Ppanning = value;
    rpanning = ((float) Ppanning) / 64.0f;
    lpanning = 2.0f - rpanning;
    lpanning = 10.0f * powf(lpanning, 4);
    rpanning = 10.0f * powf(rpanning, 4);
    lpanning = 1.0f - 1.0f / (lpanning + 1.0f);
    rpanning = 1.0f - 1.0f / (rpanning + 1.0f);

    if (Pinvert)
    {
        rpanning *= 2.0f;
        lpanning *= 2.0f;
    }
    else
    {
        rpanning *= 1.3f;
        lpanning *= 1.3f;
    }
}

void
Opticaltrem::setpreset(int npreset)
{
    const int PRESET_SIZE = 7;
    const int NUM_PRESETS = 7;
    int pdata[MAX_PDATA_SIZE];
    int presets[NUM_PRESETS][PRESET_SIZE] = {
        //Fast
        {127, 260, 10, 0, 64, 64, 0},
        //trem2
        {45, 140, 10, 0, 64, 64, 0},
        //hard pan
        {127, 120, 10, 5, 0, 64, 0},
        //soft pan
        {45, 240, 10, 1, 16, 64, 0},
        //ramp down
        {65, 200, 0, 3, 32, 64, 0},
        //hard ramp
        {127, 480, 0, 3, 32, 64, 0},
        //Slow
        {64, 33, 0, 0, 80, 64, 0}

    };

    if (npreset > NUM_PRESETS - 1)
    {
        Fpre->ReadPreset(44, npreset - NUM_PRESETS + 1, pdata);
        
        for (int n = 0; n < PRESET_SIZE; n++)
            changepar(n, pdata[n]);
    }
    else
    {
        for (int n = 0; n < PRESET_SIZE; n++)
            changepar(n, presets[npreset][n]);
    }
}

void
Opticaltrem::changepar(int npar, int value)
{
    switch (npar)
    {

    case 0:
        Pdepth = value;
        fdepth = 0.5f + ((float) Pdepth) / 254.0f;
        break;
    case 1:
        lfo->Pfreq = value;
        lfo->updateparams(PERIOD);
        break;
    case 2:
        lfo->Prandomness = value;
        lfo->updateparams(PERIOD);
        break;
    case 3:
        lfo->PLFOtype = value;
        lfo->updateparams(PERIOD);
        break;
    case 4:
        lfo->Pstereo = value;
        lfo->updateparams(PERIOD);
        break;
    case 5: // pan
        Ppanning = value;
        setpanning(value);
        break;
    case 6: //Invert
        Pinvert = value;
        if (Pinvert)
        {
            R1 = 68000.0f;      //  tremolo circuit series resistance
            Ra = 500000.0f;     //  Cds cell dark resistance.
        }
        else
        {
            R1 = 2700.0f;       //  tremolo circuit series resistance
            Ra = 1000000.0f;    //  Cds cell dark resistance.
        }
        setpanning(Ppanning);

        Ra = logf(Ra);          //  this is done for clarity
        Rb = 300.0f;            //  Cds cell full illumination
        b = exp(Ra / logf(Rb)) - CNST_E;
        break;
    }
}

int
Opticaltrem::getpar(int npar)
{
    switch (npar)
    {
    case 0:
        return (Pdepth);
        break;
    case 1:
        return (lfo->Pfreq);
        break;
    case 2:
        return (lfo->Prandomness);
        break;
    case 3:
        return (lfo->PLFOtype);
        break;
    case 4:
        return (lfo->Pstereo);
        break;
    case 5:
        return (Ppanning); //pan
        break;
    case 6:
        return (Pinvert); //pan
        break;
    }
    return (0);
}


