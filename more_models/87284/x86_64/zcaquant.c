/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__caquant
#define _nrn_initial _nrn_initial__caquant
#define nrn_cur _nrn_cur__caquant
#define _nrn_current _nrn_current__caquant
#define nrn_jacob _nrn_jacob__caquant
#define nrn_state _nrn_state__caquant
#define _net_receive _net_receive__caquant 
#define findvx findvx__caquant 
#define findix findix__caquant 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define iinit _p[0]
#define imax _p[1]
#define timax _p[2]
#define ihalf _p[3]
#define t0i _p[4]
#define t1i _p[5]
#define hwi _p[6]
#define cinit _p[7]
#define cmax _p[8]
#define tcmax _p[9]
#define svr _p[10]
#define qapprox _p[11]
#define cmaxp _p[12]
#define vinit _p[13]
#define vmax _p[14]
#define tvmax _p[15]
#define vhalf _p[16]
#define t0v _p[17]
#define t1v _p[18]
#define hwv _p[19]
#define vxt _p[20]
#define ica _p[21]
#define findwhichi _p[22]
#define cai _p[23]
#define findwhichv _p[24]
#define v _p[25]
#define _g _p[26]
#define _ion_ica	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define area	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_findvx(void);
 static void _hoc_findix(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_caquant", _hoc_setdata,
 "findvx_caquant", _hoc_findvx,
 "findix_caquant", _hoc_findix,
 0, 0
};
 /* declare global and static user variables */
#define mode mode_caquant
 double mode = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "mode_caquant", "1",
 "iinit_caquant", "mA/cm2",
 "imax_caquant", "mA/cm2",
 "timax_caquant", "ms",
 "ihalf_caquant", "mA/cm2",
 "t0i_caquant", "ms",
 "t1i_caquant", "ms",
 "hwi_caquant", "ms",
 "cinit_caquant", "mM",
 "cmax_caquant", "mM",
 "tcmax_caquant", "ms",
 "svr_caquant", "/micron",
 "qapprox_caquant", "picocoulomb",
 "cmaxp_caquant", "mM",
 "vinit_caquant", "mV",
 "vmax_caquant", "mV",
 "tvmax_caquant", "ms",
 "vhalf_caquant", "mV",
 "t0v_caquant", "ms",
 "t1v_caquant", "ms",
 "hwv_caquant", "ms",
 "vxt_caquant", "ms mV",
 0,0
};
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "mode_caquant", &mode_caquant,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void _ba1() ;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"caquant",
 0,
 "iinit_caquant",
 "imax_caquant",
 "timax_caquant",
 "ihalf_caquant",
 "t0i_caquant",
 "t1i_caquant",
 "hwi_caquant",
 "cinit_caquant",
 "cmax_caquant",
 "tcmax_caquant",
 "svr_caquant",
 "qapprox_caquant",
 "cmaxp_caquant",
 "vinit_caquant",
 "vmax_caquant",
 "tvmax_caquant",
 "vhalf_caquant",
 "t0v_caquant",
 "t1v_caquant",
 "hwv_caquant",
 "vxt_caquant",
 0,
 0,
 0};
 extern Node* nrn_alloc_node_;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 27, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 27;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 	_ppvar[2]._pval = &nrn_alloc_node_->_area; /* diam */
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _zcaquant_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 27, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "area");
 	hoc_reg_ba(_mechtype, _ba1, 14);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 caquant /home/trundle/Projects/NST-variation/more_models/87284/zcaquant.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define F _nrnunit_F[_nrnunit_use_legacy_]
static double _nrnunit_F[2] = {0x1.78e555060882cp+16, 96485.3}; /* 96485.3321233100141 */
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int findvx(_threadargsproto_);
static int findix(_threadargsproto_);
 
static int  findix ( _threadargsproto_ ) {
   if ( findwhichi  == 0.0 ) {
     if ( ica < ihalf ) {
       t0i = t ;
       findwhichi = 1.0 ;
       }
     }
   else if ( findwhichi  == 1.0 ) {
     if ( ica > ihalf ) {
       t1i = t ;
       hwi = t1i - t0i ;
       findwhichi = 2.0 ;
       }
     }
    return 0; }
 
static void _hoc_findix(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 findix ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int  findvx ( _threadargsproto_ ) {
   if ( findwhichv  == 0.0 ) {
     if ( v > vhalf ) {
       t0v = t ;
       findwhichv = 1.0 ;
       }
     }
   else if ( findwhichv  == 1.0 ) {
     if ( v < vhalf ) {
       t1v = t ;
       hwv = t1v - t0v ;
       findwhichv = 2.0 ;
       }
     }
    return 0; }
 
static void _hoc_findvx(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 findvx ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 /* BEFORE STEP */
 static void _ba1(Node*_nd, double* _pp, Datum* _ppd, Datum* _thread, _NrnThread* _nt)  {
   double* _p; Datum* _ppvar; _p = _pp; _ppvar = _ppd;
  v = NODEV(_nd);
  ica = _ion_ica;
  cai = _ion_cai;
 if ( mode  == 1.0 ) {
     if ( ica < imax ) {
       imax = ica ;
       timax = t ;
       }
     if ( cai > cmax ) {
       cmax = cai ;
       tcmax = t ;
       }
     if ( v > vmax ) {
       vmax = v ;
       tvmax = t ;
       }
     }
   else if ( mode  == 2.0 ) {
     findix ( _threadargs_ ) ;
     qapprox = - ( 0.01 ) * area * ( imax - iinit ) * hwi ;
     cmaxp = cinit - ( 10000.0 ) * svr * ( imax - iinit ) * hwi / 2.0 / F ;
     findvx ( _threadargs_ ) ;
     vxt = ( vmax - vinit ) * hwv ;
     }
   }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
 {
   if ( mode  == 1.0 ) {
     iinit = ica ;
     imax = ica ;
     timax = t ;
     ihalf = ica ;
     t0i = - 1.0 ;
     t1i = - 1.0 ;
     hwi = - 1.0 ;
     cinit = cai ;
     cmax = cai ;
     tcmax = t ;
     vinit = v ;
     vmax = v ;
     tvmax = t ;
     vhalf = v ;
     t0v = - 1.0 ;
     t1v = - 1.0 ;
     hwv = - 1.0 ;
     }
   else if ( mode  == 2.0 ) {
     ihalf = ( iinit + imax ) / 2.0 ;
     findwhichi = 0.0 ;
     vhalf = ( vinit + vmax ) / 2.0 ;
     findwhichv = 0.0 ;
     }
   }

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ica = _ion_ica;
  cai = _ion_cai;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ica = _ion_ica;
  cai = _ion_cai;
 {
   }
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/trundle/Projects/NST-variation/more_models/87284/zcaquant.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "caquant.mod\n"
  "based on mhw.mod, which measures peak depol and calculates spike half width\n"
  "  from the times at which v crosses a (depolarized) threshold.\n"
  "\n"
  "caquant measures these:\n"
  "iinit   ica at t==0, in mA/cm2\n"
  "imax    most negative (i.e. largest inward) ica, in mA/cm2\n"
  "timax   time at which the most negative ica occurs\n"
  "hwi     half width of the first ica transient that occurs in a simulation\n"
  "          and has most negative value (i.e. dips below) < imax + irest\n"
  "cinit   cai at t==0\n"
  "cmax    largest cai\n"
  "tcmax   time at which the largest cai occurs\n"
  "\n"
  "caquant also calculates these values:\n"
  "qapprox = -area*(imax-iinit)*hwi\n"
  "        approximate \"extra\" charge that enters during the ica transient\n"
  "        (assumes waveform is more or less triangular)\n"
  "        (\"extra\" charge means the difference between the amount that enters \n"
  "        during the ica transient and the amount that would have entered \n"
  "        if the transient hadn't happened)\n"
  "cmaxp   predicted cmax calculated as cinit - svr*(imax-iinit)*hwi/2/FARADAY\n"
  "        where svr is a RANGE variable (a PARAMETER declared to be RANGE) \n"
  "        equal to the surface/volume ratio.  svr must be specified by the \n"
  "        user during setup, because it depends on the geometry assumed by \n"
  "        the accumulation mechanism that READs ica and WRITEs cai.\n"
  "\n"
  "caquant operates in two modes, which are controlled by the PARAMETER (a global)\n"
  "called mode.\n"
  "When mode is 1, caquant determines the following in the course of a simulation:\n"
  "iinit, imax, timax, cinit, cmax, and tcmax\n"
  "When mode is 2, it does the following in the course of a simulation:\n"
  "1.  uses the values of iinit and imax to set the threshold that it monitors \n"
  "    in order to determine hwi  \n"
  "2.  uses the values of hwi, iinit, and imax to calculate qapprox,\n"
  "and\n"
  "3.  uses the values of cinit, svr, imax, iinit, and hwi to calculate cmaxp.\n"
  "\n"
  "USAGE EXAMPLE\n"
  "\n"
  "/*\n"
  "Run two simulations, first time with parameter mode_caquant = 1\n"
  "and second time with mode_caquant = 2\n"
  "\n"
  "At end of first run,\n"
  "this  will equal  this\n"
  "iinit             ica at t==0, in mA/cm2\n"
  "imax              most negative (i.e. largest inward) ica, in mA/cm2\n"
  "timax             time at which the most negative ica occurs\n"
  "cinit             cai at t==0\n"
  "cmax              largest cai\n"
  "tcmax             time at which the largest cai occurs\n"
  "\n"
  "At end of second run,\n"
  "this  will equal  this\n"
  "t0i and t1i        the times at which ica crosses the \"threshold\" iinit+imax/2\n"
  "hwi              half width of the first ica transient\n"
  "qapprox          approximate extra charge that enters during the ica transient\n"
  "cmaxp            predicted cmax\n"
  "*/\n"
  "\n"
  "forall {\n"
  "  insert caquant\n"
  "  for (x, 0) svr_caquant(x) = some function that specifies the surface/volume ratio\n"
  "    of the current segment\n"
  "}\n"
  "mode_caquant = 1\n"
  "run()\n"
  "mode_mhw = 2\n"
  "run()\n"
  "\n"
  "hwi will be -1 if there is no max, or if simulation ends before ica crosses\n"
  "  the automatically-set threshold twice\n"
  "\n"
  "Be cautious when using with adaptive integration--if the integrator uses long dt, \n"
  "t0i or t1i may be missed by a wide margin.\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "  SUFFIX caquant\n"
  "  USEION ca READ ica, cai\n"
  "  : mode values--\n"
  "  : 1 measure imax, 2 calc ihalf and measure halfwidth\n"
  "  GLOBAL mode\n"
  "  RANGE iinit, imax, timax\n"
  "  RANGE ihalf, t0i, t1i, hwi\n"
  "  RANGE cinit, cmax, tcmax\n"
  "\n"
  "  RANGE svr : local surface/volume ratio\n"
  "  RANGE qapprox, cmaxp\n"
  "\n"
  "  RANGE vinit, vmax, tvmax\n"
  "  RANGE vhalf, t0v, t1v, hwv\n"
  "  RANGE vxt\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "  (mA) = (milliamp)\n"
  "  (mV) = (millivolt)\n"
  "  (mM) = (milli/liter)\n"
  "  F = (faraday) (coulombs)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "  : mode values--\n"
  "  : 1 measure imax, 2 calc ihalf and measure halfwidth\n"
  "  mode = 1 (1) : default is measure imax\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  ica (mA/cm2)\n"
  "  iinit (mA/cm2) : initial ica\n"
  "  imax (mA/cm2)  : max ica during previous run\n"
  "  timax (ms)  : time at which imax occurred\n"
  "  ihalf (mA/cm2) : (iinit + imax)/2\n"
  "  t0i (ms)    : time in rising phase of cai transient when cai first < ihalf\n"
  "  t1i (ms)    : time in falling phase of cai when cai first > ihalf\n"
  "  hwi (ms)    : t1i-t0i\n"
  "  findwhichi (1) : 0 to find t0i, 1 to find t1i, 2 to find neither\n"
  "\n"
  "  cai (mM)\n"
  "  cinit (mM) : initial cai\n"
  "  cmax (mM)  : max cai during previous run\n"
  "  tcmax (ms)  : time at which imax occurred\n"
  "\n"
  "  svr (/micron)  : surface/volume ratio, which depends on the ca accumulation mechanism\n"
  "            : for cacum.mod it is depth_cacum\n"
  "\n"
  "  area (micron2) : segment surface area\n"
  "  qapprox (picocoulomb)\n"
  "  cmaxp (mM)\n"
  "\n"
  "  v (mV)\n"
  "  vinit (mV) : initial v\n"
  "  vmax (mV)  : max v during previous run\n"
  "  tvmax (ms)  : time at which vmax occurred\n"
  "  vhalf (mV) : (vinit + vmax)/2\n"
  "  t0v (ms)    : time in rising phase of v transient when v first > vhalf\n"
  "  t1v (ms)    : time in falling phase of v when v first < vhalf\n"
  "  hwv (ms)    : t1v-t0v\n"
  "  findwhichv (1) : 0 to find t0v, 1 to find t1v, 2 to find neither\n"
  "  vxt (ms mV) : (vmax - vinit)*hwv\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "  if (mode==1) { : measure peak ica\n"
  ": printf(\"Finding imax\\n\")\n"
  "    iinit = ica\n"
  ": printf(\"iinit is %g\\n\", iinit)\n"
  "    imax = ica\n"
  "    timax = t\n"
  "    ihalf = ica\n"
  "    t0i = -1 (ms) : nonsense values for t0i, t1i, hwi\n"
  "    t1i = -1 (ms)\n"
  "    hwi = -1 (ms)\n"
  "\n"
  "    cinit = cai\n"
  "    cmax = cai\n"
  "    tcmax = t\n"
  "\n"
  "    vinit = v\n"
  "    vmax = v\n"
  "    tvmax = t\n"
  "    vhalf = v\n"
  "    t0v = -1 (ms) : nonsense values for t0v, t1v, hwv\n"
  "    t1v = -1 (ms)\n"
  "    hwv = -1 (ms)\n"
  "\n"
  "  } else if (mode==2) { : calc ihalf from iinit and imax in order to determine halfwidth\n"
  ": printf(\"Determining ica transient's halfwidth\\n\")\n"
  "    ihalf = (iinit + imax)/2\n"
  ": printf(\"iinit is %g and ihalf is %g\\n\", iinit, ihalf)\n"
  "    findwhichi = 0 : 0 to find t0i, 1 to find t1i\n"
  "    vhalf = (vinit + vmax)/2\n"
  "    findwhichv = 0 : 0 to find t0v, 1 to find t1v\n"
  "  }\n"
  "}\n"
  "\n"
  ": find ica threshold crossings\n"
  "PROCEDURE findix() {\n"
  "  if (findwhichi==0) {\n"
  "    if (ica < ihalf) {\n"
  "      t0i = t\n"
  "      findwhichi = 1\n"
  "    }\n"
  "  } else if (findwhichi==1) {\n"
  "    if (ica > ihalf) { \n"
  "      t1i = t\n"
  "      hwi = t1i-t0i\n"
  "      findwhichi = 2 : stop looking already\n"
  "    }\n"
  "  }\n"
  "}\n"
  "\n"
  ": find v threshold crossings\n"
  "PROCEDURE findvx() {\n"
  "  if (findwhichv == 0) {\n"
  "    if (v > vhalf) {\n"
  "      t0v = t\n"
  "      findwhichv = 1\n"
  "    }\n"
  "  } else if (findwhichv == 1) {\n"
  "    if (v < vhalf) { \n"
  "      t1v = t\n"
  "      hwv = t1v-t0v\n"
  "      findwhichv = 2 : stop looking already\n"
  "    }\n"
  "  }\n"
  "}\n"
  "\n"
  "COMMENT\n"
  ": steady state m from car mechanism\n"
  "FUNCTION minf(V (mV))(1) {\n"
  "  minf = 1 / (1 + exp((v+14(mV))/(-6.7 (mV))))\n"
  "}\n"
  "ENDCOMMENT\n"
  "\n"
  ": BREAKPOINT {\n"
  ": a mechanism that calculate something on every time step\n"
  ": needs a BREAKPOINT block--even if only an empty one--\n"
  ": or else it will be treated as an ARTIFICIAL_CELL\n"
  "BREAKPOINT { }\n"
  "\n"
  ": AFTER SOLVE { : should work as well, executed half as many times\n"
  "BEFORE STEP { : should work even with cvode\n"
  "  if (mode==1) { : measure peak ica, cai, v, and pcar\n"
  "    if (ica<imax) {\n"
  "      imax = ica\n"
  "      timax = t\n"
  "    }\n"
  "    if (cai>cmax) {\n"
  "      cmax = cai\n"
  "      tcmax = t\n"
  "    }\n"
  "    if (v>vmax) {\n"
  "      vmax = v\n"
  "      tvmax = t\n"
  "    }\n"
  "  } else if (mode==2) {\n"
  "    findix()\n"
  "    qapprox = -(0.01)*area*(imax-iinit)*hwi\n"
  "    cmaxp = cinit - (10000)*svr*(imax-iinit)*hwi/2/F\n"
  "    findvx()\n"
  "    vxt = (vmax - vinit)*hwv\n"
  "  }\n"
  "}\n"
  ;
#endif
