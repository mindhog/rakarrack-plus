// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef exciter_gui_h
#define exciter_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include "RKR_Choice.h"
#include <FL/Fl_Group.H>
#include "RKR_Slider.h"
#include "../process.h"
#include "rakarrack.h"

class ExciterGui : public Fl_Group {
public:
  ExciterGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *exciter_activar;
private:
  inline void cb_exciter_activar_i(RKR_Light_Button*, void*);
  static void cb_exciter_activar(RKR_Light_Button*, void*);
public:
  RKR_Choice *exciter_preset;
private:
  inline void cb_exciter_preset_i(RKR_Choice*, void*);
  static void cb_exciter_preset(RKR_Choice*, void*);
  static Fl_Menu_Item menu_exciter_preset[];
public:
  RKR_Slider *ex_Gain;
private:
  inline void cb_ex_Gain_i(RKR_Slider*, void*);
  static void cb_ex_Gain(RKR_Slider*, void*);
public:
  RKR_Slider *ex_lfreq;
private:
  inline void cb_ex_lfreq_i(RKR_Slider*, void*);
  static void cb_ex_lfreq(RKR_Slider*, void*);
public:
  RKR_Slider *ex_hfreq;
private:
  inline void cb_ex_hfreq_i(RKR_Slider*, void*);
  static void cb_ex_hfreq(RKR_Slider*, void*);
public:
  RKR_Slider *ex_1;
private:
  inline void cb_ex_1_i(RKR_Slider*, void*);
  static void cb_ex_1(RKR_Slider*, void*);
public:
  RKR_Slider *ex_2;
private:
  inline void cb_ex_2_i(RKR_Slider*, void*);
  static void cb_ex_2(RKR_Slider*, void*);
public:
  RKR_Slider *ex_3;
private:
  inline void cb_ex_3_i(RKR_Slider*, void*);
  static void cb_ex_3(RKR_Slider*, void*);
public:
  RKR_Slider *ex_4;
private:
  inline void cb_ex_4_i(RKR_Slider*, void*);
  static void cb_ex_4(RKR_Slider*, void*);
public:
  RKR_Slider *ex_5;
private:
  inline void cb_ex_5_i(RKR_Slider*, void*);
  static void cb_ex_5(RKR_Slider*, void*);
public:
  RKR_Slider *ex_6;
private:
  inline void cb_ex_6_i(RKR_Slider*, void*);
  static void cb_ex_6(RKR_Slider*, void*);
public:
  RKR_Slider *ex_7;
private:
  inline void cb_ex_7_i(RKR_Slider*, void*);
  static void cb_ex_7(RKR_Slider*, void*);
public:
  RKR_Slider *ex_8;
private:
  inline void cb_ex_8_i(RKR_Slider*, void*);
  static void cb_ex_8(RKR_Slider*, void*);
public:
  RKR_Slider *ex_9;
private:
  inline void cb_ex_9_i(RKR_Slider*, void*);
  static void cb_ex_9(RKR_Slider*, void*);
public:
  RKR_Slider *ex_10;
private:
  inline void cb_ex_10_i(RKR_Slider*, void*);
  static void cb_ex_10(RKR_Slider*, void*);
};
#endif
