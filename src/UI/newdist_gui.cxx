// generated by Fast Light User Interface Designer (fluid) version 1.0305

#include "newdist_gui.h"

void NewdistGui::cb_newdist_activar_i(Fl_Light_Button* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(116);
 o->value(rkr->NewDist_Bypass);
 return;
}
rkr->NewDist_Bypass=(int)o->value();
if((int) o->value()==0)
rkr->efx_NewDist->cleanup();
rgui->findpos(17,(int)o->value(),o);
}
void NewdistGui::cb_newdist_activar(Fl_Light_Button* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_activar_i(o,v);
}

void NewdistGui::cb_newdist_preset_i(Fl_Choice* o, void* v) {
  long long ud= (long long) v;
if((ud==0)||(ud==12017))rkr->efx_NewDist->setpreset((int) o->value());
newdist_WD->value(rkr->efx_NewDist->getpar(0));
newdist_LRc->value(rkr->efx_NewDist->getpar(2)-64);
newdist_drive->value(rkr->efx_NewDist->getpar(3));
newdist_level->value(rkr->efx_NewDist->getpar(4));
newdist_tipo->value(rkr->efx_NewDist->getpar(5));
newdist_neg->value(rkr->efx_NewDist->getpar(6));
newdist_st->value(rkr->efx_NewDist->getpar(9));
newdist_oct->value(rkr->efx_NewDist->getpar(11));
newdist_pan->value(rkr->efx_NewDist->getpar(1)-64);
newdist_pf->value(rkr->efx_NewDist->getpar(10));
newdist_lpf->value(rkr->efx_NewDist->getpar(7));
newdist_hpf->value(rkr->efx_NewDist->getpar(8));
}
void NewdistGui::cb_newdist_preset(Fl_Choice* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_preset_i(o,v);
}

Fl_Menu_Item NewdistGui::menu_newdist_preset[] = {
 {"New Dist 1", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"New Dist 2", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"New Dist 3", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {0,0,0,0,0,0,0,0,0}
};

void NewdistGui::cb_newdist_WD_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(125);
 return;
} 
rkr->efx_NewDist->changepar(0,(int)(o->value()));
}
void NewdistGui::cb_newdist_WD(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_WD_i(o,v);
}

void NewdistGui::cb_newdist_LRc_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(127);
 return;
} 
rkr->efx_NewDist->changepar(2,(int)(o->value()+64));
}
void NewdistGui::cb_newdist_LRc(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_LRc_i(o,v);
}

void NewdistGui::cb_newdist_drive_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(2);
 return;
} 
rkr->efx_NewDist->changepar(3,(int)o->value());
}
void NewdistGui::cb_newdist_drive(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_drive_i(o,v);
}

void NewdistGui::cb_newdist_level_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(3);
 return;
} 
rkr->efx_NewDist->changepar(4,(int)o->value());
}
void NewdistGui::cb_newdist_level(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_level_i(o,v);
}

void NewdistGui::cb_newdist_tipo_i(Fl_Choice* o, void*) {
  rkr->efx_NewDist->changepar(5,(int)o->value());
}
void NewdistGui::cb_newdist_tipo(Fl_Choice* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_tipo_i(o,v);
}

void NewdistGui::cb_newdist_neg_i(Fl_Check_Button* o, void*) {
  rkr->efx_NewDist->changepar(6,(int)o->value());
}
void NewdistGui::cb_newdist_neg(Fl_Check_Button* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_neg_i(o,v);
}

void NewdistGui::cb_newdist_st_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(6);
 return;
} 
rkr->efx_NewDist->changepar(9,(int)o->value());
}
void NewdistGui::cb_newdist_st(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_st_i(o,v);
}

void NewdistGui::cb_newdist_oct_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(8);
 return;
} 
rkr->efx_NewDist->changepar(11,(int)o->value());
}
void NewdistGui::cb_newdist_oct(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_oct_i(o,v);
}

void NewdistGui::cb_newdist_pan_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(126);
 return;
} 
rkr->efx_NewDist->changepar(1,(int)(o->value()+64));
}
void NewdistGui::cb_newdist_pan(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_pan_i(o,v);
}

void NewdistGui::cb_newdist_pf_i(Fl_Check_Button* o, void*) {
  rkr->efx_NewDist->changepar(10,(int)o->value());
}
void NewdistGui::cb_newdist_pf(Fl_Check_Button* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_pf_i(o,v);
}

void NewdistGui::cb_newdist_lpf_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(4);
 return;
} 
rkr->efx_NewDist->changepar(7,(int)o->value());
}
void NewdistGui::cb_newdist_lpf(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_lpf_i(o,v);
}

void NewdistGui::cb_newdist_hpf_i(SliderW* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(5);
 return;
} 
rkr->efx_NewDist->changepar(8,(int)o->value());
}
void NewdistGui::cb_newdist_hpf(SliderW* o, void* v) {
  ((NewdistGui*)(o->parent()))->cb_newdist_hpf_i(o,v);
}
NewdistGui::NewdistGui(int X, int Y, int W, int H, const char *L)
  : Fl_Group(0, 0, W, H, L) {
this->box(FL_UP_BOX);
this->color(FL_FOREGROUND_COLOR);
this->selection_color(FL_FOREGROUND_COLOR);
this->user_data((void*)(1));
this->align(Fl_Align(96|FL_ALIGN_INSIDE));
{ newdist_activar = new Fl_Light_Button(5, 4, 34, 18, "On");
  newdist_activar->shortcut(0x33);
  newdist_activar->color((Fl_Color)62);
  newdist_activar->selection_color((Fl_Color)1);
  newdist_activar->labelsize(10);
  newdist_activar->callback((Fl_Callback*)cb_newdist_activar, (void*)(2));
  newdist_activar->align(Fl_Align(68|FL_ALIGN_INSIDE));
  newdist_activar->when(FL_WHEN_CHANGED);
} // Fl_Light_Button* newdist_activar
{ newdist_preset = new Fl_Choice(77, 4, 76, 18, "Preset");
  newdist_preset->down_box(FL_BORDER_BOX);
  newdist_preset->selection_color(FL_FOREGROUND_COLOR);
  newdist_preset->labelsize(10);
  newdist_preset->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_preset->textsize(10);
  newdist_preset->textcolor(FL_BACKGROUND2_COLOR);
  newdist_preset->callback((Fl_Callback*)cb_newdist_preset, (void*)(12017));
  newdist_preset->when(FL_WHEN_RELEASE_ALWAYS);
  newdist_preset->menu(menu_newdist_preset);
} // Fl_Choice* newdist_preset
{ newdist_WD = new SliderW(52, 28, 100, 10, "Wet/Dry");
  newdist_WD->type(5);
  newdist_WD->box(FL_FLAT_BOX);
  newdist_WD->color((Fl_Color)178);
  newdist_WD->selection_color((Fl_Color)62);
  newdist_WD->labeltype(FL_NORMAL_LABEL);
  newdist_WD->labelfont(0);
  newdist_WD->labelsize(10);
  newdist_WD->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_WD->maximum(127);
  newdist_WD->step(1);
  newdist_WD->textcolor(FL_BACKGROUND2_COLOR);
  newdist_WD->callback((Fl_Callback*)cb_newdist_WD);
  newdist_WD->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_WD->when(FL_WHEN_CHANGED);
} // SliderW* newdist_WD
{ newdist_LRc = new SliderW(52, 42, 100, 10, "L/R.Cr");
  newdist_LRc->type(5);
  newdist_LRc->box(FL_FLAT_BOX);
  newdist_LRc->color((Fl_Color)178);
  newdist_LRc->selection_color((Fl_Color)62);
  newdist_LRc->labeltype(FL_NORMAL_LABEL);
  newdist_LRc->labelfont(0);
  newdist_LRc->labelsize(10);
  newdist_LRc->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_LRc->minimum(-64);
  newdist_LRc->maximum(63);
  newdist_LRc->step(1);
  newdist_LRc->textcolor(FL_BACKGROUND2_COLOR);
  newdist_LRc->callback((Fl_Callback*)cb_newdist_LRc);
  newdist_LRc->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_LRc->when(FL_WHEN_CHANGED);
} // SliderW* newdist_LRc
{ newdist_drive = new SliderW(52, 56, 100, 10, "Drive");
  newdist_drive->type(5);
  newdist_drive->box(FL_FLAT_BOX);
  newdist_drive->color((Fl_Color)178);
  newdist_drive->selection_color((Fl_Color)62);
  newdist_drive->labeltype(FL_NORMAL_LABEL);
  newdist_drive->labelfont(0);
  newdist_drive->labelsize(10);
  newdist_drive->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_drive->minimum(1);
  newdist_drive->maximum(127);
  newdist_drive->step(1);
  newdist_drive->value(1);
  newdist_drive->textcolor(FL_BACKGROUND2_COLOR);
  newdist_drive->callback((Fl_Callback*)cb_newdist_drive);
  newdist_drive->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_drive->when(FL_WHEN_CHANGED);
} // SliderW* newdist_drive
{ newdist_level = new SliderW(52, 70, 100, 10, "Level");
  newdist_level->type(5);
  newdist_level->box(FL_FLAT_BOX);
  newdist_level->color((Fl_Color)178);
  newdist_level->selection_color((Fl_Color)62);
  newdist_level->labeltype(FL_NORMAL_LABEL);
  newdist_level->labelfont(0);
  newdist_level->labelsize(10);
  newdist_level->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_level->maximum(127);
  newdist_level->step(1);
  newdist_level->textcolor(FL_BACKGROUND2_COLOR);
  newdist_level->callback((Fl_Callback*)cb_newdist_level);
  newdist_level->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_level->when(FL_WHEN_CHANGED);
} // SliderW* newdist_level
{ Fl_Choice* o = newdist_tipo = new Fl_Choice(34, 84, 70, 16, "Type");
  newdist_tipo->down_box(FL_BORDER_BOX);
  newdist_tipo->selection_color(FL_FOREGROUND_COLOR);
  newdist_tipo->labelsize(10);
  newdist_tipo->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_tipo->textsize(10);
  newdist_tipo->textcolor(FL_BACKGROUND2_COLOR);
  newdist_tipo->callback((Fl_Callback*)cb_newdist_tipo);
  o->menu(m_dist_menu->get_distortion_type());
} // Fl_Choice* newdist_tipo
{ newdist_neg = new Fl_Check_Button(110, 84, 42, 15, "Neg.");
  newdist_neg->down_box(FL_BORDER_BOX);
  newdist_neg->labelsize(10);
  newdist_neg->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_neg->callback((Fl_Callback*)cb_newdist_neg, (void*)(2));
} // Fl_Check_Button* newdist_neg
{ newdist_st = new SliderW(52, 106, 100, 10, "Color");
  newdist_st->type(5);
  newdist_st->box(FL_FLAT_BOX);
  newdist_st->color((Fl_Color)178);
  newdist_st->selection_color((Fl_Color)62);
  newdist_st->labeltype(FL_NORMAL_LABEL);
  newdist_st->labelfont(0);
  newdist_st->labelsize(10);
  newdist_st->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_st->maximum(127);
  newdist_st->step(1);
  newdist_st->textcolor(FL_BACKGROUND2_COLOR);
  newdist_st->callback((Fl_Callback*)cb_newdist_st);
  newdist_st->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_st->when(FL_WHEN_CHANGED);
} // SliderW* newdist_st
{ newdist_oct = new SliderW(52, 120, 100, 10, "Sub Octv");
  newdist_oct->type(5);
  newdist_oct->box(FL_FLAT_BOX);
  newdist_oct->color((Fl_Color)178);
  newdist_oct->selection_color((Fl_Color)62);
  newdist_oct->labeltype(FL_NORMAL_LABEL);
  newdist_oct->labelfont(0);
  newdist_oct->labelsize(10);
  newdist_oct->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_oct->maximum(127);
  newdist_oct->step(1);
  newdist_oct->textcolor(FL_BACKGROUND2_COLOR);
  newdist_oct->callback((Fl_Callback*)cb_newdist_oct);
  newdist_oct->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_oct->when(FL_WHEN_CHANGED);
} // SliderW* newdist_oct
{ newdist_pan = new SliderW(52, 134, 100, 10, "Pan");
  newdist_pan->type(5);
  newdist_pan->box(FL_FLAT_BOX);
  newdist_pan->color((Fl_Color)178);
  newdist_pan->selection_color((Fl_Color)62);
  newdist_pan->labeltype(FL_NORMAL_LABEL);
  newdist_pan->labelfont(0);
  newdist_pan->labelsize(10);
  newdist_pan->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_pan->minimum(-64);
  newdist_pan->maximum(63);
  newdist_pan->step(1);
  newdist_pan->textcolor(FL_BACKGROUND2_COLOR);
  newdist_pan->callback((Fl_Callback*)cb_newdist_pan);
  newdist_pan->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_pan->when(FL_WHEN_CHANGED);
} // SliderW* newdist_pan
{ newdist_pf = new Fl_Check_Button(50, 144, 66, 15, "Pre Filter");
  newdist_pf->down_box(FL_BORDER_BOX);
  newdist_pf->labelsize(10);
  newdist_pf->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_pf->callback((Fl_Callback*)cb_newdist_pf, (void*)(2));
} // Fl_Check_Button* newdist_pf
{ newdist_lpf = new SliderW(52, 159, 100, 10, "LPF");
  newdist_lpf->type(5);
  newdist_lpf->box(FL_FLAT_BOX);
  newdist_lpf->color((Fl_Color)178);
  newdist_lpf->selection_color((Fl_Color)62);
  newdist_lpf->labeltype(FL_NORMAL_LABEL);
  newdist_lpf->labelfont(0);
  newdist_lpf->labelsize(10);
  newdist_lpf->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_lpf->minimum(20);
  newdist_lpf->maximum(26000);
  newdist_lpf->step(1);
  newdist_lpf->value(20000);
  newdist_lpf->textcolor(FL_BACKGROUND2_COLOR);
  newdist_lpf->callback((Fl_Callback*)cb_newdist_lpf);
  newdist_lpf->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_lpf->when(FL_WHEN_CHANGED);
} // SliderW* newdist_lpf
{ newdist_hpf = new SliderW(52, 171, 100, 10, "HPF");
  newdist_hpf->type(5);
  newdist_hpf->box(FL_FLAT_BOX);
  newdist_hpf->color((Fl_Color)178);
  newdist_hpf->selection_color((Fl_Color)62);
  newdist_hpf->labeltype(FL_NORMAL_LABEL);
  newdist_hpf->labelfont(0);
  newdist_hpf->labelsize(10);
  newdist_hpf->labelcolor(FL_BACKGROUND2_COLOR);
  newdist_hpf->minimum(20);
  newdist_hpf->maximum(20000);
  newdist_hpf->step(1);
  newdist_hpf->value(20);
  newdist_hpf->textcolor(FL_BACKGROUND2_COLOR);
  newdist_hpf->callback((Fl_Callback*)cb_newdist_hpf);
  newdist_hpf->align(Fl_Align(FL_ALIGN_LEFT));
  newdist_hpf->when(FL_WHEN_CHANGED);
} // SliderW* newdist_hpf
position(X, Y);
end();
}
