// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef newdist_gui_h
#define newdist_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include "RKR_Check_Button.h"
#include "RKR_Choice.h"
#include <FL/Fl_Group.H>
#include "RKR_Slider.h"
#include "../process.h"
#include "rakarrack.h"
#include "common_gui_menu.h"

class NewdistGui : public Fl_Group {
public:
  NewdistGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *newdist_activar;
private:
  inline void cb_newdist_activar_i(RKR_Light_Button*, void*);
  static void cb_newdist_activar(RKR_Light_Button*, void*);
public:
  RKR_Choice *newdist_preset;
private:
  inline void cb_newdist_preset_i(RKR_Choice*, void*);
  static void cb_newdist_preset(RKR_Choice*, void*);
  static Fl_Menu_Item menu_newdist_preset[];
public:
  RKR_Slider *newdist_WD;
private:
  inline void cb_newdist_WD_i(RKR_Slider*, void*);
  static void cb_newdist_WD(RKR_Slider*, void*);
public:
  RKR_Slider *newdist_LRc;
private:
  inline void cb_newdist_LRc_i(RKR_Slider*, void*);
  static void cb_newdist_LRc(RKR_Slider*, void*);
public:
  RKR_Slider *newdist_drive;
private:
  inline void cb_newdist_drive_i(RKR_Slider*, void*);
  static void cb_newdist_drive(RKR_Slider*, void*);
public:
  RKR_Slider *newdist_level;
private:
  inline void cb_newdist_level_i(RKR_Slider*, void*);
  static void cb_newdist_level(RKR_Slider*, void*);
public:
  RKR_Choice *newdist_tipo;
private:
  inline void cb_newdist_tipo_i(RKR_Choice*, void*);
  static void cb_newdist_tipo(RKR_Choice*, void*);
public:
  RKR_Check_Button *newdist_neg;
private:
  inline void cb_newdist_neg_i(RKR_Check_Button*, void*);
  static void cb_newdist_neg(RKR_Check_Button*, void*);
public:
  RKR_Slider *newdist_st;
private:
  inline void cb_newdist_st_i(RKR_Slider*, void*);
  static void cb_newdist_st(RKR_Slider*, void*);
public:
  RKR_Slider *newdist_oct;
private:
  inline void cb_newdist_oct_i(RKR_Slider*, void*);
  static void cb_newdist_oct(RKR_Slider*, void*);
public:
  RKR_Slider *newdist_pan;
private:
  inline void cb_newdist_pan_i(RKR_Slider*, void*);
  static void cb_newdist_pan(RKR_Slider*, void*);
public:
  RKR_Check_Button *newdist_pf;
private:
  inline void cb_newdist_pf_i(RKR_Check_Button*, void*);
  static void cb_newdist_pf(RKR_Check_Button*, void*);
public:
  RKR_Slider *newdist_lpf;
private:
  inline void cb_newdist_lpf_i(RKR_Slider*, void*);
  static void cb_newdist_lpf(RKR_Slider*, void*);
public:
  RKR_Slider *newdist_hpf;
private:
  inline void cb_newdist_hpf_i(RKR_Slider*, void*);
  static void cb_newdist_hpf(RKR_Slider*, void*);
  CommonGuiMenu *m_dist_menu; 
};
#endif
