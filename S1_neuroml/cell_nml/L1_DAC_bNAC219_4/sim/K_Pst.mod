TITLE Mod file for component: Component(id=K_Pst type=ionChannelHH)

COMMENT

    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)
         org.neuroml.export  v1.11.0
         org.neuroml.model   v1.11.0
         jLEMS               v0.12.0

ENDCOMMENT

NEURON {
    SUFFIX K_Pst
    USEION k WRITE ik VALENCE 1 ? Assuming valence = 1; TODO check this!!
    
    RANGE gion
    RANGE i__K_Pst : a copy of the variable for current which makes it easier to access from outside the mod file
    RANGE gmax                              : Will be changed when ion channel mechanism placed on cell!
    RANGE conductance                       : parameter
    RANGE g                                 : exposure
    RANGE fopen                             : exposure
    RANGE m_instances                       : parameter
    RANGE m_tau                             : exposure
    RANGE m_inf                             : exposure
    RANGE m_rateScale                       : exposure
    RANGE m_fcond                           : exposure
    RANGE m_timeCourse_TIME_SCALE           : parameter
    RANGE m_timeCourse_VOLT_SCALE           : parameter
    RANGE m_timeCourse_t                    : exposure
    RANGE m_steadyState_rate                : parameter
    RANGE m_steadyState_midpoint            : parameter
    RANGE m_steadyState_scale               : parameter
    RANGE m_steadyState_x                   : exposure
    RANGE m_q10Settings_fixedQ10            : parameter
    RANGE m_q10Settings_q10                 : exposure
    RANGE h_instances                       : parameter
    RANGE h_tau                             : exposure
    RANGE h_inf                             : exposure
    RANGE h_rateScale                       : exposure
    RANGE h_fcond                           : exposure
    RANGE h_timeCourse_TIME_SCALE           : parameter
    RANGE h_timeCourse_VOLT_SCALE           : parameter
    RANGE h_timeCourse_t                    : exposure
    RANGE h_steadyState_rate                : parameter
    RANGE h_steadyState_midpoint            : parameter
    RANGE h_steadyState_scale               : parameter
    RANGE h_steadyState_x                   : exposure
    RANGE h_q10Settings_fixedQ10            : parameter
    RANGE h_q10Settings_q10                 : exposure
    RANGE m_timeCourse_V                    : derived variable
    RANGE m_tauUnscaled                     : derived variable
    RANGE h_timeCourse_V                    : derived variable
    RANGE h_tauUnscaled                     : derived variable
    RANGE conductanceScale                  : derived variable
    RANGE fopen0                            : derived variable
    
}

UNITS {
    
    (nA) = (nanoamp)
    (uA) = (microamp)
    (mA) = (milliamp)
    (A) = (amp)
    (mV) = (millivolt)
    (mS) = (millisiemens)
    (uS) = (microsiemens)
    (nF) = (nanofarad)
    (molar) = (1/liter)
    (kHz) = (kilohertz)
    (mM) = (millimolar)
    (um) = (micrometer)
    (umol) = (micromole)
    (pC) = (picocoulomb)
    (S) = (siemens)
    
}

PARAMETER {
    
    gmax = 0  (S/cm2)                       : Will be changed when ion channel mechanism placed on cell!
    
    conductance = 1.0E-5 (uS)              : was: 1.0E-11 (conductance)
    m_instances = 2                        : was: 2.0 (none)
    m_timeCourse_TIME_SCALE = 1 (ms)       : was: 0.001 (time)
    m_timeCourse_VOLT_SCALE = 1 (mV)       : was: 0.001 (voltage)
    m_steadyState_rate = 1                 : was: 1.0 (none)
    m_steadyState_midpoint = -11 (mV)      : was: -0.011 (voltage)
    m_steadyState_scale = 12 (mV)          : was: 0.012 (voltage)
    m_q10Settings_fixedQ10 = 2.9528825     : was: 2.95288264141 (none)
    h_instances = 1                        : was: 1.0 (none)
    h_timeCourse_TIME_SCALE = 1 (ms)       : was: 0.001 (time)
    h_timeCourse_VOLT_SCALE = 1 (mV)       : was: 0.001 (voltage)
    h_steadyState_rate = 1                 : was: 1.0 (none)
    h_steadyState_midpoint = -64 (mV)      : was: -0.064 (voltage)
    h_steadyState_scale = -11 (mV)         : was: -0.011 (voltage)
    h_q10Settings_fixedQ10 = 2.9528825     : was: 2.95288264141 (none)
}

ASSIGNED {
    
    gion   (S/cm2)                          : Transient conductance density of the channel? Standard Assigned variables with ionChannel
    v (mV)
    celsius (degC)
    temperature (K)
    ek (mV)
    ik (mA/cm2)
    i__K_Pst (mA/cm2)
    
    m_timeCourse_V                          : derived variable
    
    m_timeCourse_t (ms)                     : conditional derived var...
    m_steadyState_x                         : derived variable
    m_q10Settings_q10                       : derived variable
    m_rateScale                             : derived variable
    m_fcond                                 : derived variable
    m_inf                                   : derived variable
    m_tauUnscaled (ms)                      : derived variable
    m_tau (ms)                              : derived variable
    h_timeCourse_V                          : derived variable
    h_timeCourse_t (ms)                     : derived variable
    h_steadyState_x                         : derived variable
    h_q10Settings_q10                       : derived variable
    h_rateScale                             : derived variable
    h_fcond                                 : derived variable
    h_inf                                   : derived variable
    h_tauUnscaled (ms)                      : derived variable
    h_tau (ms)                              : derived variable
    conductanceScale                        : derived variable
    fopen0                                  : derived variable
    fopen                                   : derived variable
    g (uS)                                  : derived variable
    rate_m_q (/ms)
    rate_h_q (/ms)
    
}

STATE {
    m_q  : dimension: none
    h_q  : dimension: none
    
}

INITIAL {
    ek = -85.0
    
    temperature = celsius + 273.15
    
    rates()
    rates() ? To ensure correct initialisation.
    
    m_q = m_inf
    
    h_q = h_inf
    
}

BREAKPOINT {
    
    SOLVE states METHOD cnexp
    
    ? DerivedVariable is based on path: conductanceScaling[*]/factor, on: Component(id=K_Pst type=ionChannelHH), from conductanceScaling; null
    ? Path not present in component, using factor: 1
    
    conductanceScale = 1 
    
    ? DerivedVariable is based on path: gates[*]/fcond, on: Component(id=K_Pst type=ionChannelHH), from gates; Component(id=m type=gateHHtauInf)
    ? multiply applied to all instances of fcond in: <gates> ([Component(id=m type=gateHHtauInf), Component(id=h type=gateHHtauInf)]))
    fopen0 = m_fcond * h_fcond ? path based, prefix = 
    
    fopen = conductanceScale  *  fopen0 ? evaluable
    g = conductance  *  fopen ? evaluable
    gion = gmax * fopen 
    
    ik = gion * (v - ek)
    i__K_Pst =  -1 * ik : set this variable to the current also - note -1 as channel current convention for LEMS used!
    
}

DERIVATIVE states {
    rates()
    m_q' = rate_m_q 
    h_q' = rate_h_q 
    
}

PROCEDURE rates() {
    
    m_timeCourse_V = v /  m_timeCourse_VOLT_SCALE ? evaluable
    if (m_timeCourse_V   < ( -60 ))  { 
        m_timeCourse_t = ( (1.25 + 175.03 * (exp (( m_timeCourse_V +10) * 0.026))) ) *  m_timeCourse_TIME_SCALE ? evaluable cdv
    } else  { 
        m_timeCourse_t = ( (1.25 + 13 * (exp (( m_timeCourse_V +10) * -0.026)))) *  m_timeCourse_TIME_SCALE ? evaluable cdv
    }
    
    m_steadyState_x = m_steadyState_rate  / (1 + exp(0 - (v -  m_steadyState_midpoint )/ m_steadyState_scale )) ? evaluable
    m_q10Settings_q10 = m_q10Settings_fixedQ10 ? evaluable
    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=m type=gateHHtauInf), from q10Settings; Component(id=null type=q10Fixed)
    ? multiply applied to all instances of q10 in: <q10Settings> ([Component(id=null type=q10Fixed)]))
    m_rateScale = m_q10Settings_q10 ? path based, prefix = m_
    
    m_fcond = m_q ^ m_instances ? evaluable
    ? DerivedVariable is based on path: steadyState/x, on: Component(id=m type=gateHHtauInf), from steadyState; Component(id=null type=HHSigmoidVariable)
    m_inf = m_steadyState_x ? path based, prefix = m_
    
    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=m type=gateHHtauInf), from timeCourse; Component(id=null type=K_Pst_m_tau)
    m_tauUnscaled = m_timeCourse_t ? path based, prefix = m_
    
    m_tau = m_tauUnscaled  /  m_rateScale ? evaluable
    h_timeCourse_V = v /  h_timeCourse_VOLT_SCALE ? evaluable
    h_timeCourse_t = (360 + (1010 + 24*( h_timeCourse_V +65)) * (exp (-1 *(( h_timeCourse_V +85)/48)*(( h_timeCourse_V +85)/48)))) *  h_timeCourse_TIME_SCALE ? evaluable
    h_steadyState_x = h_steadyState_rate  / (1 + exp(0 - (v -  h_steadyState_midpoint )/ h_steadyState_scale )) ? evaluable
    h_q10Settings_q10 = h_q10Settings_fixedQ10 ? evaluable
    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=h type=gateHHtauInf), from q10Settings; Component(id=null type=q10Fixed)
    ? multiply applied to all instances of q10 in: <q10Settings> ([Component(id=null type=q10Fixed)]))
    h_rateScale = h_q10Settings_q10 ? path based, prefix = h_
    
    h_fcond = h_q ^ h_instances ? evaluable
    ? DerivedVariable is based on path: steadyState/x, on: Component(id=h type=gateHHtauInf), from steadyState; Component(id=null type=HHSigmoidVariable)
    h_inf = h_steadyState_x ? path based, prefix = h_
    
    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=h type=gateHHtauInf), from timeCourse; Component(id=null type=K_Pst_h_tau)
    h_tauUnscaled = h_timeCourse_t ? path based, prefix = h_
    
    h_tau = h_tauUnscaled  /  h_rateScale ? evaluable
    
     
    rate_m_q = ( m_inf  -  m_q ) /  m_tau ? Note units of all quantities used here need to be consistent!
    
     
    
     
    
     
    
     
    rate_h_q = ( h_inf  -  h_q ) /  h_tau ? Note units of all quantities used here need to be consistent!
    
     
    
     
    
     
    
     
    
}

