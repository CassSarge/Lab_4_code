/*
 * cranePlant.c
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
#include "cranePlant_dt.h"

/* Block signals (auto storage) */
B_cranePlant_T cranePlant_B;

/* Continuous states */
X_cranePlant_T cranePlant_X;

/* Block states (auto storage) */
DW_cranePlant_T cranePlant_DW;

/* Real-time model */
RT_MODEL_cranePlant_T cranePlant_M_;
RT_MODEL_cranePlant_T *const cranePlant_M = &cranePlant_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  cranePlant_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  cranePlant_step();
  cranePlant_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  cranePlant_step();
  cranePlant_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  cranePlant_step();
  cranePlant_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void cranePlant_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  if (rtmIsMajorTimeStep(cranePlant_M)) {
    /* set solver stop time */
    if (!(cranePlant_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&cranePlant_M->solverInfo,
                            ((cranePlant_M->Timing.clockTickH0 + 1) *
        cranePlant_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&cranePlant_M->solverInfo,
                            ((cranePlant_M->Timing.clockTick0 + 1) *
        cranePlant_M->Timing.stepSize0 + cranePlant_M->Timing.clockTickH0 *
        cranePlant_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(cranePlant_M)) {
    cranePlant_M->Timing.t[0] = rtsiGetT(&cranePlant_M->solverInfo);
  }

  {
    real_T *lastU;
    static const real_T waypoints[4] = { 0.33161255787892258,
      -1.0471975511965976, 0.52359877559829882, 0.0 };

    real_T rtb_TmpSignalConversionAtSFun_0;
    if (rtmIsMajorTimeStep(cranePlant_M)) {
      /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

      /* S-Function Block: cranePlant/Quanser Rotary Pendulum 1/Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
      {
        t_error result;
        result = hil_task_read_encoder(cranePlant_DW.HILReadEncoderTimebase_Task,
          1, &cranePlant_DW.HILReadEncoderTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(cranePlant_M, _rt_error_message);
        } else {
          rtb_HILReadEncoderTimebase_o1 =
            cranePlant_DW.HILReadEncoderTimebase_Buffer[0];
          rtb_HILReadEncoderTimebase_o2 =
            cranePlant_DW.HILReadEncoderTimebase_Buffer[1];
        }
      }
    }

    /* TransferFcn: '<S3>/Transfer Fcn' */
    cranePlant_B.TransferFcn = 0.0;
    cranePlant_B.TransferFcn += cranePlant_P.TransferFcn_C *
      cranePlant_X.TransferFcn_CSTATE;

    /* Gain: '<Root>/rad2deg' */
    cranePlant_B.r = cranePlant_P.rad2deg_Gain * cranePlant_B.TransferFcn;
    if (rtmIsMajorTimeStep(cranePlant_M)) {
      /* Gain: '<S4>/Rotary Arm: counts to rad' */
      cranePlant_B.theta = cranePlant_P.RotaryArmcountstorad_Gain *
        rtb_HILReadEncoderTimebase_o1;

      /* Gain: '<Root>/Gain2' */
      cranePlant_B.theta_c = cranePlant_P.Gain2_Gain * cranePlant_B.theta;

      /* Gain: '<S4>/Pendulum: counts to rad' */
      cranePlant_B.alpha = cranePlant_P.Pendulumcountstorad_Gain *
        rtb_HILReadEncoderTimebase_o2;
    }

    /* StateSpace: '<S4>/Analog Filter Design1' */
    cranePlant_B.thetadothat = 0.0;
    cranePlant_B.thetadothat += cranePlant_P.AnalogFilterDesign1_C *
      cranePlant_X.AnalogFilterDesign1_CSTATE[1];

    /* StateSpace: '<S4>/Analog Filter Design' */
    cranePlant_B.alphadothat = 0.0;
    cranePlant_B.alphadothat += cranePlant_P.AnalogFilterDesign_C *
      cranePlant_X.AnalogFilterDesign_CSTATE[1];
    if (rtmIsMajorTimeStep(cranePlant_M)) {
      /* SignalConversion: '<Root>/TmpSignal ConversionAtTo WorkspaceInport1' */
      cranePlant_B.x[0] = cranePlant_B.theta;
      cranePlant_B.x[1] = cranePlant_B.alpha;
      cranePlant_B.x[2] = cranePlant_B.thetadothat;
      cranePlant_B.x[3] = cranePlant_B.alphadothat;

      /* MATLAB Function: '<S3>/Reference Generator' incorporates:
       *  SignalConversion: '<S5>/TmpSignal ConversionAt SFunction Inport1'
       */
      /* MATLAB Function 'Reference Generator/Reference Generator': '<S5>:1' */
      /*      coder.allowpcode('REFGEN'); */
      cranePlant_B.ref[0] = 0.0;
      cranePlant_B.ref[1] = 0.0;
      cranePlant_B.ref[2] = 0.0;
      cranePlant_B.ref[3] = 0.0;
      if (!cranePlant_DW.done) {
        if ((fabs(waypoints[(int32_T)cranePlant_DW.n - 1] - cranePlant_B.theta) <=
             0.017453292519943295) && (fabs(cranePlant_B.alpha) <=
             0.017453292519943295) && (fabs(cranePlant_B.thetadothat) <= 0.1) &&
            (fabs(cranePlant_B.alphadothat) <= 0.1)) {
          cranePlant_DW.goodSteps++;
        } else {
          cranePlant_DW.goodSteps = 1.0;
        }

        if (cranePlant_DW.goodSteps >= 125.0) {
          cranePlant_DW.n++;
          if (cranePlant_DW.n > 4.0) {
            cranePlant_DW.done = true;
          }
        }
      }

      if (!cranePlant_DW.done) {
        cranePlant_B.ref[0] = waypoints[(int32_T)cranePlant_DW.n - 1];
        cranePlant_B.finished = cranePlant_DW.done;
      } else {
        cranePlant_B.ref[0] = 0.0;
        cranePlant_B.finished = cranePlant_DW.done;
      }

      /* '<S5>:1:4' */
      cranePlant_B.gscount = cranePlant_DW.goodSteps;

      /* '<S5>:1:4' */
      cranePlant_B.rst = 1.0;

      /* End of MATLAB Function: '<S3>/Reference Generator' */
    }

    /* Sum: '<Root>/Sum' */
    rtb_TmpSignalConversionAtSFun_0 = cranePlant_B.TransferFcn -
      cranePlant_B.theta;

    /* Gain: '<S1>/Filter Coefficient' incorporates:
     *  Gain: '<S1>/Derivative Gain'
     *  Integrator: '<S1>/Filter'
     *  Sum: '<S1>/SumD'
     */
    cranePlant_B.FilterCoefficient = (cranePlant_P.PIDController_D *
      rtb_TmpSignalConversionAtSFun_0 - cranePlant_X.Filter_CSTATE) *
      cranePlant_P.PIDController_N;

    /* Sum: '<S1>/Sum' incorporates:
     *  Gain: '<S1>/Proportional Gain'
     *  Integrator: '<S1>/Integrator'
     */
    cranePlant_B.Sum = (cranePlant_P.PIDController_P *
                        rtb_TmpSignalConversionAtSFun_0 +
                        cranePlant_X.Integrator_CSTATE) +
      cranePlant_B.FilterCoefficient;
    if (rtmIsMajorTimeStep(cranePlant_M)) {
    }

    /* Gain: '<S1>/Integral Gain' */
    cranePlant_B.IntegralGain = cranePlant_P.PIDController_I *
      rtb_TmpSignalConversionAtSFun_0;

    /* Saturate: '<S2>/Saturation' */
    if (cranePlant_B.Sum > cranePlant_P.Saturation_UpperSat) {
      cranePlant_B.Saturation = cranePlant_P.Saturation_UpperSat;
    } else if (cranePlant_B.Sum < cranePlant_P.Saturation_LowerSat) {
      cranePlant_B.Saturation = cranePlant_P.Saturation_LowerSat;
    } else {
      cranePlant_B.Saturation = cranePlant_B.Sum;
    }

    /* End of Saturate: '<S2>/Saturation' */
    if (rtmIsMajorTimeStep(cranePlant_M)) {
    }

    /* Derivative: '<S4>/Derivative' */
    if ((cranePlant_DW.TimeStampA >= cranePlant_M->Timing.t[0]) &&
        (cranePlant_DW.TimeStampB >= cranePlant_M->Timing.t[0])) {
      cranePlant_B.Derivative = 0.0;
    } else {
      rtb_TmpSignalConversionAtSFun_0 = cranePlant_DW.TimeStampA;
      lastU = &cranePlant_DW.LastUAtTimeA;
      if (cranePlant_DW.TimeStampA < cranePlant_DW.TimeStampB) {
        if (cranePlant_DW.TimeStampB < cranePlant_M->Timing.t[0]) {
          rtb_TmpSignalConversionAtSFun_0 = cranePlant_DW.TimeStampB;
          lastU = &cranePlant_DW.LastUAtTimeB;
        }
      } else {
        if (cranePlant_DW.TimeStampA >= cranePlant_M->Timing.t[0]) {
          rtb_TmpSignalConversionAtSFun_0 = cranePlant_DW.TimeStampB;
          lastU = &cranePlant_DW.LastUAtTimeB;
        }
      }

      cranePlant_B.Derivative = (cranePlant_B.alpha - *lastU) /
        (cranePlant_M->Timing.t[0] - rtb_TmpSignalConversionAtSFun_0);
    }

    /* End of Derivative: '<S4>/Derivative' */

    /* Derivative: '<S4>/Derivative1' */
    if ((cranePlant_DW.TimeStampA_c >= cranePlant_M->Timing.t[0]) &&
        (cranePlant_DW.TimeStampB_i >= cranePlant_M->Timing.t[0])) {
      cranePlant_B.Derivative1 = 0.0;
    } else {
      rtb_TmpSignalConversionAtSFun_0 = cranePlant_DW.TimeStampA_c;
      lastU = &cranePlant_DW.LastUAtTimeA_e;
      if (cranePlant_DW.TimeStampA_c < cranePlant_DW.TimeStampB_i) {
        if (cranePlant_DW.TimeStampB_i < cranePlant_M->Timing.t[0]) {
          rtb_TmpSignalConversionAtSFun_0 = cranePlant_DW.TimeStampB_i;
          lastU = &cranePlant_DW.LastUAtTimeB_g;
        }
      } else {
        if (cranePlant_DW.TimeStampA_c >= cranePlant_M->Timing.t[0]) {
          rtb_TmpSignalConversionAtSFun_0 = cranePlant_DW.TimeStampB_i;
          lastU = &cranePlant_DW.LastUAtTimeB_g;
        }
      }

      cranePlant_B.Derivative1 = (cranePlant_B.theta - *lastU) /
        (cranePlant_M->Timing.t[0] - rtb_TmpSignalConversionAtSFun_0);
    }

    /* End of Derivative: '<S4>/Derivative1' */

    /* Gain: '<S4>/Gain1' */
    cranePlant_B.Gain1 = cranePlant_P.Gain1_Gain * cranePlant_B.Saturation;
    if (rtmIsMajorTimeStep(cranePlant_M)) {
      /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

      /* S-Function Block: cranePlant/Quanser Rotary Pendulum 1/Plant/HIL Write Analog (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(cranePlant_DW.HILInitialize_Card,
          &cranePlant_P.HILWriteAnalog_channels, 1, &cranePlant_B.Gain1);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(cranePlant_M, _rt_error_message);
        }
      }

      /* Stop: '<S3>/Stop Simulation' */
      if (cranePlant_B.finished) {
        rtmSetStopRequested(cranePlant_M, 1);
      }

      /* End of Stop: '<S3>/Stop Simulation' */

      /* SignalConversion: '<S3>/TmpSignal ConversionAtTo WorkspaceInport1' */
      cranePlant_B.TmpSignalConversionAtToWorkspac[0] = cranePlant_B.TransferFcn;
      cranePlant_B.TmpSignalConversionAtToWorkspac[1] = cranePlant_B.ref[1];
      cranePlant_B.TmpSignalConversionAtToWorkspac[2] = cranePlant_B.ref[2];
      cranePlant_B.TmpSignalConversionAtToWorkspac[3] = cranePlant_B.ref[3];
    }

    /* Clock: '<Root>/Clock' */
    cranePlant_B.Clock = cranePlant_M->Timing.t[0];
  }

  if (rtmIsMajorTimeStep(cranePlant_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S4>/Derivative' */
    if (cranePlant_DW.TimeStampA == (rtInf)) {
      cranePlant_DW.TimeStampA = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeA;
    } else if (cranePlant_DW.TimeStampB == (rtInf)) {
      cranePlant_DW.TimeStampB = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeB;
    } else if (cranePlant_DW.TimeStampA < cranePlant_DW.TimeStampB) {
      cranePlant_DW.TimeStampA = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeA;
    } else {
      cranePlant_DW.TimeStampB = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeB;
    }

    *lastU = cranePlant_B.alpha;

    /* End of Update for Derivative: '<S4>/Derivative' */

    /* Update for Derivative: '<S4>/Derivative1' */
    if (cranePlant_DW.TimeStampA_c == (rtInf)) {
      cranePlant_DW.TimeStampA_c = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeA_e;
    } else if (cranePlant_DW.TimeStampB_i == (rtInf)) {
      cranePlant_DW.TimeStampB_i = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeB_g;
    } else if (cranePlant_DW.TimeStampA_c < cranePlant_DW.TimeStampB_i) {
      cranePlant_DW.TimeStampA_c = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeA_e;
    } else {
      cranePlant_DW.TimeStampB_i = cranePlant_M->Timing.t[0];
      lastU = &cranePlant_DW.LastUAtTimeB_g;
    }

    *lastU = cranePlant_B.theta;

    /* End of Update for Derivative: '<S4>/Derivative1' */

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, cranePlant_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(cranePlant_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((cranePlant_M->Timing.clockTick1+
                            cranePlant_M->Timing.clockTickH1* 4294967296.0)) *
                          0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(cranePlant_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(cranePlant_M)!=-1) &&
          !((rtmGetTFinal(cranePlant_M)-(((cranePlant_M->Timing.clockTick1+
               cranePlant_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((cranePlant_M->Timing.clockTick1+cranePlant_M->Timing.clockTickH1*
               4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(cranePlant_M, "Simulation finished");
      }

      if (rtmGetStopRequested(cranePlant_M)) {
        rtmSetErrorStatus(cranePlant_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&cranePlant_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++cranePlant_M->Timing.clockTick0)) {
      ++cranePlant_M->Timing.clockTickH0;
    }

    cranePlant_M->Timing.t[0] = rtsiGetSolverStopTime(&cranePlant_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      cranePlant_M->Timing.clockTick1++;
      if (!cranePlant_M->Timing.clockTick1) {
        cranePlant_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void cranePlant_derivatives(void)
{
  XDot_cranePlant_T *_rtXdot;
  _rtXdot = ((XDot_cranePlant_T *) cranePlant_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += cranePlant_P.TransferFcn_A *
    cranePlant_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += cranePlant_B.ref[0];

  /* Derivatives for StateSpace: '<S4>/Analog Filter Design1' */
  _rtXdot->AnalogFilterDesign1_CSTATE[0] = 0.0;

  /* Derivatives for StateSpace: '<S4>/Analog Filter Design' */
  _rtXdot->AnalogFilterDesign_CSTATE[0] = 0.0;

  /* Derivatives for StateSpace: '<S4>/Analog Filter Design1' */
  _rtXdot->AnalogFilterDesign1_CSTATE[1] = 0.0;

  /* Derivatives for StateSpace: '<S4>/Analog Filter Design' */
  _rtXdot->AnalogFilterDesign_CSTATE[1] = 0.0;

  /* Derivatives for StateSpace: '<S4>/Analog Filter Design1' */
  _rtXdot->AnalogFilterDesign1_CSTATE[0] += cranePlant_P.AnalogFilterDesign1_A[0]
    * cranePlant_X.AnalogFilterDesign1_CSTATE[0];
  _rtXdot->AnalogFilterDesign1_CSTATE[0] += cranePlant_P.AnalogFilterDesign1_A[1]
    * cranePlant_X.AnalogFilterDesign1_CSTATE[1];
  _rtXdot->AnalogFilterDesign1_CSTATE[1] += cranePlant_P.AnalogFilterDesign1_A[2]
    * cranePlant_X.AnalogFilterDesign1_CSTATE[0];
  _rtXdot->AnalogFilterDesign1_CSTATE[0] += cranePlant_P.AnalogFilterDesign1_B *
    cranePlant_B.Derivative1;

  /* Derivatives for StateSpace: '<S4>/Analog Filter Design' */
  _rtXdot->AnalogFilterDesign_CSTATE[0] += cranePlant_P.AnalogFilterDesign_A[0] *
    cranePlant_X.AnalogFilterDesign_CSTATE[0];
  _rtXdot->AnalogFilterDesign_CSTATE[0] += cranePlant_P.AnalogFilterDesign_A[1] *
    cranePlant_X.AnalogFilterDesign_CSTATE[1];
  _rtXdot->AnalogFilterDesign_CSTATE[1] += cranePlant_P.AnalogFilterDesign_A[2] *
    cranePlant_X.AnalogFilterDesign_CSTATE[0];
  _rtXdot->AnalogFilterDesign_CSTATE[0] += cranePlant_P.AnalogFilterDesign_B *
    cranePlant_B.Derivative;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = cranePlant_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = cranePlant_B.FilterCoefficient;
}

/* Model initialize function */
void cranePlant_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)cranePlant_M, 0,
                sizeof(RT_MODEL_cranePlant_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&cranePlant_M->solverInfo,
                          &cranePlant_M->Timing.simTimeStep);
    rtsiSetTPtr(&cranePlant_M->solverInfo, &rtmGetTPtr(cranePlant_M));
    rtsiSetStepSizePtr(&cranePlant_M->solverInfo,
                       &cranePlant_M->Timing.stepSize0);
    rtsiSetdXPtr(&cranePlant_M->solverInfo, &cranePlant_M->ModelData.derivs);
    rtsiSetContStatesPtr(&cranePlant_M->solverInfo, (real_T **)
                         &cranePlant_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&cranePlant_M->solverInfo,
      &cranePlant_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&cranePlant_M->solverInfo,
      &cranePlant_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&cranePlant_M->solverInfo,
      &cranePlant_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&cranePlant_M->solverInfo,
      &cranePlant_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&cranePlant_M->solverInfo, (&rtmGetErrorStatus
      (cranePlant_M)));
    rtsiSetRTModelPtr(&cranePlant_M->solverInfo, cranePlant_M);
  }

  rtsiSetSimTimeStep(&cranePlant_M->solverInfo, MAJOR_TIME_STEP);
  cranePlant_M->ModelData.intgData.y = cranePlant_M->ModelData.odeY;
  cranePlant_M->ModelData.intgData.f[0] = cranePlant_M->ModelData.odeF[0];
  cranePlant_M->ModelData.intgData.f[1] = cranePlant_M->ModelData.odeF[1];
  cranePlant_M->ModelData.intgData.f[2] = cranePlant_M->ModelData.odeF[2];
  cranePlant_M->ModelData.intgData.f[3] = cranePlant_M->ModelData.odeF[3];
  cranePlant_M->ModelData.contStates = ((X_cranePlant_T *) &cranePlant_X);
  rtsiSetSolverData(&cranePlant_M->solverInfo, (void *)
                    &cranePlant_M->ModelData.intgData);
  rtsiSetSolverName(&cranePlant_M->solverInfo,"ode4");
  rtmSetTPtr(cranePlant_M, &cranePlant_M->Timing.tArray[0]);
  rtmSetTFinal(cranePlant_M, 50.0);
  cranePlant_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  cranePlant_M->Sizes.checksums[0] = (1885170214U);
  cranePlant_M->Sizes.checksums[1] = (3663121366U);
  cranePlant_M->Sizes.checksums[2] = (2915459038U);
  cranePlant_M->Sizes.checksums[3] = (969684003U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    cranePlant_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(cranePlant_M->extModeInfo,
      &cranePlant_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(cranePlant_M->extModeInfo, cranePlant_M->Sizes.checksums);
    rteiSetTPtr(cranePlant_M->extModeInfo, rtmGetTPtr(cranePlant_M));
  }

  /* block I/O */
  (void) memset(((void *) &cranePlant_B), 0,
                sizeof(B_cranePlant_T));

  /* states (continuous) */
  {
    (void) memset((void *)&cranePlant_X, 0,
                  sizeof(X_cranePlant_T));
  }

  /* states (dwork) */
  (void) memset((void *)&cranePlant_DW, 0,
                sizeof(DW_cranePlant_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    cranePlant_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: cranePlant/HIL Initialize (hil_initialize_block) */
  {
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    static const t_double analog_output_minimums[2U] = {
      -10.0
      , -10.0
    };

    static const t_double analog_output_maximums[2U] = {
      10.0
      , 10.0
    };

    static const t_double initial_analog_outputs[2U] = {
      0.0
      , 0.0
    };

    static const t_uint encoder_input_channels[2U] = {
      0
      , 1
    };

    static const t_encoder_quadrature_mode encoder_quadrature[2U] = {
      ENCODER_QUADRATURE_4X
      , ENCODER_QUADRATURE_4X
    };

    static const t_int32 initial_encoder_counts[2U] = {
      0
      , 0
    };

    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo_usb", "0", &cranePlant_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cranePlant_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(cranePlant_DW.HILInitialize_Card,
      "d0=pwm;d1=pwm;led=auto;update_rate=normal;decimation=1", 55);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cranePlant_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(cranePlant_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cranePlant_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges(cranePlant_DW.HILInitialize_Card,
        analog_output_channels, 2U,
        analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cranePlant_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog(cranePlant_DW.HILInitialize_Card,
        analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cranePlant_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode(cranePlant_DW.HILInitialize_Card,
        encoder_input_channels, 2U, (t_encoder_quadrature_mode *)
        encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cranePlant_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts(cranePlant_DW.HILInitialize_Card,
        encoder_input_channels, 2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cranePlant_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: cranePlant/Quanser Rotary Pendulum 1/Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(cranePlant_DW.HILInitialize_Card,
      cranePlant_P.HILReadEncoderTimebase_samples_,
      cranePlant_P.HILReadEncoderTimebase_channels, 2,
      &cranePlant_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cranePlant_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  cranePlant_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for StateSpace: '<S4>/Analog Filter Design1' */
  cranePlant_X.AnalogFilterDesign1_CSTATE[0] =
    cranePlant_P.AnalogFilterDesign1_X0;

  /* InitializeConditions for StateSpace: '<S4>/Analog Filter Design' */
  cranePlant_X.AnalogFilterDesign_CSTATE[0] = cranePlant_P.AnalogFilterDesign_X0;

  /* InitializeConditions for StateSpace: '<S4>/Analog Filter Design1' */
  cranePlant_X.AnalogFilterDesign1_CSTATE[1] =
    cranePlant_P.AnalogFilterDesign1_X0;

  /* InitializeConditions for StateSpace: '<S4>/Analog Filter Design' */
  cranePlant_X.AnalogFilterDesign_CSTATE[1] = cranePlant_P.AnalogFilterDesign_X0;

  /* InitializeConditions for MATLAB Function: '<S3>/Reference Generator' */
  cranePlant_DW.n = 1.0;
  cranePlant_DW.done = false;
  cranePlant_DW.goodSteps = 1.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  cranePlant_X.Integrator_CSTATE = cranePlant_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  cranePlant_X.Filter_CSTATE = cranePlant_P.Filter_IC;

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  cranePlant_DW.TimeStampA = (rtInf);
  cranePlant_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S4>/Derivative1' */
  cranePlant_DW.TimeStampA_c = (rtInf);
  cranePlant_DW.TimeStampB_i = (rtInf);
}

/* Model terminate function */
void cranePlant_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: cranePlant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(cranePlant_DW.HILInitialize_Card);
    hil_monitor_stop_all(cranePlant_DW.HILInitialize_Card);
    is_switching = false;
    if ((cranePlant_P.HILInitialize_set_analog_outp_o && !is_switching) ||
        (cranePlant_P.HILInitialize_set_analog_output && is_switching)) {
      cranePlant_DW.HILInitialize_AOVoltages[0] =
        cranePlant_P.HILInitialize_final_analog_outp;
      cranePlant_DW.HILInitialize_AOVoltages[1] =
        cranePlant_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(cranePlant_DW.HILInitialize_Card,
        analog_output_channels, num_final_analog_outputs,
        &cranePlant_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cranePlant_M, _rt_error_message);
      }
    }

    hil_task_delete_all(cranePlant_DW.HILInitialize_Card);
    hil_monitor_delete_all(cranePlant_DW.HILInitialize_Card);
    hil_close(cranePlant_DW.HILInitialize_Card);
    cranePlant_DW.HILInitialize_Card = NULL;
  }
}
