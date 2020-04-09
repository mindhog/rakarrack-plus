// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef stompbox_gui_h
#define stompbox_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include <FL/Fl_Group.H>
#include "sliderW.h"
#include "../process.h"
#include "rakarrack.h"
#include <FL/Fl_Choice.H>

class StompboxGui : public Fl_Group {
public:
  StompboxGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *stomp_activar;
private:
  inline void cb_stomp_activar_i(RKR_Light_Button*, void*);
  static void cb_stomp_activar(RKR_Light_Button*, void*);
public:
  Fl_Choice *stomp_preset;
private:
  inline void cb_stomp_preset_i(Fl_Choice*, void*);
  static void cb_stomp_preset(Fl_Choice*, void*);
  static Fl_Menu_Item menu_stomp_preset[];
public:
  SliderW *stomp_WD;
private:
  inline void cb_stomp_WD_i(SliderW*, void*);
  static void cb_stomp_WD(SliderW*, void*);
public:
  SliderW *stomp_gain;
private:
  inline void cb_stomp_gain_i(SliderW*, void*);
  static void cb_stomp_gain(SliderW*, void*);
public:
  SliderW *stomp_low;
private:
  inline void cb_stomp_low_i(SliderW*, void*);
  static void cb_stomp_low(SliderW*, void*);
public:
  SliderW *stomp_mid;
private:
  inline void cb_stomp_mid_i(SliderW*, void*);
  static void cb_stomp_mid(SliderW*, void*);
public:
  SliderW *stomp_high;
private:
  inline void cb_stomp_high_i(SliderW*, void*);
  static void cb_stomp_high(SliderW*, void*);
public:
  Fl_Choice *stomp_mode;
private:
  inline void cb_stomp_mode_i(Fl_Choice*, void*);
  static void cb_stomp_mode(Fl_Choice*, void*);
  static Fl_Menu_Item menu_stomp_mode[];
};
#endif
