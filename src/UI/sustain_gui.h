// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef sustain_gui_h
#define sustain_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include "RKR_Choice.h"
#include <FL/Fl_Group.H>
#include "RKR_Slider.h"
#include "../process.h"
#include "rakarrack.h"

class SustainGui : public Fl_Group {
public:
  SustainGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *sus_activar;
private:
  inline void cb_sus_activar_i(RKR_Light_Button*, void*);
  static void cb_sus_activar(RKR_Light_Button*, void*);
public:
  RKR_Choice *sus_preset;
private:
  inline void cb_sus_preset_i(RKR_Choice*, void*);
  static void cb_sus_preset(RKR_Choice*, void*);
  static Fl_Menu_Item menu_sus_preset[];
public:
  RKR_Slider *sus_gain;
private:
  inline void cb_sus_gain_i(RKR_Slider*, void*);
  static void cb_sus_gain(RKR_Slider*, void*);
public:
  RKR_Slider *sus_sus;
private:
  inline void cb_sus_sus_i(RKR_Slider*, void*);
  static void cb_sus_sus(RKR_Slider*, void*);
};
#endif
