// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef flanger_gui_h
#define flanger_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include "RKR_Check_Button.h"
#include "RKR_Choice.h"
#include <FL/Fl_Group.H>
#include "RKR_Slider.h"
#include "../process.h"
#include "rakarrack.h"
#include "common_gui_menu.h"

class FlangerGui : public Fl_Group {
public:
  FlangerGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *flanger_activar;
private:
  inline void cb_flanger_activar_i(RKR_Light_Button*, void*);
  static void cb_flanger_activar(RKR_Light_Button*, void*);
public:
  RKR_Choice *flanger_preset;
private:
  inline void cb_flanger_preset_i(RKR_Choice*, void*);
  static void cb_flanger_preset(RKR_Choice*, void*);
  static Fl_Menu_Item menu_flanger_preset[];
public:
  RKR_Slider *flanger_WD;
private:
  inline void cb_flanger_WD_i(RKR_Slider*, void*);
  static void cb_flanger_WD(RKR_Slider*, void*);
public:
  RKR_Slider *flanger_pan;
private:
  inline void cb_flanger_pan_i(RKR_Slider*, void*);
  static void cb_flanger_pan(RKR_Slider*, void*);
public:
  RKR_Slider *flanger_freq;
private:
  inline void cb_flanger_freq_i(RKR_Slider*, void*);
  static void cb_flanger_freq(RKR_Slider*, void*);
public:
  RKR_Slider *flanger_rnd;
private:
  inline void cb_flanger_rnd_i(RKR_Slider*, void*);
  static void cb_flanger_rnd(RKR_Slider*, void*);
public:
  RKR_Choice *flanger_lfotype;
private:
  inline void cb_flanger_lfotype_i(RKR_Choice*, void*);
  static void cb_flanger_lfotype(RKR_Choice*, void*);
public:
  RKR_Check_Button *flanger_subs;
private:
  inline void cb_flanger_subs_i(RKR_Check_Button*, void*);
  static void cb_flanger_subs(RKR_Check_Button*, void*);
public:
  RKR_Check_Button *flanger_awesome;
private:
  inline void cb_flanger_awesome_i(RKR_Check_Button*, void*);
  static void cb_flanger_awesome(RKR_Check_Button*, void*);
public:
  RKR_Slider *flanger_stdf;
private:
  inline void cb_flanger_stdf_i(RKR_Slider*, void*);
  static void cb_flanger_stdf(RKR_Slider*, void*);
public:
  RKR_Slider *flanger_dpth;
private:
  inline void cb_flanger_dpth_i(RKR_Slider*, void*);
  static void cb_flanger_dpth(RKR_Slider*, void*);
public:
  RKR_Slider *flanger_delay;
private:
  inline void cb_flanger_delay_i(RKR_Slider*, void*);
  static void cb_flanger_delay(RKR_Slider*, void*);
public:
  RKR_Slider *flanger_fb;
private:
  inline void cb_flanger_fb_i(RKR_Slider*, void*);
  static void cb_flanger_fb(RKR_Slider*, void*);
public:
  RKR_Slider *flanger_LR;
private:
  inline void cb_flanger_LR_i(RKR_Slider*, void*);
  static void cb_flanger_LR(RKR_Slider*, void*);
  CommonGuiMenu *m_lfo_menu; 
};
#endif
