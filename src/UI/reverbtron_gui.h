// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef reverbtron_gui_h
#define reverbtron_gui_h
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include "sliderW.h"
#include "../process.h"
#include "rakarrack.h"
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Button.H>

class RevtronGui : public Fl_Group {
public:
  RevtronGui(int X, int Y, int W, int H, const char *L = 0);
  Fl_Light_Button *revtron_activar;
private:
  inline void cb_revtron_activar_i(Fl_Light_Button*, void*);
  static void cb_revtron_activar(Fl_Light_Button*, void*);
public:
  Fl_Choice *revtron_preset;
private:
  inline void cb_revtron_preset_i(Fl_Choice*, void*);
  static void cb_revtron_preset(Fl_Choice*, void*);
  static Fl_Menu_Item menu_revtron_preset[];
public:
  SliderW *revtron_WD;
private:
  inline void cb_revtron_WD_i(SliderW*, void*);
  static void cb_revtron_WD(SliderW*, void*);
public:
  SliderW *revtron_pan;
private:
  inline void cb_revtron_pan_i(SliderW*, void*);
  static void cb_revtron_pan(SliderW*, void*);
public:
  SliderW *revtron_level;
private:
  inline void cb_revtron_level_i(SliderW*, void*);
  static void cb_revtron_level(SliderW*, void*);
public:
  SliderW *revtron_damp;
private:
  inline void cb_revtron_damp_i(SliderW*, void*);
  static void cb_revtron_damp(SliderW*, void*);
public:
  SliderW *revtron_fb;
private:
  inline void cb_revtron_fb_i(SliderW*, void*);
  static void cb_revtron_fb(SliderW*, void*);
public:
  SliderW *revtron_length;
private:
  inline void cb_revtron_length_i(SliderW*, void*);
  static void cb_revtron_length(SliderW*, void*);
public:
  SliderW *revtron_strech;
private:
  inline void cb_revtron_strech_i(SliderW*, void*);
  static void cb_revtron_strech(SliderW*, void*);
public:
  SliderW *revtron_idelay;
private:
  inline void cb_revtron_idelay_i(SliderW*, void*);
  static void cb_revtron_idelay(SliderW*, void*);
public:
  SliderW *revtron_fade;
private:
  inline void cb_revtron_fade_i(SliderW*, void*);
  static void cb_revtron_fade(SliderW*, void*);
public:
  SliderW *revtron_HPF;
private:
  inline void cb_revtron_HPF_i(SliderW*, void*);
  static void cb_revtron_HPF(SliderW*, void*);
public:
  SliderW *revtron_LPF;
private:
  inline void cb_revtron_LPF_i(SliderW*, void*);
  static void cb_revtron_LPF(SliderW*, void*);
public:
  Fl_Check_Button *revtron_rv;
private:
  inline void cb_revtron_rv_i(Fl_Check_Button*, void*);
  static void cb_revtron_rv(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *revtron_es;
private:
  inline void cb_revtron_es_i(Fl_Check_Button*, void*);
  static void cb_revtron_es(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *revtron_safe;
private:
  inline void cb_revtron_safe_i(Fl_Check_Button*, void*);
  static void cb_revtron_safe(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *revtron_user;
private:
  inline void cb_revtron_user_i(Fl_Check_Button*, void*);
  static void cb_revtron_user(Fl_Check_Button*, void*);
public:
  Fl_Button *B_rvb;
private:
  inline void cb_B_rvb_i(Fl_Button*, void*);
  static void cb_B_rvb(Fl_Button*, void*);
public:
  Fl_Choice *revtron_fnum;
private:
  inline void cb_revtron_fnum_i(Fl_Choice*, void*);
  static void cb_revtron_fnum(Fl_Choice*, void*);
  static Fl_Menu_Item menu_revtron_fnum[];
};
#endif
