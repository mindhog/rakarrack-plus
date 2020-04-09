// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef sequence_gui_h
#define sequence_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include <FL/Fl_Group.H>
#include "sliderW.h"
#include "../process.h"
#include "rakarrack.h"
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>

class SequenceGui : public Fl_Group {
public:
  SequenceGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *seq_activar;
private:
  inline void cb_seq_activar_i(RKR_Light_Button*, void*);
  static void cb_seq_activar(RKR_Light_Button*, void*);
public:
  Fl_Choice *seq_preset;
private:
  inline void cb_seq_preset_i(Fl_Choice*, void*);
  static void cb_seq_preset(Fl_Choice*, void*);
  static Fl_Menu_Item menu_seq_preset[];
public:
  SliderW *seq_WD;
private:
  inline void cb_seq_WD_i(SliderW*, void*);
  static void cb_seq_WD(SliderW*, void*);
public:
  SliderW *seq_1;
private:
  inline void cb_seq_1_i(SliderW*, void*);
  static void cb_seq_1(SliderW*, void*);
public:
  SliderW *seq_2;
private:
  inline void cb_seq_2_i(SliderW*, void*);
  static void cb_seq_2(SliderW*, void*);
public:
  SliderW *seq_3;
private:
  inline void cb_seq_3_i(SliderW*, void*);
  static void cb_seq_3(SliderW*, void*);
public:
  SliderW *seq_4;
private:
  inline void cb_seq_4_i(SliderW*, void*);
  static void cb_seq_4(SliderW*, void*);
public:
  SliderW *seq_5;
private:
  inline void cb_seq_5_i(SliderW*, void*);
  static void cb_seq_5(SliderW*, void*);
public:
  SliderW *seq_6;
private:
  inline void cb_seq_6_i(SliderW*, void*);
  static void cb_seq_6(SliderW*, void*);
public:
  SliderW *seq_7;
private:
  inline void cb_seq_7_i(SliderW*, void*);
  static void cb_seq_7(SliderW*, void*);
public:
  SliderW *seq_8;
private:
  inline void cb_seq_8_i(SliderW*, void*);
  static void cb_seq_8(SliderW*, void*);
public:
  SliderW *seq_tempo;
private:
  inline void cb_seq_tempo_i(SliderW*, void*);
  static void cb_seq_tempo(SliderW*, void*);
public:
  SliderW *seq_q;
private:
  inline void cb_seq_q_i(SliderW*, void*);
  static void cb_seq_q(SliderW*, void*);
public:
  SliderW *seq_stdf;
private:
  inline void cb_seq_stdf_i(SliderW*, void*);
  static void cb_seq_stdf(SliderW*, void*);
public:
  Fl_Check_Button *seq_amp;
private:
  inline void cb_seq_amp_i(Fl_Check_Button*, void*);
  static void cb_seq_amp(Fl_Check_Button*, void*);
public:
  Fl_Choice *seq_mode;
private:
  inline void cb_seq_mode_i(Fl_Choice*, void*);
  static void cb_seq_mode(Fl_Choice*, void*);
  static Fl_Menu_Item menu_seq_mode[];
public:
  Fl_Choice *seq_range;
private:
  inline void cb_seq_range_i(Fl_Choice*, void*);
  static void cb_seq_range(Fl_Choice*, void*);
  static Fl_Menu_Item menu_seq_range[];
};
#endif
