/*
 * cranePlant_data.c
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

#include "cranePlant.h"
#include "cranePlant_private.h"

/* Block parameters (auto storage) */
P_cranePlant_T cranePlant_P = {
  2.0,                                 /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  2.5,                                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  100.0,                               /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  3.0,                                 /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<S4>/HIL Read Encoder Timebase'
                                        */

  /*  Mask Parameter: HILReadEncoderTimebase_channels
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  { 0U, 1U },
  0U,                                  /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<S4>/HIL Write Analog'
                                        */
  500U,                                /* Mask Parameter: HILReadEncoderTimebase_samples_
                                        * Referenced by: '<S4>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -20.0,                               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  20.0,                                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/rad2deg'
                                        */
  -0.00307,                            /* Expression: -0.00307
                                        * Referenced by: '<S4>/Rotary Arm: counts to rad'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain2'
                                        */
  0.00307,                             /* Expression: 0.00307
                                        * Referenced by: '<S4>/Pendulum: counts to rad'
                                        */

  /*  Computed Parameter: AnalogFilterDesign1_A
   * Referenced by: '<S4>/Analog Filter Design1'
   */
  { -141.42135623730948, -100.0, 100.0 },
  100.0,                               /* Computed Parameter: AnalogFilterDesign1_B
                                        * Referenced by: '<S4>/Analog Filter Design1'
                                        */
  1.0,                                 /* Computed Parameter: AnalogFilterDesign1_C
                                        * Referenced by: '<S4>/Analog Filter Design1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Analog Filter Design1'
                                        */

  /*  Computed Parameter: AnalogFilterDesign_A
   * Referenced by: '<S4>/Analog Filter Design'
   */
  { -141.42135623730948, -100.0, 100.0 },
  100.0,                               /* Computed Parameter: AnalogFilterDesign_B
                                        * Referenced by: '<S4>/Analog Filter Design'
                                        */
  1.0,                                 /* Computed Parameter: AnalogFilterDesign_C
                                        * Referenced by: '<S4>/Analog Filter Design'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Analog Filter Design'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<S4>/HIL Read Encoder Timebase'
                                        */
  0                                    /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S4>/HIL Write Analog'
                                        */
};
