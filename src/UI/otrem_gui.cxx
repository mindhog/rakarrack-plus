// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include "otrem_gui.h"

void OtremGui::cb_otrem_activar_i(RKR_Light_Button* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(116);
 o->value(rkr->Opticaltrem_Bypass);
 return;
}
rkr->Opticaltrem_Bypass=(int)o->value();
if((int) o->value()==0)
rkr->efx_Opticaltrem->cleanup();
rgui->findpos(44,(int)o->value(),o);
}
void OtremGui::cb_otrem_activar(RKR_Light_Button* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_activar_i(o,v);
}

void OtremGui::cb_otrem_preset_i(Fl_Choice* o, void* v) {
  long long ud= (long long) v;
if((ud==0)||(ud==12044))rkr->efx_Opticaltrem->setpreset((int)o->value());
otrem_dpth->value(rkr->efx_Opticaltrem->getpar(0));
otrem_freq->value(rkr->efx_Opticaltrem->getpar(1));
otrem_rnd->value(rkr->efx_Opticaltrem->getpar(2));
otrem_lfotype->value(rkr->efx_Opticaltrem->getpar(3));
otrem_stdf->value(rkr->efx_Opticaltrem->getpar(4));
otrem_pan->value(rkr->efx_Opticaltrem->getpar(5)-64);
otrem_invert->value(rkr->efx_Opticaltrem->getpar(6));
}
void OtremGui::cb_otrem_preset(Fl_Choice* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_preset_i(o,v);
}

Fl_Menu_Item OtremGui::menu_otrem_preset[] = {
 {"Fast", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Trem 2", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Hard Pan", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Soft Pan", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Ramp Down", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Hard Ramp", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Slow", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {0,0,0,0,0,0,0,0,0}
};

void OtremGui::cb_otrem_dpth_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(381);
 return;
}
rkr->efx_Opticaltrem->changepar(0,(int)o->value());
}
void OtremGui::cb_otrem_dpth(SliderW* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_dpth_i(o,v);
}

void OtremGui::cb_otrem_freq_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(382);
 return;
}
rkr->efx_Opticaltrem->changepar(1,(int)o->value());
}
void OtremGui::cb_otrem_freq(SliderW* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_freq_i(o,v);
}

void OtremGui::cb_otrem_rnd_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(383);
 return;
}
rkr->efx_Opticaltrem->changepar(2,(int)o->value());
}
void OtremGui::cb_otrem_rnd(SliderW* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_rnd_i(o,v);
}

void OtremGui::cb_otrem_lfotype_i(Fl_Choice* o, void*) {
  rkr->efx_Opticaltrem->changepar(3,(int)o->value());
}
void OtremGui::cb_otrem_lfotype(Fl_Choice* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_lfotype_i(o,v);
}

void OtremGui::cb_otrem_stdf_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(384);
 return;
}
rkr->efx_Opticaltrem->changepar(4,(int)o->value());
}
void OtremGui::cb_otrem_stdf(SliderW* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_stdf_i(o,v);
}

void OtremGui::cb_otrem_pan_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(385);
 return;
}
rkr->efx_Opticaltrem->changepar(5,(int)(o->value()+64));
}
void OtremGui::cb_otrem_pan(SliderW* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_pan_i(o,v);
}

void OtremGui::cb_otrem_invert_i(Fl_Check_Button* o, void*) {
  rkr->efx_Opticaltrem->changepar(6,(int)o->value());
}
void OtremGui::cb_otrem_invert(Fl_Check_Button* o, void* v) {
  ((OtremGui*)(o->parent()))->cb_otrem_invert_i(o,v);
}
OtremGui::OtremGui(int X, int Y, int W, int H, const char *L)
  : Fl_Group(0, 0, W, H, L) {
this->box(FL_UP_BOX);
this->color(FL_FOREGROUND_COLOR);
this->selection_color(FL_FOREGROUND_COLOR);
this->user_data((void*)(1));
this->align(Fl_Align(96|FL_ALIGN_INSIDE));
{ otrem_activar = new RKR_Light_Button(5, 6, 34, 18, "On");
  otrem_activar->box(FL_UP_BOX);
  otrem_activar->shortcut(0x38);
  otrem_activar->color((Fl_Color)62);
  otrem_activar->selection_color((Fl_Color)1);
  otrem_activar->labeltype(FL_NORMAL_LABEL);
  otrem_activar->labelfont(0);
  otrem_activar->labelsize(10);
  otrem_activar->labelcolor(FL_FOREGROUND_COLOR);
  otrem_activar->callback((Fl_Callback*)cb_otrem_activar, (void*)(2));
  otrem_activar->align(Fl_Align(68|FL_ALIGN_INSIDE));
  otrem_activar->when(FL_WHEN_CHANGED);
} // RKR_Light_Button* otrem_activar
{ otrem_preset = new Fl_Choice(77, 6, 76, 18, "Preset");
  otrem_preset->down_box(FL_BORDER_BOX);
  otrem_preset->selection_color(FL_FOREGROUND_COLOR);
  otrem_preset->labelsize(10);
  otrem_preset->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_preset->textsize(10);
  otrem_preset->textcolor(FL_BACKGROUND2_COLOR);
  otrem_preset->callback((Fl_Callback*)cb_otrem_preset, (void*)(12044));
  otrem_preset->when(FL_WHEN_RELEASE_ALWAYS);
  otrem_preset->menu(menu_otrem_preset);
} // Fl_Choice* otrem_preset
{ otrem_dpth = new SliderW(56, 35, 100, 10, "Depth");
  otrem_dpth->type(5);
  otrem_dpth->box(FL_FLAT_BOX);
  otrem_dpth->color((Fl_Color)178);
  otrem_dpth->selection_color((Fl_Color)62);
  otrem_dpth->labeltype(FL_NORMAL_LABEL);
  otrem_dpth->labelfont(0);
  otrem_dpth->labelsize(10);
  otrem_dpth->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_dpth->maximum(127);
  otrem_dpth->step(1);
  otrem_dpth->textcolor(FL_BACKGROUND2_COLOR);
  otrem_dpth->callback((Fl_Callback*)cb_otrem_dpth);
  otrem_dpth->align(Fl_Align(FL_ALIGN_LEFT));
  otrem_dpth->when(FL_WHEN_CHANGED);
} // SliderW* otrem_dpth
{ otrem_freq = new SliderW(56, 55, 100, 10, "Tempo");
  otrem_freq->type(5);
  otrem_freq->box(FL_FLAT_BOX);
  otrem_freq->color((Fl_Color)178);
  otrem_freq->selection_color((Fl_Color)62);
  otrem_freq->labeltype(FL_NORMAL_LABEL);
  otrem_freq->labelfont(0);
  otrem_freq->labelsize(10);
  otrem_freq->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_freq->minimum(1);
  otrem_freq->maximum(600);
  otrem_freq->step(1);
  otrem_freq->textcolor(FL_BACKGROUND2_COLOR);
  otrem_freq->callback((Fl_Callback*)cb_otrem_freq);
  otrem_freq->align(Fl_Align(FL_ALIGN_LEFT));
  otrem_freq->when(FL_WHEN_CHANGED);
} // SliderW* otrem_freq
{ otrem_rnd = new SliderW(56, 75, 100, 10, "Random");
  otrem_rnd->type(5);
  otrem_rnd->box(FL_FLAT_BOX);
  otrem_rnd->color((Fl_Color)178);
  otrem_rnd->selection_color((Fl_Color)62);
  otrem_rnd->labeltype(FL_NORMAL_LABEL);
  otrem_rnd->labelfont(0);
  otrem_rnd->labelsize(10);
  otrem_rnd->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_rnd->maximum(127);
  otrem_rnd->step(1);
  otrem_rnd->textcolor(FL_BACKGROUND2_COLOR);
  otrem_rnd->callback((Fl_Callback*)cb_otrem_rnd);
  otrem_rnd->align(Fl_Align(FL_ALIGN_LEFT));
  otrem_rnd->when(FL_WHEN_CHANGED);
} // SliderW* otrem_rnd
{ Fl_Choice* o = otrem_lfotype = new Fl_Choice(78, 102, 72, 16, "LFO Type");
  otrem_lfotype->down_box(FL_BORDER_BOX);
  otrem_lfotype->selection_color(FL_FOREGROUND_COLOR);
  otrem_lfotype->labelsize(10);
  otrem_lfotype->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_lfotype->textsize(10);
  otrem_lfotype->textcolor(FL_BACKGROUND2_COLOR);
  otrem_lfotype->callback((Fl_Callback*)cb_otrem_lfotype);
  o->menu(m_lfo_menu->get_lfo_type());
} // Fl_Choice* otrem_lfotype
{ otrem_stdf = new SliderW(56, 129, 100, 10, "Stereo Df");
  otrem_stdf->tooltip("LFO L/R Delay");
  otrem_stdf->type(5);
  otrem_stdf->box(FL_FLAT_BOX);
  otrem_stdf->color((Fl_Color)178);
  otrem_stdf->selection_color((Fl_Color)62);
  otrem_stdf->labeltype(FL_NORMAL_LABEL);
  otrem_stdf->labelfont(0);
  otrem_stdf->labelsize(10);
  otrem_stdf->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_stdf->maximum(127);
  otrem_stdf->step(1);
  otrem_stdf->textcolor(FL_BACKGROUND2_COLOR);
  otrem_stdf->callback((Fl_Callback*)cb_otrem_stdf);
  otrem_stdf->align(Fl_Align(FL_ALIGN_LEFT));
  otrem_stdf->when(FL_WHEN_CHANGED);
} // SliderW* otrem_stdf
{ otrem_pan = new SliderW(56, 149, 100, 10, "Pan");
  otrem_pan->type(5);
  otrem_pan->box(FL_FLAT_BOX);
  otrem_pan->color((Fl_Color)178);
  otrem_pan->selection_color((Fl_Color)62);
  otrem_pan->labeltype(FL_NORMAL_LABEL);
  otrem_pan->labelfont(0);
  otrem_pan->labelsize(10);
  otrem_pan->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_pan->minimum(-64);
  otrem_pan->maximum(63);
  otrem_pan->step(1);
  otrem_pan->textcolor(FL_BACKGROUND2_COLOR);
  otrem_pan->callback((Fl_Callback*)cb_otrem_pan);
  otrem_pan->align(Fl_Align(FL_ALIGN_LEFT));
  otrem_pan->when(FL_WHEN_CHANGED);
} // SliderW* otrem_pan
{ otrem_invert = new Fl_Check_Button(49, 164, 73, 15, "Invert");
  otrem_invert->tooltip("If checked it behaves more like tube preamp trem. If unchecked it behaves lik\
e a stompbox Opto Trem");
  otrem_invert->down_box(FL_BORDER_BOX);
  otrem_invert->labelsize(10);
  otrem_invert->labelcolor(FL_BACKGROUND2_COLOR);
  otrem_invert->callback((Fl_Callback*)cb_otrem_invert, (void*)(2));
} // Fl_Check_Button* otrem_invert
position(X, Y);
end();
}
