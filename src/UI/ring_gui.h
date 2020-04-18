// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef ring_gui_h
#define ring_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include "RKR_Check_Button.h"
#include "RKR_Choice.h"
#include <FL/Fl_Group.H>
#include "RKR_Slider.h"
#include "../process.h"
#include "rakarrack.h"

class RingGui : public Fl_Group {
public:
  RingGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *ring_activar;
private:
  inline void cb_ring_activar_i(RKR_Light_Button*, void*);
  static void cb_ring_activar(RKR_Light_Button*, void*);
public:
  RKR_Choice *ring_preset;
private:
  inline void cb_ring_preset_i(RKR_Choice*, void*);
  static void cb_ring_preset(RKR_Choice*, void*);
  static Fl_Menu_Item menu_ring_preset[];
public:
  RKR_Slider *ring_WD;
private:
  inline void cb_ring_WD_i(RKR_Slider*, void*);
  static void cb_ring_WD(RKR_Slider*, void*);
public:
  RKR_Slider *ring_LRc;
private:
  inline void cb_ring_LRc_i(RKR_Slider*, void*);
  static void cb_ring_LRc(RKR_Slider*, void*);
public:
  RKR_Slider *ring_input;
private:
  inline void cb_ring_input_i(RKR_Slider*, void*);
  static void cb_ring_input(RKR_Slider*, void*);
public:
  RKR_Slider *ring_level;
private:
  inline void cb_ring_level_i(RKR_Slider*, void*);
  static void cb_ring_level(RKR_Slider*, void*);
public:
  RKR_Slider *ring_pan;
private:
  inline void cb_ring_pan_i(RKR_Slider*, void*);
  static void cb_ring_pan(RKR_Slider*, void*);
public:
  RKR_Check_Button *ring_st;
private:
  inline void cb_ring_st_i(RKR_Check_Button*, void*);
  static void cb_ring_st(RKR_Check_Button*, void*);
public:
  RKR_Check_Button *ring_afreq;
private:
  inline void cb_ring_afreq_i(RKR_Check_Button*, void*);
  static void cb_ring_afreq(RKR_Check_Button*, void*);
public:
  RKR_Slider *ring_depth;
private:
  inline void cb_ring_depth_i(RKR_Slider*, void*);
  static void cb_ring_depth(RKR_Slider*, void*);
public:
  RKR_Slider *ring_freq;
private:
  inline void cb_ring_freq_i(RKR_Slider*, void*);
  static void cb_ring_freq(RKR_Slider*, void*);
public:
  RKR_Slider *ring_sin;
private:
  inline void cb_ring_sin_i(RKR_Slider*, void*);
  static void cb_ring_sin(RKR_Slider*, void*);
public:
  RKR_Slider *ring_tri;
private:
  inline void cb_ring_tri_i(RKR_Slider*, void*);
  static void cb_ring_tri(RKR_Slider*, void*);
public:
  RKR_Slider *ring_saw;
private:
  inline void cb_ring_saw_i(RKR_Slider*, void*);
  static void cb_ring_saw(RKR_Slider*, void*);
public:
  RKR_Slider *ring_squ;
private:
  inline void cb_ring_squ_i(RKR_Slider*, void*);
  static void cb_ring_squ(RKR_Slider*, void*);
};
#endif
