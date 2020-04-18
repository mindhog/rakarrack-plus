// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef whawha_gui_h
#define whawha_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include "RKR_Check_Button.h"
#include "RKR_Choice.h"
#include <FL/Fl_Group.H>
#include "RKR_Slider.h"
#include "../process.h"
#include "rakarrack.h"
#include "common_gui_menu.h"

class WhawhaGui : public Fl_Group {
public:
  WhawhaGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *WhaWha_activar;
private:
  inline void cb_WhaWha_activar_i(RKR_Light_Button*, void*);
  static void cb_WhaWha_activar(RKR_Light_Button*, void*);
public:
  RKR_Choice *WhaWha_preset;
private:
  inline void cb_WhaWha_preset_i(RKR_Choice*, void*);
  static void cb_WhaWha_preset(RKR_Choice*, void*);
  static Fl_Menu_Item menu_WhaWha_preset[];
public:
  RKR_Slider *WhaWha_WD;
private:
  inline void cb_WhaWha_WD_i(RKR_Slider*, void*);
  static void cb_WhaWha_WD(RKR_Slider*, void*);
public:
  RKR_Slider *WhaWha_pan;
private:
  inline void cb_WhaWha_pan_i(RKR_Slider*, void*);
  static void cb_WhaWha_pan(RKR_Slider*, void*);
public:
  RKR_Slider *WhaWha_freq;
private:
  inline void cb_WhaWha_freq_i(RKR_Slider*, void*);
  static void cb_WhaWha_freq(RKR_Slider*, void*);
public:
  RKR_Slider *WhaWha_rnd;
private:
  inline void cb_WhaWha_rnd_i(RKR_Slider*, void*);
  static void cb_WhaWha_rnd(RKR_Slider*, void*);
public:
  RKR_Choice *WhaWha_lfotype;
private:
  inline void cb_WhaWha_lfotype_i(RKR_Choice*, void*);
  static void cb_WhaWha_lfotype(RKR_Choice*, void*);
public:
  RKR_Slider *WhaWha_stdf;
private:
  inline void cb_WhaWha_stdf_i(RKR_Slider*, void*);
  static void cb_WhaWha_stdf(RKR_Slider*, void*);
public:
  RKR_Slider *WhaWha_dpth;
private:
  inline void cb_WhaWha_dpth_i(RKR_Slider*, void*);
  static void cb_WhaWha_dpth(RKR_Slider*, void*);
public:
  RKR_Slider *WhaWha_ampsns;
private:
  inline void cb_WhaWha_ampsns_i(RKR_Slider*, void*);
  static void cb_WhaWha_ampsns(RKR_Slider*, void*);
public:
  RKR_Check_Button *WhaWha_ampsnsinv;
private:
  inline void cb_WhaWha_ampsnsinv_i(RKR_Check_Button*, void*);
  static void cb_WhaWha_ampsnsinv(RKR_Check_Button*, void*);
public:
  RKR_Choice *WhaWha_ftype;
private:
  inline void cb_WhaWha_ftype_i(RKR_Choice*, void*);
  static void cb_WhaWha_ftype(RKR_Choice*, void*);
  static Fl_Menu_Item menu_WhaWha_ftype[];
public:
  RKR_Slider *WhaWha_smooth;
private:
  inline void cb_WhaWha_smooth_i(RKR_Slider*, void*);
  static void cb_WhaWha_smooth(RKR_Slider*, void*);
  CommonGuiMenu *m_lfo_menu; 
};
#endif
