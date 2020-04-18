// generated by Fast Light User Interface Designer (fluid) version 1.0305

#include "dist_gui.h"

void DistGui::cb_dist_activar_i(RKR_Light_Button* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(116);
 o->value(rkr->Distorsion_Bypass);
 return;
}
rkr->Distorsion_Bypass=(int)o->value();
if((int) o->value()==0)
rkr->efx_Distorsion->cleanup();
rgui->findpos(2,(int)o->value(),o);
}
void DistGui::cb_dist_activar(RKR_Light_Button* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_activar_i(o,v);
}

void DistGui::cb_dist_preset_i(RKR_Choice* o, void* v) {
  long long ud= (long long) v;
if((ud==0)||(ud==12002)) rkr->efx_Distorsion->setpreset(0,(int)(o->value()+2));
dist_WD->value(Dry_Wet(rkr->efx_Distorsion->getpar(0)));
dist_pan->value(rkr->efx_Distorsion->getpar(1)-64);
dist_LRc->value(rkr->efx_Distorsion->getpar(2));
dist_drive->value(rkr->efx_Distorsion->getpar(3));
dist_level->value(rkr->efx_Distorsion->getpar(4));
dist_tipo->value(rkr->efx_Distorsion->getpar(5));
dist_neg->value(rkr->efx_Distorsion->getpar(6));
dist_lpf->value(rkr->efx_Distorsion->getpar(7));
dist_hpf->value(rkr->efx_Distorsion->getpar(8));
dist_st->value(rkr->efx_Distorsion->getpar(9));
dist_pf->value(rkr->efx_Distorsion->getpar(10));
dist_oct->value(rkr->efx_Distorsion->getpar(12));
}
void DistGui::cb_dist_preset(RKR_Choice* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_preset_i(o,v);
}

Fl_Menu_Item DistGui::menu_dist_preset[] = {
 {"Distorsion 1", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Distorsion 2", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Distorsion 3", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {"Guitar Amp", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 0, 10, 0},
 {0,0,0,0,0,0,0,0,0}
};

void DistGui::cb_dist_WD_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(30);
 return;
} 
rkr->efx_Distorsion->changepar(0,Dry_Wet((int)(o->value())));
}
void DistGui::cb_dist_WD(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_WD_i(o,v);
}

void DistGui::cb_dist_LRc_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(95);
 return;
} 
rkr->efx_Distorsion->changepar(2,(int)(o->value()));
}
void DistGui::cb_dist_LRc(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_LRc_i(o,v);
}

void DistGui::cb_dist_drive_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(69);
 return;
} 
rkr->efx_Distorsion->changepar(3,(int)o->value());
}
void DistGui::cb_dist_drive(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_drive_i(o,v);
}

void DistGui::cb_dist_level_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(71);
 return;
} 
rkr->efx_Distorsion->changepar(4,(int)o->value());
}
void DistGui::cb_dist_level(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_level_i(o,v);
}

void DistGui::cb_dist_tipo_i(RKR_Choice* o, void*) {
  rkr->efx_Distorsion->changepar(5,(int)o->value());
}
void DistGui::cb_dist_tipo(RKR_Choice* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_tipo_i(o,v);
}

void DistGui::cb_dist_neg_i(RKR_Check_Button* o, void*) {
  rkr->efx_Distorsion->changepar(6,(int)o->value());
}
void DistGui::cb_dist_neg(RKR_Check_Button* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_neg_i(o,v);
}

void DistGui::cb_dist_pf_i(RKR_Check_Button* o, void*) {
  rkr->efx_Distorsion->changepar(10,(int)o->value());
}
void DistGui::cb_dist_pf(RKR_Check_Button* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_pf_i(o,v);
}

void DistGui::cb_dist_st_i(RKR_Check_Button* o, void*) {
  rkr->efx_Distorsion->changepar(9,(int)o->value());
}
void DistGui::cb_dist_st(RKR_Check_Button* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_st_i(o,v);
}

void DistGui::cb_dist_pan_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(48);
 return;
} 
rkr->efx_Distorsion->changepar(1,(int)(o->value()+64));
}
void DistGui::cb_dist_pan(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_pan_i(o,v);
}

void DistGui::cb_dist_oct_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(9);
 return;
} 
rkr->efx_Distorsion->changepar(12,(int)o->value());
}
void DistGui::cb_dist_oct(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_oct_i(o,v);
}

void DistGui::cb_dist_lpf_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(86);
 return;
} 
rkr->efx_Distorsion->changepar(7,(int)o->value());
}
void DistGui::cb_dist_lpf(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_lpf_i(o,v);
}

void DistGui::cb_dist_hpf_i(RKR_Slider* o, void*) {
  if(Fl::event_button()==3)
{
 rgui->getMIDIControl(89);
 return;
} 
rkr->efx_Distorsion->changepar(8,(int)o->value());
}
void DistGui::cb_dist_hpf(RKR_Slider* o, void* v) {
  ((DistGui*)(o->parent()))->cb_dist_hpf_i(o,v);
}
DistGui::DistGui(int X, int Y, int W, int H, const char *L)
  : Fl_Group(0, 0, W, H, L) {
this->box(FL_UP_BOX);
this->color(FL_FOREGROUND_COLOR);
this->selection_color(FL_FOREGROUND_COLOR);
this->user_data((void*)(1));
this->align(Fl_Align(96|FL_ALIGN_INSIDE));
{ dist_activar = new RKR_Light_Button(5, 4, 34, 18, "On");
  dist_activar->box(FL_UP_BOX);
  dist_activar->shortcut(0x33);
  dist_activar->color((Fl_Color)62);
  dist_activar->selection_color((Fl_Color)1);
  dist_activar->labeltype(FL_NORMAL_LABEL);
  dist_activar->labelfont(0);
  dist_activar->labelsize(10);
  dist_activar->labelcolor(FL_FOREGROUND_COLOR);
  dist_activar->callback((Fl_Callback*)cb_dist_activar, (void*)(2));
  dist_activar->align(Fl_Align(68|FL_ALIGN_INSIDE));
  dist_activar->when(FL_WHEN_CHANGED);
} // RKR_Light_Button* dist_activar
{ dist_preset = new RKR_Choice(77, 4, 76, 18, "Preset");
  dist_preset->box(FL_FLAT_BOX);
  dist_preset->down_box(FL_BORDER_BOX);
  dist_preset->color(FL_BACKGROUND_COLOR);
  dist_preset->selection_color(FL_FOREGROUND_COLOR);
  dist_preset->labeltype(FL_NORMAL_LABEL);
  dist_preset->labelfont(0);
  dist_preset->labelsize(10);
  dist_preset->labelcolor(FL_BACKGROUND2_COLOR);
  dist_preset->textsize(10);
  dist_preset->textcolor(FL_BACKGROUND2_COLOR);
  dist_preset->callback((Fl_Callback*)cb_dist_preset, (void*)(12002));
  dist_preset->align(Fl_Align(FL_ALIGN_LEFT));
  dist_preset->when(FL_WHEN_RELEASE_ALWAYS);
  dist_preset->menu(menu_dist_preset);
} // RKR_Choice* dist_preset
{ dist_WD = new RKR_Slider(56, 35, 100, 10, "Dry/Wet");
  dist_WD->type(5);
  dist_WD->box(FL_FLAT_BOX);
  dist_WD->color((Fl_Color)178);
  dist_WD->selection_color((Fl_Color)62);
  dist_WD->labeltype(FL_NORMAL_LABEL);
  dist_WD->labelfont(0);
  dist_WD->labelsize(10);
  dist_WD->labelcolor(FL_BACKGROUND2_COLOR);
  dist_WD->maximum(127);
  dist_WD->step(1);
  dist_WD->textcolor(FL_BACKGROUND2_COLOR);
  dist_WD->callback((Fl_Callback*)cb_dist_WD);
  dist_WD->align(Fl_Align(FL_ALIGN_LEFT));
  dist_WD->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_WD
{ dist_LRc = new RKR_Slider(56, 48, 100, 10, "L/R Cross");
  dist_LRc->type(5);
  dist_LRc->box(FL_FLAT_BOX);
  dist_LRc->color((Fl_Color)178);
  dist_LRc->selection_color((Fl_Color)62);
  dist_LRc->labeltype(FL_NORMAL_LABEL);
  dist_LRc->labelfont(0);
  dist_LRc->labelsize(10);
  dist_LRc->labelcolor(FL_BACKGROUND2_COLOR);
  dist_LRc->maximum(127);
  dist_LRc->step(1);
  dist_LRc->textcolor(FL_BACKGROUND2_COLOR);
  dist_LRc->callback((Fl_Callback*)cb_dist_LRc);
  dist_LRc->align(Fl_Align(FL_ALIGN_LEFT));
  dist_LRc->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_LRc
{ dist_drive = new RKR_Slider(56, 61, 100, 10, "Drive");
  dist_drive->type(5);
  dist_drive->box(FL_FLAT_BOX);
  dist_drive->color((Fl_Color)178);
  dist_drive->selection_color((Fl_Color)62);
  dist_drive->labeltype(FL_NORMAL_LABEL);
  dist_drive->labelfont(0);
  dist_drive->labelsize(10);
  dist_drive->labelcolor(FL_BACKGROUND2_COLOR);
  dist_drive->maximum(127);
  dist_drive->step(1);
  dist_drive->textcolor(FL_BACKGROUND2_COLOR);
  dist_drive->callback((Fl_Callback*)cb_dist_drive);
  dist_drive->align(Fl_Align(FL_ALIGN_LEFT));
  dist_drive->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_drive
{ dist_level = new RKR_Slider(56, 75, 100, 10, "Level");
  dist_level->type(5);
  dist_level->box(FL_FLAT_BOX);
  dist_level->color((Fl_Color)178);
  dist_level->selection_color((Fl_Color)62);
  dist_level->labeltype(FL_NORMAL_LABEL);
  dist_level->labelfont(0);
  dist_level->labelsize(10);
  dist_level->labelcolor(FL_BACKGROUND2_COLOR);
  dist_level->maximum(127);
  dist_level->step(1);
  dist_level->textcolor(FL_BACKGROUND2_COLOR);
  dist_level->callback((Fl_Callback*)cb_dist_level);
  dist_level->align(Fl_Align(FL_ALIGN_LEFT));
  dist_level->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_level
{ RKR_Choice* o = dist_tipo = new RKR_Choice(34, 91, 70, 16, "Type");
  dist_tipo->box(FL_FLAT_BOX);
  dist_tipo->down_box(FL_BORDER_BOX);
  dist_tipo->color(FL_BACKGROUND_COLOR);
  dist_tipo->selection_color(FL_FOREGROUND_COLOR);
  dist_tipo->labeltype(FL_NORMAL_LABEL);
  dist_tipo->labelfont(0);
  dist_tipo->labelsize(10);
  dist_tipo->labelcolor(FL_BACKGROUND2_COLOR);
  dist_tipo->textsize(10);
  dist_tipo->textcolor(FL_BACKGROUND2_COLOR);
  dist_tipo->callback((Fl_Callback*)cb_dist_tipo, (void*)(12));
  dist_tipo->align(Fl_Align(FL_ALIGN_LEFT));
  dist_tipo->when(FL_WHEN_RELEASE);
  o->menu(m_dist_menu->get_distortion_type());
} // RKR_Choice* dist_tipo
{ dist_neg = new RKR_Check_Button(110, 92, 41, 15, "Neg.");
  dist_neg->box(FL_NO_BOX);
  dist_neg->down_box(FL_BORDER_BOX);
  dist_neg->color(FL_BACKGROUND_COLOR);
  dist_neg->selection_color(FL_FOREGROUND_COLOR);
  dist_neg->labeltype(FL_NORMAL_LABEL);
  dist_neg->labelfont(0);
  dist_neg->labelsize(10);
  dist_neg->labelcolor(FL_BACKGROUND2_COLOR);
  dist_neg->callback((Fl_Callback*)cb_dist_neg, (void*)(2));
  dist_neg->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
  dist_neg->when(FL_WHEN_RELEASE);
} // RKR_Check_Button* dist_neg
{ dist_pf = new RKR_Check_Button(9, 108, 67, 15, "Pre Filter");
  dist_pf->box(FL_NO_BOX);
  dist_pf->down_box(FL_BORDER_BOX);
  dist_pf->color(FL_BACKGROUND_COLOR);
  dist_pf->selection_color(FL_FOREGROUND_COLOR);
  dist_pf->labeltype(FL_NORMAL_LABEL);
  dist_pf->labelfont(0);
  dist_pf->labelsize(10);
  dist_pf->labelcolor(FL_BACKGROUND2_COLOR);
  dist_pf->callback((Fl_Callback*)cb_dist_pf, (void*)(2));
  dist_pf->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
  dist_pf->when(FL_WHEN_RELEASE);
} // RKR_Check_Button* dist_pf
{ dist_st = new RKR_Check_Button(74, 108, 57, 15, "Stereo");
  dist_st->box(FL_NO_BOX);
  dist_st->down_box(FL_BORDER_BOX);
  dist_st->color(FL_BACKGROUND_COLOR);
  dist_st->selection_color(FL_FOREGROUND_COLOR);
  dist_st->labeltype(FL_NORMAL_LABEL);
  dist_st->labelfont(0);
  dist_st->labelsize(10);
  dist_st->labelcolor(FL_BACKGROUND2_COLOR);
  dist_st->callback((Fl_Callback*)cb_dist_st, (void*)(2));
  dist_st->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
  dist_st->when(FL_WHEN_RELEASE);
} // RKR_Check_Button* dist_st
{ dist_pan = new RKR_Slider(56, 125, 100, 10, "Pan");
  dist_pan->type(5);
  dist_pan->box(FL_FLAT_BOX);
  dist_pan->color((Fl_Color)178);
  dist_pan->selection_color((Fl_Color)62);
  dist_pan->labeltype(FL_NORMAL_LABEL);
  dist_pan->labelfont(0);
  dist_pan->labelsize(10);
  dist_pan->labelcolor(FL_BACKGROUND2_COLOR);
  dist_pan->minimum(-64);
  dist_pan->maximum(63);
  dist_pan->step(1);
  dist_pan->textcolor(FL_BACKGROUND2_COLOR);
  dist_pan->callback((Fl_Callback*)cb_dist_pan);
  dist_pan->align(Fl_Align(FL_ALIGN_LEFT));
  dist_pan->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_pan
{ dist_oct = new RKR_Slider(56, 145, 100, 10, "Sub Octv");
  dist_oct->type(5);
  dist_oct->box(FL_FLAT_BOX);
  dist_oct->color((Fl_Color)178);
  dist_oct->selection_color((Fl_Color)62);
  dist_oct->labeltype(FL_NORMAL_LABEL);
  dist_oct->labelfont(0);
  dist_oct->labelsize(10);
  dist_oct->labelcolor(FL_BACKGROUND2_COLOR);
  dist_oct->maximum(127);
  dist_oct->step(1);
  dist_oct->textcolor(FL_BACKGROUND2_COLOR);
  dist_oct->callback((Fl_Callback*)cb_dist_oct);
  dist_oct->align(Fl_Align(FL_ALIGN_LEFT));
  dist_oct->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_oct
{ dist_lpf = new RKR_Slider(56, 157, 100, 10, "LPF");
  dist_lpf->type(5);
  dist_lpf->box(FL_FLAT_BOX);
  dist_lpf->color((Fl_Color)178);
  dist_lpf->selection_color((Fl_Color)62);
  dist_lpf->labeltype(FL_NORMAL_LABEL);
  dist_lpf->labelfont(0);
  dist_lpf->labelsize(10);
  dist_lpf->labelcolor(FL_BACKGROUND2_COLOR);
  dist_lpf->minimum(20);
  dist_lpf->maximum(26000);
  dist_lpf->step(1);
  dist_lpf->value(20000);
  dist_lpf->textcolor(FL_BACKGROUND2_COLOR);
  dist_lpf->callback((Fl_Callback*)cb_dist_lpf);
  dist_lpf->align(Fl_Align(FL_ALIGN_LEFT));
  dist_lpf->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_lpf
{ dist_hpf = new RKR_Slider(56, 169, 100, 10, "HPF");
  dist_hpf->type(5);
  dist_hpf->box(FL_FLAT_BOX);
  dist_hpf->color((Fl_Color)178);
  dist_hpf->selection_color((Fl_Color)62);
  dist_hpf->labeltype(FL_NORMAL_LABEL);
  dist_hpf->labelfont(0);
  dist_hpf->labelsize(10);
  dist_hpf->labelcolor(FL_BACKGROUND2_COLOR);
  dist_hpf->minimum(20);
  dist_hpf->maximum(20000);
  dist_hpf->step(1);
  dist_hpf->value(20);
  dist_hpf->textcolor(FL_BACKGROUND2_COLOR);
  dist_hpf->callback((Fl_Callback*)cb_dist_hpf);
  dist_hpf->align(Fl_Align(FL_ALIGN_LEFT));
  dist_hpf->when(FL_WHEN_CHANGED);
} // RKR_Slider* dist_hpf
position(X, Y);
end();
}
