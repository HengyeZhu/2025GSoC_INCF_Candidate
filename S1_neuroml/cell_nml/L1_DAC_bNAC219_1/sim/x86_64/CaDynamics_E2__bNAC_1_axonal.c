/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
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
 
#define nrn_init _nrn_init__CaDynamics_E2__bNAC_1_axonal
#define _nrn_initial _nrn_initial__CaDynamics_E2__bNAC_1_axonal
#define nrn_cur _nrn_cur__CaDynamics_E2__bNAC_1_axonal
#define _nrn_current _nrn_current__CaDynamics_E2__bNAC_1_axonal
#define nrn_jacob _nrn_jacob__CaDynamics_E2__bNAC_1_axonal
#define nrn_state _nrn_state__CaDynamics_E2__bNAC_1_axonal
#define _net_receive _net_receive__CaDynamics_E2__bNAC_1_axonal 
#define rates rates__CaDynamics_E2__bNAC_1_axonal 
#define states states__CaDynamics_E2__bNAC_1_axonal 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gamma _p[0]
#define gamma_columnindex 0
#define minCai _p[1]
#define minCai_columnindex 1
#define decay _p[2]
#define decay_columnindex 2
#define depth _p[3]
#define depth_columnindex 3
#define Faraday _p[4]
#define Faraday_columnindex 4
#define AREA_SCALE _p[5]
#define AREA_SCALE_columnindex 5
#define LENGTH_SCALE _p[6]
#define LENGTH_SCALE_columnindex 6
#define currDensCa _p[7]
#define currDensCa_columnindex 7
#define concentration _p[8]
#define concentration_columnindex 8
#define extConcentration _p[9]
#define extConcentration_columnindex 9
#define cai _p[10]
#define cai_columnindex 10
#define cao _p[11]
#define cao_columnindex 11
#define ica _p[12]
#define ica_columnindex 12
#define i__CaDynamics_E2__bNAC_1_axonal _p[13]
#define i__CaDynamics_E2__bNAC_1_axonal_columnindex 13
#define rate_concentration _p[14]
#define rate_concentration_columnindex 14
#define Dconcentration _p[15]
#define Dconcentration_columnindex 15
#define DextConcentration _p[16]
#define DextConcentration_columnindex 16
#define _g _p[17]
#define _g_columnindex 17
#define _ion_cai	*_ppvar[0]._pval
#define _ion_cao	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _style_ca	*((int*)_ppvar[3]._pvoid)
#define diam	*_ppvar[4]._pval
#define area	*_ppvar[5]._pval
 
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
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_rates(void);
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
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_CaDynamics_E2__bNAC_1_axonal", _hoc_setdata,
 "rates_CaDynamics_E2__bNAC_1_axonal", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define iCa iCa_CaDynamics_E2__bNAC_1_axonal
 double iCa = 0;
#define initialExtConcentration initialExtConcentration_CaDynamics_E2__bNAC_1_axonal
 double initialExtConcentration = 0;
#define initialConcentration initialConcentration_CaDynamics_E2__bNAC_1_axonal
 double initialConcentration = 0;
#define surfaceArea surfaceArea_CaDynamics_E2__bNAC_1_axonal
 double surfaceArea = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "surfaceArea_CaDynamics_E2__bNAC_1_axonal", "cm2",
 "iCa_CaDynamics_E2__bNAC_1_axonal", "nA",
 "initialConcentration_CaDynamics_E2__bNAC_1_axonal", "mM",
 "initialExtConcentration_CaDynamics_E2__bNAC_1_axonal", "mM",
 "minCai_CaDynamics_E2__bNAC_1_axonal", "mM",
 "decay_CaDynamics_E2__bNAC_1_axonal", "ms",
 "depth_CaDynamics_E2__bNAC_1_axonal", "cm",
 "Faraday_CaDynamics_E2__bNAC_1_axonal", "pC",
 "AREA_SCALE_CaDynamics_E2__bNAC_1_axonal", "cm2",
 "LENGTH_SCALE_CaDynamics_E2__bNAC_1_axonal", "cm",
 "concentration_CaDynamics_E2__bNAC_1_axonal", "mM",
 "extConcentration_CaDynamics_E2__bNAC_1_axonal", "mM",
 "currDensCa_CaDynamics_E2__bNAC_1_axonal", "nA / cm2",
 0,0
};
 static double concentration0 = 0;
 static double delta_t = 0.01;
 static double extConcentration0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "surfaceArea_CaDynamics_E2__bNAC_1_axonal", &surfaceArea_CaDynamics_E2__bNAC_1_axonal,
 "iCa_CaDynamics_E2__bNAC_1_axonal", &iCa_CaDynamics_E2__bNAC_1_axonal,
 "initialConcentration_CaDynamics_E2__bNAC_1_axonal", &initialConcentration_CaDynamics_E2__bNAC_1_axonal,
 "initialExtConcentration_CaDynamics_E2__bNAC_1_axonal", &initialExtConcentration_CaDynamics_E2__bNAC_1_axonal,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[6]._i
 static void _ode_synonym(int, double**, Datum**);
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"CaDynamics_E2__bNAC_1_axonal",
 "gamma_CaDynamics_E2__bNAC_1_axonal",
 "minCai_CaDynamics_E2__bNAC_1_axonal",
 "decay_CaDynamics_E2__bNAC_1_axonal",
 "depth_CaDynamics_E2__bNAC_1_axonal",
 "Faraday_CaDynamics_E2__bNAC_1_axonal",
 "AREA_SCALE_CaDynamics_E2__bNAC_1_axonal",
 "LENGTH_SCALE_CaDynamics_E2__bNAC_1_axonal",
 0,
 "currDensCa_CaDynamics_E2__bNAC_1_axonal",
 0,
 "concentration_CaDynamics_E2__bNAC_1_axonal",
 "extConcentration_CaDynamics_E2__bNAC_1_axonal",
 0,
 0};
 static Symbol* _morphology_sym;
 extern Node* nrn_alloc_node_;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 18, _prop);
 	/*initialize range parameters*/
 	gamma = 0.001739;
 	minCai = 0.0001;
 	decay = 468.07;
 	depth = 1e-05;
 	Faraday = 9.64853e+10;
 	AREA_SCALE = 10000;
 	LENGTH_SCALE = 100;
 	_prop->param = _p;
 	_prop->param_size = 18;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 7, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[4]._pval = &prop_ion->param[0]; /* diam */
 	_ppvar[5]._pval = &nrn_alloc_node_->_area; /* diam */
 prop_ion = need_memb(_ca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _CaDynamics_E2__bNAC_1_axonal_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", 2.0);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 18, 7);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 4, "diam");
  hoc_register_dparam_semantics(_mechtype, 5, "area");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 CaDynamics_E2__bNAC_1_axonal /home/gluciferd/2025GSoC_INCF_Project12/S1_neuroml/cell_nml/L1_DAC_bNAC219_1/sim/CaDynamics_E2__bNAC_1_axonal.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=CaDynamics_E2__bNAC_1_axonal type=concentrationModelHayEtAl)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates();
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   rates ( _threadargs_ ) ;
   Dconcentration = rate_concentration ;
   cai = concentration ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 rates ( _threadargs_ ) ;
 Dconcentration = Dconcentration  / (1. - dt*( 0.0 )) ;
 cai = concentration ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   rates ( _threadargs_ ) ;
    concentration = concentration - dt*(- ( rate_concentration ) ) ;
   cai = concentration ;
   }
  return 0;
}
 
static int  rates (  ) {
   surfaceArea = ( 1e-08 ) * ( area ) ;
   iCa = ( 1e6 ) * ( - 1.0 * ica * surfaceArea ) ;
   currDensCa = iCa / surfaceArea ;
   rate_concentration = ( currDensCa * gamma / ( 2.0 * Faraday * depth ) ) - ( ( concentration - minCai ) / decay ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  cao = _ion_cao;
  ica = _ion_ica;
  cai = _ion_cai;
     _ode_spec1 ();
  _ion_cai = cai;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_cai =  concentration ;
 }}
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  cao = _ion_cao;
  ica = _ion_ica;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  concentration = concentration0;
  extConcentration = extConcentration0;
 {
   initialConcentration = cai ;
   initialExtConcentration = cao ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   concentration = initialConcentration ;
   extConcentration = initialExtConcentration ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  cai = _ion_cai;
  cao = _ion_cao;
  ica = _ion_ica;
  cai = _ion_cai;
 initmodel();
  _ion_cai = cai;
  nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 
}}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 
}}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
  cai = _ion_cai;
  cao = _ion_cao;
  ica = _ion_ica;
  cai = _ion_cai;
 { error =  states();
 if(error){fprintf(stderr,"at line 99 in file CaDynamics_E2__bNAC_1_axonal.mod:\n    \n"); nrn_complain(_p); abort_run(error);}
 } {
   }
  _ion_cai = cai;
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = concentration_columnindex;  _dlist1[0] = Dconcentration_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/gluciferd/2025GSoC_INCF_Project12/S1_neuroml/cell_nml/L1_DAC_bNAC219_1/sim/CaDynamics_E2__bNAC_1_axonal.mod";
static const char* nmodl_file_text = 
  "TITLE Mod file for component: Component(id=CaDynamics_E2__bNAC_1_axonal type=concentrationModelHayEtAl)\n"
  "\n"
  "COMMENT\n"
  "\n"
  "    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)\n"
  "         org.neuroml.export  v1.11.0\n"
  "         org.neuroml.model   v1.11.0\n"
  "         jLEMS               v0.12.0\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "    SUFFIX CaDynamics_E2__bNAC_1_axonal\n"
  "    USEION ca READ cai, cao, ica WRITE cai VALENCE 2\n"
  "    RANGE cai\n"
  "    RANGE cao\n"
  "    GLOBAL initialConcentration\n"
  "    GLOBAL initialExtConcentration\n"
  "    RANGE gamma                             : parameter\n"
  "    RANGE minCai                            : parameter\n"
  "    RANGE decay                             : parameter\n"
  "    RANGE depth                             : parameter\n"
  "    RANGE Faraday                           : parameter\n"
  "    RANGE AREA_SCALE                        : parameter\n"
  "    RANGE LENGTH_SCALE                      : parameter\n"
  "    RANGE currDensCa                        : derived variable\n"
  "    \n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    \n"
  "    (nA) = (nanoamp)\n"
  "    (uA) = (microamp)\n"
  "    (mA) = (milliamp)\n"
  "    (A) = (amp)\n"
  "    (mV) = (millivolt)\n"
  "    (mS) = (millisiemens)\n"
  "    (uS) = (microsiemens)\n"
  "    (nF) = (nanofarad)\n"
  "    (molar) = (1/liter)\n"
  "    (kHz) = (kilohertz)\n"
  "    (mM) = (millimolar)\n"
  "    (um) = (micrometer)\n"
  "    (umol) = (micromole)\n"
  "    (pC) = (picocoulomb)\n"
  "    (S) = (siemens)\n"
  "    \n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    surfaceArea (cm2)\n"
  "    iCa (nA)\n"
  "    initialConcentration (mM)\n"
  "    initialExtConcentration (mM)\n"
  "    \n"
  "    gamma = 0.001739                       : was: 0.001739 (none)\n"
  "    minCai = 1.0E-4 (mM)                   : was: 1.0E-4 (concentration)\n"
  "    decay = 468.06967 (ms)                 : was: 0.468069681 (time)\n"
  "    depth = 1.0E-5 (cm)                    : was: 1.0E-7 (length)\n"
  "    Faraday = 9.6485302E10 (pC / umol)     : was: 96485.3 (charge_per_mole)\n"
  "    AREA_SCALE = 10000 (cm2)               : was: 1.0 (area)\n"
  "    LENGTH_SCALE = 100 (cm)                : was: 1.0 (length)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    cai (mM)\n"
  "    cao (mM)\n"
  "    ica (mA/cm2)\n"
  "    i__CaDynamics_E2__bNAC_1_axonal (mA/cm2)\n"
  "    diam (um)                               : Added to facilitate access to section's diam\n"
  "    area (um2)                              : Added to facilitate access to section's area\n"
  "    currDensCa (nA / cm2)                   : derived variable\n"
  "    rate_concentration (mM/ms)\n"
  "    \n"
  "}\n"
  "\n"
  "STATE {\n"
  "    concentration (mM) : dimension: concentration\n"
  "    extConcentration (mM) : dimension: concentration\n"
  "    \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    initialConcentration = cai\n"
  "    initialExtConcentration = cao\n"
  "    rates()\n"
  "    rates() ? To ensure correct initialisation.\n"
  "    \n"
  "    concentration = initialConcentration\n"
  "    \n"
  "    extConcentration = initialExtConcentration\n"
  "    \n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    \n"
  "    SOLVE states METHOD cnexp\n"
  "    \n"
  "    \n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates()\n"
  "    concentration' = rate_concentration\n"
  "    cai = concentration \n"
  "    \n"
  "}\n"
  "\n"
  "PROCEDURE rates() {\n"
  "    \n"
  "    surfaceArea = (1e-08)*(area)   : surfaceArea has units (cm2), area (built in to NEURON) is in um^2...\n"
  "    \n"
  "    iCa = (1e6) * (-1 * ica * surfaceArea) :   iCa has units (nA) ; ica (built in to NEURON) has units (mA/cm2)...\n"
  "    \n"
  "    currDensCa = iCa / surfaceArea ? evaluable\n"
  "    rate_concentration = (  currDensCa  *  gamma  /(2*  Faraday  *  depth  )) - ((  concentration   -   minCai  ) /   decay  ) ? Note units of all quantities used here need to be consistent!\n"
  "    \n"
  "     \n"
  "    \n"
  "}\n"
  "\n"
  ;
#endif
