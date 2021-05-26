/*
 * cranePlant.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "cranePlant".
 *
 * Model version              : 1.239
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Mar 14 18:05:21 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_cranePlant_h_
#define RTW_HEADER_cranePlant_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef cranePlant_COMMON_INCLUDES_
# define cranePlant_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* cranePlant_COMMON_INCLUDES_ */

#include "cranePlant_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T TransferFcn;                  /* '<S3>/Transfer Fcn' */
  real_T r;                            /* '<Root>/rad2deg' */
  real_T theta;                        /* '<S4>/Rotary Arm: counts to rad' */
  real_T theta_c;                      /* '<Root>/Gain2' */
  real_T alpha;                        /* '<S4>/Pendulum: counts to rad' */
  real_T thetadothat;                  /* '<S4>/Analog Filter Design1' */
  real_T alphadothat;                  /* '<S4>/Analog Filter Design' */
  real_T x[4];                         /* '<Root>/Quanser Rotary Pendulum 1' */
  real_T FilterCoefficient;            /* '<S1>/Filter Coefficient' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T IntegralGain;                 /* '<S1>/Integral Gain' */
  real_T Saturation;                   /* '<S2>/Saturation' */
  real_T Derivative;                   /* '<S4>/Derivative' */
  real_T Derivative1;                  /* '<S4>/Derivative1' */
  real_T Gain1;                        /* '<S4>/Gain1' */
  real_T TmpSignalConversionAtToWorkspac[4];
  real_T Clock;                        /* '<Root>/Clock' */
  real_T ref[4];                       /* '<S3>/Reference Generator' */
  real_T gscount;                      /* '<S3>/Reference Generator' */
  real_T rst;                          /* '<S3>/Reference Generator' */
  boolean_T finished;                  /* '<S3>/Reference Generator' */
} B_cranePlant_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  real_T TimeStampA;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S4>/Derivative' */
  real_T TimeStampB;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S4>/Derivative' */
  real_T TimeStampA_c;                 /* '<S4>/Derivative1' */
  real_T LastUAtTimeA_e;               /* '<S4>/Derivative1' */
  real_T TimeStampB_i;                 /* '<S4>/Derivative1' */
  real_T LastUAtTimeB_g;               /* '<S4>/Derivative1' */
  real_T n;                            /* '<S3>/Reference Generator' */
  real_T goodSteps;                    /* '<S3>/Reference Generator' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  t_task HILReadEncoderTimebase_Task;  /* '<S4>/HIL Read Encoder Timebase' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S2>/Scope' */

  void *HILWriteAnalog_PWORK;          /* '<S4>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     /* '<S3>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S3>/Scope2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_h;               /* '<S3>/To Workspace' */

  int32_T HILInitialize_ClockModes;    /* '<Root>/HIL Initialize' */
  int32_T HILReadEncoderTimebase_Buffer[2];/* '<S4>/HIL Read Encoder Timebase' */
  boolean_T done;                      /* '<S3>/Reference Generator' */
} DW_cranePlant_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S3>/Transfer Fcn' */
  real_T AnalogFilterDesign1_CSTATE[2];/* '<S4>/Analog Filter Design1' */
  real_T AnalogFilterDesign_CSTATE[2]; /* '<S4>/Analog Filter Design' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Filter_CSTATE;                /* '<S1>/Filter' */
} X_cranePlant_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S3>/Transfer Fcn' */
  real_T AnalogFilterDesign1_CSTATE[2];/* '<S4>/Analog Filter Design1' */
  real_T AnalogFilterDesign_CSTATE[2]; /* '<S4>/Analog Filter Design' */
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Filter_CSTATE;                /* '<S1>/Filter' */
} XDot_cranePlant_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S3>/Transfer Fcn' */
  boolean_T AnalogFilterDesign1_CSTATE[2];/* '<S4>/Analog Filter Design1' */
  boolean_T AnalogFilterDesign_CSTATE[2];/* '<S4>/Analog Filter Design' */
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S1>/Filter' */
} XDis_cranePlant_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (auto storage) */
struct P_cranePlant_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  real_T HILInitialize_final_analog_outp;/* Mask Parameter: HILInitialize_final_analog_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_e;/* Mask Parameter: HILInitialize_set_other_outpu_e
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  int32_T HILReadEncoderTimebase_clock;/* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<S4>/HIL Read Encoder Timebase'
                                        */
  uint32_T HILReadEncoderTimebase_channels[2];/* Mask Parameter: HILReadEncoderTimebase_channels
                                               * Referenced by: '<S4>/HIL Read Encoder Timebase'
                                               */
  uint32_T HILWriteAnalog_channels;    /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<S4>/HIL Write Analog'
                                        */
  uint32_T HILReadEncoderTimebase_samples_;/* Mask Parameter: HILReadEncoderTimebase_samples_
                                            * Referenced by: '<S4>/HIL Read Encoder Timebase'
                                            */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_o;/* Mask Parameter: HILInitialize_set_analog_outp_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_p;/* Mask Parameter: HILInitialize_set_digital_out_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_k;/* Mask Parameter: HILInitialize_set_pwm_outputs_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T rad2deg_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<Root>/rad2deg'
                                        */
  real_T RotaryArmcountstorad_Gain;    /* Expression: -0.00307
                                        * Referenced by: '<S4>/Rotary Arm: counts to rad'
                                        */
  real_T Gain2_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Pendulumcountstorad_Gain;     /* Expression: 0.00307
                                        * Referenced by: '<S4>/Pendulum: counts to rad'
                                        */
  real_T AnalogFilterDesign1_A[3];     /* Computed Parameter: AnalogFilterDesign1_A
                                        * Referenced by: '<S4>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_B;        /* Computed Parameter: AnalogFilterDesign1_B
                                        * Referenced by: '<S4>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_C;        /* Computed Parameter: AnalogFilterDesign1_C
                                        * Referenced by: '<S4>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign1_X0;       /* Expression: 0
                                        * Referenced by: '<S4>/Analog Filter Design1'
                                        */
  real_T AnalogFilterDesign_A[3];      /* Computed Parameter: AnalogFilterDesign_A
                                        * Referenced by: '<S4>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_B;         /* Computed Parameter: AnalogFilterDesign_B
                                        * Referenced by: '<S4>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_C;         /* Computed Parameter: AnalogFilterDesign_C
                                        * Referenced by: '<S4>/Analog Filter Design'
                                        */
  real_T AnalogFilterDesign_X0;        /* Expression: 0
                                        * Referenced by: '<S4>/Analog Filter Design'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -10
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  boolean_T HILReadEncoderTimebase_Active;/* Computed Parameter: HILReadEncoderTimebase_Active
                                           * Referenced by: '<S4>/HIL Read Encoder Timebase'
                                           */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S4>/HIL Write Analog'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_cranePlant_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_cranePlant_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[7];
    real_T odeF[4][7];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_cranePlant_T cranePlant_P;

/* Block signals (auto storage) */
extern B_cranePlant_T cranePlant_B;

/* Continuous states (auto storage) */
extern X_cranePlant_T cranePlant_X;

/* Block states (auto storage) */
extern DW_cranePlant_T cranePlant_DW;

/* Model entry point functions */
extern void cranePlant_initialize(void);
extern void cranePlant_step(void);
extern void cranePlant_terminate(void);

/* Real-time Model object */
extern RT_MODEL_cranePlant_T *const cranePlant_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'cranePlant'
 * '<S1>'   : 'cranePlant/PID Controller'
 * '<S2>'   : 'cranePlant/Quanser Rotary Pendulum 1'
 * '<S3>'   : 'cranePlant/Reference Generator'
 * '<S4>'   : 'cranePlant/Quanser Rotary Pendulum 1/Plant'
 * '<S5>'   : 'cranePlant/Reference Generator/Reference Generator'
 * '<S6>'   : 'cranePlant/Reference Generator/Reference Generator1'
 */
#endif                                 /* RTW_HEADER_cranePlant_h_ */
