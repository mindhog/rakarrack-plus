// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef ryanwah_gui_h
#define ryanwah_gui_h
#include <FL/Fl.H>
#include "RKR_Light_Button.h"
#include "RKR_Value_Input.h"
#include "RKR_Check_Button.h"
#include "RKR_Counter.h"
#include "RKR_Choice.h"
#include <FL/Fl_Group.H>
#include "RKR_Slider.h"
#include "../process.h"
#include "rakarrack.h"
#include "common_gui_menu.h"

class RyanwahGui : public Fl_Group {
public:
  RyanwahGui(int X, int Y, int W, int H, const char *L = 0);
  RKR_Light_Button *ryanwah_activar;
private:
  inline void cb_ryanwah_activar_i(RKR_Light_Button*, void*);
  static void cb_ryanwah_activar(RKR_Light_Button*, void*);
public:
  RKR_Choice *ryanwah_preset;
private:
  inline void cb_ryanwah_preset_i(RKR_Choice*, void*);
  static void cb_ryanwah_preset(RKR_Choice*, void*);
  static Fl_Menu_Item menu_ryanwah_preset[];
public:
  RKR_Slider *ryanwah_WD;
private:
  inline void cb_ryanwah_WD_i(RKR_Slider*, void*);
  static void cb_ryanwah_WD(RKR_Slider*, void*);
public:
  RKR_Check_Button *ryanwah_qm;
private:
  inline void cb_ryanwah_qm_i(RKR_Check_Button*, void*);
  static void cb_ryanwah_qm(RKR_Check_Button*, void*);
public:
  RKR_Slider *ryanwah_lp;
private:
  inline void cb_ryanwah_lp_i(RKR_Slider*, void*);
  static void cb_ryanwah_lp(RKR_Slider*, void*);
public:
  RKR_Check_Button *ryanwah_nat;
private:
  inline void cb_ryanwah_nat_i(RKR_Check_Button*, void*);
  static void cb_ryanwah_nat(RKR_Check_Button*, void*);
public:
  RKR_Slider *ryanwah_bp;
private:
  inline void cb_ryanwah_bp_i(RKR_Slider*, void*);
  static void cb_ryanwah_bp(RKR_Slider*, void*);
public:
  RKR_Check_Button *ryanwah_res;
private:
  inline void cb_ryanwah_res_i(RKR_Check_Button*, void*);
  static void cb_ryanwah_res(RKR_Check_Button*, void*);
public:
  RKR_Slider *ryanwah_hp;
private:
  inline void cb_ryanwah_hp_i(RKR_Slider*, void*);
  static void cb_ryanwah_hp(RKR_Slider*, void*);
public:
  RKR_Counter *svfilter_stages;
private:
  inline void cb_svfilter_stages_i(RKR_Counter*, void*);
  static void cb_svfilter_stages(RKR_Counter*, void*);
public:
  RKR_Choice *ryanwah_lfotype;
private:
  inline void cb_ryanwah_lfotype_i(RKR_Choice*, void*);
  static void cb_ryanwah_lfotype(RKR_Choice*, void*);
public:
  RKR_Slider *ryanwah_dpth;
private:
  inline void cb_ryanwah_dpth_i(RKR_Slider*, void*);
  static void cb_ryanwah_dpth(RKR_Slider*, void*);
public:
  RKR_Slider *ryanwah_freq;
private:
  inline void cb_ryanwah_freq_i(RKR_Slider*, void*);
  static void cb_ryanwah_freq(RKR_Slider*, void*);
public:
  RKR_Slider *ryanwah_q;
private:
  inline void cb_ryanwah_q_i(RKR_Slider*, void*);
  static void cb_ryanwah_q(RKR_Slider*, void*);
public:
  RKR_Slider *ryanwah_rng;
private:
  inline void cb_ryanwah_rng_i(RKR_Slider*, void*);
  static void cb_ryanwah_rng(RKR_Slider*, void*);
public:
  RKR_Slider *ryanwah_ampsnsinv;
private:
  inline void cb_ryanwah_ampsnsinv_i(RKR_Slider*, void*);
  static void cb_ryanwah_ampsnsinv(RKR_Slider*, void*);
public:
  RKR_Slider *ryanwah_ampsns;
private:
  inline void cb_ryanwah_ampsns_i(RKR_Slider*, void*);
  static void cb_ryanwah_ampsns(RKR_Slider*, void*);
public:
  RKR_Value_Input *ryanwah_smooth;
private:
  inline void cb_ryanwah_smooth_i(RKR_Value_Input*, void*);
  static void cb_ryanwah_smooth(RKR_Value_Input*, void*);
public:
  RKR_Value_Input *ryanwah_Rnd;
private:
  inline void cb_ryanwah_Rnd_i(RKR_Value_Input*, void*);
  static void cb_ryanwah_Rnd(RKR_Value_Input*, void*);
public:
  RKR_Value_Input *ryanwah_St;
private:
  inline void cb_ryanwah_St_i(RKR_Value_Input*, void*);
  static void cb_ryanwah_St(RKR_Value_Input*, void*);
public:
  RKR_Value_Input *ryanwah_minfreq;
private:
  inline void cb_ryanwah_minfreq_i(RKR_Value_Input*, void*);
  static void cb_ryanwah_minfreq(RKR_Value_Input*, void*);
  CommonGuiMenu *m_lfo_menu; 
};
#endif
