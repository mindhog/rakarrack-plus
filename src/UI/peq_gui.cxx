// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include "peq_gui.h"

void PeqGui::cb_eqp_activar_i(RKR_Light_Button* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(116);
 o->value(rkr->EQ2_Bypass);
 return;
}
rkr->EQ2_Bypass=(int)o->value();
if((int) o->value()==0)
rkr->efx_EQ2->cleanup();
rgui->findpos(9,(int)o->value(),o);
}
void PeqGui::cb_eqp_activar(RKR_Light_Button* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_activar_i(o,v);
}

void PeqGui::cb_eqp_preset_i(Fl_Choice* o, void* v) {
  long long ud= (long long) v;
if((ud==0)||(ud==12009)) rkr->EQ2_setpreset((int)o->value());
eqp_LF->value(rkr->efx_EQ2->getpar(11));
eqp_LFg->value(rkr->efx_EQ2->getpar(12)-64);
eqp_LQ->value(rkr->efx_EQ2->getpar(13)-64);
eqp_MF->value(rkr->efx_EQ2->getpar(16));
eqp_MFg->value(rkr->efx_EQ2->getpar(17)-64);
eqp_MQ->value(rkr->efx_EQ2->getpar(18)-64);
eqp_HF->value(rkr->efx_EQ2->getpar(21));
eqp_HFg->value(rkr->efx_EQ2->getpar(22)-64);
eqp_HQ->value(rkr->efx_EQ2->getpar(23)-64);
eqp_Gain->value(rkr->efx_EQ2->getpar(0)-64);
}
void PeqGui::cb_eqp_preset(Fl_Choice* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_preset_i(o,v);
}

Fl_Menu_Item PeqGui::menu_eqp_preset[] = {
 {"Plain", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Pop", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Jazz", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {0,0,0,0,0,0,0,0,0}
};

void PeqGui::cb_eqp_Gain_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(148);
 return;
} 
rkr->efx_EQ2->changepar(0,(int)(o->value()+64));
}
void PeqGui::cb_eqp_Gain(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_Gain_i(o,v);
}

void PeqGui::cb_eqp_LF_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(149);
 return;
} 
rkr->efx_EQ2->changepar(11,(int)o->value());
}
void PeqGui::cb_eqp_LF(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_LF_i(o,v);
}

void PeqGui::cb_eqp_LFg_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(150);
 return;
} 
rkr->efx_EQ2->changepar(12,(int)(o->value()+64));
}
void PeqGui::cb_eqp_LFg(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_LFg_i(o,v);
}

void PeqGui::cb_eqp_LQ_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(151);
 return;
} 
rkr->efx_EQ2->changepar(13,(int)(o->value()+64));
}
void PeqGui::cb_eqp_LQ(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_LQ_i(o,v);
}

void PeqGui::cb_eqp_MF_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(152);
 return;
} 
rkr->efx_EQ2->changepar(5+11,(int)o->value());
}
void PeqGui::cb_eqp_MF(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_MF_i(o,v);
}

void PeqGui::cb_eqp_MFg_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(153);
 return;
} 
rkr->efx_EQ2->changepar(5+12,(int)(o->value()+64));
}
void PeqGui::cb_eqp_MFg(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_MFg_i(o,v);
}

void PeqGui::cb_eqp_MQ_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(154);
 return;
} 
rkr->efx_EQ2->changepar(5+13,(int)(o->value()+64));
}
void PeqGui::cb_eqp_MQ(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_MQ_i(o,v);
}

void PeqGui::cb_eqp_HF_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(155);
 return;
} 
rkr->efx_EQ2->changepar(10+11,(int)o->value());
}
void PeqGui::cb_eqp_HF(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_HF_i(o,v);
}

void PeqGui::cb_eqp_HFg_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(156);
 return;
} 
rkr->efx_EQ2->changepar(10+12,(int)(o->value()+64));
}
void PeqGui::cb_eqp_HFg(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_HFg_i(o,v);
}

void PeqGui::cb_eqp_HQ_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(157);
 return;
} 
rkr->efx_EQ2->changepar(10+13,(int)(o->value()+64));
}
void PeqGui::cb_eqp_HQ(SliderW* o, void* v) {
  ((PeqGui*)(o->parent()))->cb_eqp_HQ_i(o,v);
}
PeqGui::PeqGui(int X, int Y, int W, int H, const char *L)
  : Fl_Group(0, 0, W, H, L) {
this->box(FL_UP_BOX);
this->color(FL_FOREGROUND_COLOR);
this->selection_color(FL_FOREGROUND_COLOR);
this->user_data((void*)(1));
this->align(Fl_Align(96|FL_ALIGN_INSIDE));
{ eqp_activar = new RKR_Light_Button(5, 4, 34, 18, "On");
  eqp_activar->box(FL_UP_BOX);
  eqp_activar->shortcut(0x30);
  eqp_activar->color((Fl_Color)62);
  eqp_activar->selection_color((Fl_Color)1);
  eqp_activar->labeltype(FL_NORMAL_LABEL);
  eqp_activar->labelfont(0);
  eqp_activar->labelsize(10);
  eqp_activar->labelcolor(FL_FOREGROUND_COLOR);
  eqp_activar->callback((Fl_Callback*)cb_eqp_activar, (void*)(2));
  eqp_activar->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
  eqp_activar->when(FL_WHEN_CHANGED);
} // RKR_Light_Button* eqp_activar
{ eqp_preset = new Fl_Choice(77, 4, 76, 18, "Preset");
  eqp_preset->down_box(FL_BORDER_BOX);
  eqp_preset->selection_color(FL_FOREGROUND_COLOR);
  eqp_preset->labelsize(10);
  eqp_preset->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_preset->textsize(10);
  eqp_preset->textcolor(FL_BACKGROUND2_COLOR);
  eqp_preset->callback((Fl_Callback*)cb_eqp_preset, (void*)(12009));
  eqp_preset->when(FL_WHEN_RELEASE_ALWAYS);
  eqp_preset->menu(menu_eqp_preset);
} // Fl_Choice* eqp_preset
{ eqp_Gain = new SliderW(53, 26, 100, 10, "Gain");
  eqp_Gain->type(5);
  eqp_Gain->box(FL_FLAT_BOX);
  eqp_Gain->color((Fl_Color)178);
  eqp_Gain->selection_color((Fl_Color)62);
  eqp_Gain->labeltype(FL_NORMAL_LABEL);
  eqp_Gain->labelfont(0);
  eqp_Gain->labelsize(10);
  eqp_Gain->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_Gain->minimum(-64);
  eqp_Gain->maximum(63);
  eqp_Gain->step(1);
  eqp_Gain->textcolor(FL_BACKGROUND2_COLOR);
  eqp_Gain->callback((Fl_Callback*)cb_eqp_Gain);
  eqp_Gain->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_Gain->when(FL_WHEN_CHANGED);
} // SliderW* eqp_Gain
{ eqp_LF = new SliderW(53, 50, 100, 10, "Low F.");
  eqp_LF->tooltip("Low Frequency");
  eqp_LF->type(5);
  eqp_LF->box(FL_FLAT_BOX);
  eqp_LF->color((Fl_Color)178);
  eqp_LF->selection_color((Fl_Color)62);
  eqp_LF->labeltype(FL_NORMAL_LABEL);
  eqp_LF->labelfont(0);
  eqp_LF->labelsize(10);
  eqp_LF->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_LF->minimum(20);
  eqp_LF->maximum(1000);
  eqp_LF->step(1);
  eqp_LF->value(200);
  eqp_LF->textcolor(FL_BACKGROUND2_COLOR);
  eqp_LF->callback((Fl_Callback*)cb_eqp_LF);
  eqp_LF->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_LF->when(FL_WHEN_CHANGED);
} // SliderW* eqp_LF
{ eqp_LFg = new SliderW(53, 63, 100, 10, "Low G.");
  eqp_LFg->tooltip("Low Gain");
  eqp_LFg->type(5);
  eqp_LFg->box(FL_FLAT_BOX);
  eqp_LFg->color((Fl_Color)178);
  eqp_LFg->selection_color((Fl_Color)62);
  eqp_LFg->labeltype(FL_NORMAL_LABEL);
  eqp_LFg->labelfont(0);
  eqp_LFg->labelsize(10);
  eqp_LFg->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_LFg->minimum(-64);
  eqp_LFg->maximum(63);
  eqp_LFg->step(1);
  eqp_LFg->textcolor(FL_BACKGROUND2_COLOR);
  eqp_LFg->callback((Fl_Callback*)cb_eqp_LFg);
  eqp_LFg->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_LFg->when(FL_WHEN_CHANGED);
} // SliderW* eqp_LFg
{ eqp_LQ = new SliderW(53, 76, 100, 10, "Low Q.");
  eqp_LQ->tooltip("Low Width");
  eqp_LQ->type(5);
  eqp_LQ->box(FL_FLAT_BOX);
  eqp_LQ->color((Fl_Color)178);
  eqp_LQ->selection_color((Fl_Color)62);
  eqp_LQ->labeltype(FL_NORMAL_LABEL);
  eqp_LQ->labelfont(0);
  eqp_LQ->labelsize(10);
  eqp_LQ->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_LQ->minimum(-64);
  eqp_LQ->maximum(63);
  eqp_LQ->step(1);
  eqp_LQ->textcolor(FL_BACKGROUND2_COLOR);
  eqp_LQ->callback((Fl_Callback*)cb_eqp_LQ);
  eqp_LQ->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_LQ->when(FL_WHEN_CHANGED);
} // SliderW* eqp_LQ
{ eqp_MF = new SliderW(53, 98, 100, 10, "Mid F.");
  eqp_MF->tooltip("Mid Frequency");
  eqp_MF->type(5);
  eqp_MF->box(FL_FLAT_BOX);
  eqp_MF->color((Fl_Color)178);
  eqp_MF->selection_color((Fl_Color)62);
  eqp_MF->labeltype(FL_NORMAL_LABEL);
  eqp_MF->labelfont(0);
  eqp_MF->labelsize(10);
  eqp_MF->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_MF->minimum(800);
  eqp_MF->maximum(8000);
  eqp_MF->step(1);
  eqp_MF->value(800);
  eqp_MF->textcolor(FL_BACKGROUND2_COLOR);
  eqp_MF->callback((Fl_Callback*)cb_eqp_MF);
  eqp_MF->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_MF->when(FL_WHEN_CHANGED);
} // SliderW* eqp_MF
{ eqp_MFg = new SliderW(53, 110, 100, 10, "Mid G.");
  eqp_MFg->tooltip("Mid Gain");
  eqp_MFg->type(5);
  eqp_MFg->box(FL_FLAT_BOX);
  eqp_MFg->color((Fl_Color)178);
  eqp_MFg->selection_color((Fl_Color)62);
  eqp_MFg->labeltype(FL_NORMAL_LABEL);
  eqp_MFg->labelfont(0);
  eqp_MFg->labelsize(10);
  eqp_MFg->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_MFg->minimum(-64);
  eqp_MFg->maximum(63);
  eqp_MFg->step(1);
  eqp_MFg->textcolor(FL_BACKGROUND2_COLOR);
  eqp_MFg->callback((Fl_Callback*)cb_eqp_MFg);
  eqp_MFg->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_MFg->when(FL_WHEN_CHANGED);
} // SliderW* eqp_MFg
{ eqp_MQ = new SliderW(53, 122, 100, 10, "Mid Q.");
  eqp_MQ->tooltip("Mid Width");
  eqp_MQ->type(5);
  eqp_MQ->box(FL_FLAT_BOX);
  eqp_MQ->color((Fl_Color)178);
  eqp_MQ->selection_color((Fl_Color)62);
  eqp_MQ->labeltype(FL_NORMAL_LABEL);
  eqp_MQ->labelfont(0);
  eqp_MQ->labelsize(10);
  eqp_MQ->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_MQ->minimum(-64);
  eqp_MQ->maximum(63);
  eqp_MQ->step(1);
  eqp_MQ->textcolor(FL_BACKGROUND2_COLOR);
  eqp_MQ->callback((Fl_Callback*)cb_eqp_MQ);
  eqp_MQ->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_MQ->when(FL_WHEN_CHANGED);
} // SliderW* eqp_MQ
{ eqp_HF = new SliderW(53, 144, 100, 10, "High F.");
  eqp_HF->tooltip("High Frequency");
  eqp_HF->type(5);
  eqp_HF->box(FL_FLAT_BOX);
  eqp_HF->color((Fl_Color)178);
  eqp_HF->selection_color((Fl_Color)62);
  eqp_HF->labeltype(FL_NORMAL_LABEL);
  eqp_HF->labelfont(0);
  eqp_HF->labelsize(10);
  eqp_HF->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_HF->minimum(6000);
  eqp_HF->maximum(26000);
  eqp_HF->step(1);
  eqp_HF->value(12000);
  eqp_HF->textcolor(FL_BACKGROUND2_COLOR);
  eqp_HF->callback((Fl_Callback*)cb_eqp_HF);
  eqp_HF->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_HF->when(FL_WHEN_CHANGED);
} // SliderW* eqp_HF
{ eqp_HFg = new SliderW(53, 156, 100, 10, "High G.");
  eqp_HFg->tooltip("High Gain");
  eqp_HFg->type(5);
  eqp_HFg->box(FL_FLAT_BOX);
  eqp_HFg->color((Fl_Color)178);
  eqp_HFg->selection_color((Fl_Color)62);
  eqp_HFg->labeltype(FL_NORMAL_LABEL);
  eqp_HFg->labelfont(0);
  eqp_HFg->labelsize(10);
  eqp_HFg->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_HFg->minimum(-64);
  eqp_HFg->maximum(63);
  eqp_HFg->step(1);
  eqp_HFg->textcolor(FL_BACKGROUND2_COLOR);
  eqp_HFg->callback((Fl_Callback*)cb_eqp_HFg);
  eqp_HFg->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_HFg->when(FL_WHEN_CHANGED);
} // SliderW* eqp_HFg
{ eqp_HQ = new SliderW(53, 168, 100, 10, "High Q.");
  eqp_HQ->tooltip("High Width");
  eqp_HQ->type(5);
  eqp_HQ->box(FL_FLAT_BOX);
  eqp_HQ->color((Fl_Color)178);
  eqp_HQ->selection_color((Fl_Color)62);
  eqp_HQ->labeltype(FL_NORMAL_LABEL);
  eqp_HQ->labelfont(0);
  eqp_HQ->labelsize(10);
  eqp_HQ->labelcolor(FL_BACKGROUND2_COLOR);
  eqp_HQ->minimum(-64);
  eqp_HQ->maximum(63);
  eqp_HQ->step(1);
  eqp_HQ->textcolor(FL_BACKGROUND2_COLOR);
  eqp_HQ->callback((Fl_Callback*)cb_eqp_HQ);
  eqp_HQ->align(Fl_Align(FL_ALIGN_LEFT));
  eqp_HQ->when(FL_WHEN_CHANGED);
} // SliderW* eqp_HQ
position(X, Y);
end();
}
