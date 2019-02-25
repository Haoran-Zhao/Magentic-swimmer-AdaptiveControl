/* Include files */

#include "blascompat32.h"
#include "lin_model_PI_MRAC_Sim_CASE2_sfun.h"
#include "c1_lin_model_PI_MRAC_Sim_CASE2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lin_model_PI_MRAC_Sim_CASE2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[5] = { "nargin", "nargout", "b", "A",
  "y" };

/* Function Declarations */
static void initialize_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void initialize_params_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void enable_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void disable_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void set_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_st);
static void finalize_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void sf_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void initSimStructsc1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_y, const char_T *c1_identifier, real_T
  c1_b_y[44]);
static void c1_b_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[44]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[57]);
static void c1_mldivide(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_A[44], real_T c1_B[121], real_T c1_Y[44]);
static void c1_eml_scalar_eg(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance);
static void c1_eps(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance);
static real_T c1_sqrt(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
                      *chartInstance, real_T c1_x);
static void c1_eml_error(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance);
static real_T c1_eml_xnrm2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x[44], int32_T c1_ix0);
static real_T c1_ceval_xnrm2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0, int32_T c1_incx);
static int32_T c1_eml_ixamax(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[4], int32_T c1_ix0);
static int32_T c1_ceval_ixamax(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[4], int32_T c1_ix0, int32_T c1_incx);
static void c1_eml_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x[44], int32_T c1_ix0, int32_T c1_iy0, real_T
  c1_b_x[44]);
static void c1_ceval_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0, int32_T c1_incx,
  int32_T c1_iy0, int32_T c1_incy, real_T c1_b_x[44]);
static real_T c1_b_eml_xnrm2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0);
static real_T c1_eml_dlapy2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x1, real_T c1_x2);
static void c1_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0,
  real_T c1_b_x[44]);
static void c1_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0,
  int32_T c1_incx, real_T c1_b_x[44]);
static void c1_eml_matlab_zlarfg(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *
  chartInstance, real_T c1_alpha1, real_T c1_x, real_T *c1_b_alpha1, real_T
  *c1_b_x, real_T *c1_tau);
static real_T c1_b_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_a, real_T c1_x);
static real_T c1_b_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x, int32_T c1_ix0,
  int32_T c1_incx);
static void c1_eml_matlab_zlarf(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[44], int32_T c1_ic0, real_T c1_work[4], real_T c1_b_C[44], real_T
  c1_b_work[4]);
static void c1_eml_blas_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[44], int32_T c1_ia0,
  real_T c1_x[44], int32_T c1_ix0, real_T c1_y[4], real_T c1_b_y[4]);
static void c1_ceval_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[44],
  int32_T c1_ia0, int32_T c1_lda, real_T c1_x[44], int32_T c1_ix0, int32_T
  c1_incx, real_T c1_beta1, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy,
  real_T c1_b_y[4]);
static void c1_ceval_xger(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_incx, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy, real_T c1_A
  [44], int32_T c1_ia0, int32_T c1_lda, real_T c1_b_A[44]);
static void c1_eml_warning(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_varargin_2, char_T c1_varargin_3[14]);
static void c1_d_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14]);
static void c1_e_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14]);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_b_is_active_c1_lin_model_PI_MRAC_Sim_CASE2, const char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sqrt(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
                      *chartInstance, real_T *c1_x);
static void c1_b_eml_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x[44], int32_T c1_ix0, int32_T c1_iy0);
static void c1_b_ceval_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0, int32_T c1_incx,
  int32_T c1_iy0, int32_T c1_incy);
static void c1_c_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0);
static void c1_c_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0,
  int32_T c1_incx);
static real_T c1_b_eml_matlab_zlarfg
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, real_T
   *c1_alpha1, real_T *c1_x);
static void c1_d_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_a, real_T *c1_x);
static void c1_d_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T *c1_x, int32_T c1_ix0,
  int32_T c1_incx);
static void c1_b_eml_matlab_zlarf(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[44], int32_T c1_ic0, real_T c1_work[4]);
static void c1_b_eml_blas_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[44], int32_T c1_ia0,
  real_T c1_x[44], int32_T c1_ix0, real_T c1_y[4]);
static void c1_b_ceval_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[44],
  int32_T c1_ia0, int32_T c1_lda, real_T c1_x[44], int32_T c1_ix0, int32_T
  c1_incx, real_T c1_beta1, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy);
static void c1_b_ceval_xger(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_incx, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy, real_T c1_A
  [44], int32_T c1_ia0, int32_T c1_lda);
static void init_dsm_address_info(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_lin_model_PI_MRAC_Sim_CASE2 = 0U;
}

static void initialize_params_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
}

static void enable_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[44];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_d_y)[44];
  c1_d_y = (real_T (*)[44])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  for (c1_i0 = 0; c1_i0 < 44; c1_i0++) {
    c1_u[c1_i0] = (*c1_d_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 11));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_lin_model_PI_MRAC_Sim_CASE2;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[44];
  int32_T c1_i1;
  real_T (*c1_y)[44];
  c1_y = (real_T (*)[44])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 44; c1_i1++) {
    (*c1_y)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_lin_model_PI_MRAC_Sim_CASE2 =
    c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_lin_model_PI_MRAC_Sim_CASE2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_lin_model_PI_MRAC_Sim_CASE2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
}

static void sf_c1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  real_T c1_b[44];
  int32_T c1_i6;
  real_T c1_A[121];
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_y[44];
  int32_T c1_i7;
  real_T c1_b_b[44];
  int32_T c1_i8;
  real_T c1_b_A[121];
  real_T c1_dv1[44];
  int32_T c1_i9;
  int32_T c1_i10;
  real_T (*c1_b_y)[44];
  real_T (*c1_c_A)[121];
  real_T (*c1_c_b)[44];
  c1_c_A = (real_T (*)[121])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_y = (real_T (*)[44])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_c_b = (real_T (*)[44])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 44; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_c_b)[c1_i2], 0U);
  }

  for (c1_i3 = 0; c1_i3 < 44; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_y)[c1_i3], 1U);
  }

  for (c1_i4 = 0; c1_i4 < 121; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_c_A)[c1_i4], 2U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i5 = 0; c1_i5 < 44; c1_i5++) {
    c1_b[c1_i5] = (*c1_c_b)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 121; c1_i6++) {
    c1_A[c1_i6] = (*c1_c_A)[c1_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_b, 2U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_A, 3U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_y, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  for (c1_i7 = 0; c1_i7 < 44; c1_i7++) {
    c1_b_b[c1_i7] = c1_b[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 121; c1_i8++) {
    c1_b_A[c1_i8] = c1_A[c1_i8];
  }

  c1_mldivide(chartInstance, c1_b_b, c1_b_A, c1_dv1);
  for (c1_i9 = 0; c1_i9 < 44; c1_i9++) {
    c1_y[c1_i9] = c1_dv1[c1_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c1_i10 = 0; c1_i10 < 44; c1_i10++) {
    (*c1_b_y)[c1_i10] = c1_y[c1_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_lin_model_PI_MRAC_Sim_CASE2MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc1_lin_model_PI_MRAC_Sim_CASE2
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T c1_b_inData[44];
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_u[44];
  const mxArray *c1_y = NULL;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i11 = 0;
  for (c1_i12 = 0; c1_i12 < 11; c1_i12++) {
    for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
      c1_b_inData[c1_i13 + c1_i11] = (*(real_T (*)[44])c1_inData)[c1_i13 +
        c1_i11];
    }

    c1_i11 += 4;
  }

  c1_i14 = 0;
  for (c1_i15 = 0; c1_i15 < 11; c1_i15++) {
    for (c1_i16 = 0; c1_i16 < 4; c1_i16++) {
      c1_u[c1_i16 + c1_i14] = c1_b_inData[c1_i16 + c1_i14];
    }

    c1_i14 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 11));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_y, const char_T *c1_identifier, real_T
  c1_b_y[44])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
}

static void c1_b_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[44])
{
  real_T c1_dv2[44];
  int32_T c1_i17;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 4, 11);
  for (c1_i17 = 0; c1_i17 < 44; c1_i17++) {
    c1_y[c1_i17] = c1_dv2[c1_i17];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[44];
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  c1_i18 = 0;
  for (c1_i19 = 0; c1_i19 < 11; c1_i19++) {
    for (c1_i20 = 0; c1_i20 < 4; c1_i20++) {
      (*(real_T (*)[44])c1_outData)[c1_i20 + c1_i18] = c1_b_y[c1_i20 + c1_i18];
    }

    c1_i18 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_b_inData[121];
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  real_T c1_u[121];
  const mxArray *c1_y = NULL;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 11; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 11; c1_i23++) {
      c1_b_inData[c1_i23 + c1_i21] = (*(real_T (*)[121])c1_inData)[c1_i23 +
        c1_i21];
    }

    c1_i21 += 11;
  }

  c1_i24 = 0;
  for (c1_i25 = 0; c1_i25 < 11; c1_i25++) {
    for (c1_i26 = 0; c1_i26 < 11; c1_i26++) {
      c1_u[c1_i26 + c1_i24] = c1_b_inData[c1_i26 + c1_i24];
    }

    c1_i24 += 11;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 11, 11));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_b_inData[44];
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_u[44];
  const mxArray *c1_y = NULL;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i27 = 0;
  for (c1_i28 = 0; c1_i28 < 4; c1_i28++) {
    for (c1_i29 = 0; c1_i29 < 11; c1_i29++) {
      c1_b_inData[c1_i29 + c1_i27] = (*(real_T (*)[44])c1_inData)[c1_i29 +
        c1_i27];
    }

    c1_i27 += 11;
  }

  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 4; c1_i31++) {
    for (c1_i32 = 0; c1_i32 < 11; c1_i32++) {
      c1_u[c1_i32 + c1_i30] = c1_b_inData[c1_i32 + c1_i30];
    }

    c1_i30 += 11;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 11, 4));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_lin_model_PI_MRAC_Sim_CASE2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[57];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i33;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 57));
  for (c1_i33 = 0; c1_i33 < 57; c1_i33++) {
    c1_r0 = &c1_info[c1_i33];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i33);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[57])
{
  c1_info[0].context = "";
  c1_info[0].name = "mldivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[0].fileTimeLo = 3368733440U;
  c1_info[0].fileTimeHi = 30130985U;
  c1_info[0].mFileTimeLo = 509702400U;
  c1_info[0].mFileTimeHi = 30114350U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[1].name = "eml_qrsolve";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[1].fileTimeLo = 2579026944U;
  c1_info[1].fileTimeHi = 30108061U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[2].name = "min";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[2].fileTimeLo = 1619026944U;
  c1_info[2].fileTimeHi = 30108061U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[3].name = "eml_min_or_max";
  c1_info[3].dominantType = "char";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[3].fileTimeLo = 2539026944U;
  c1_info[3].fileTimeHi = 30108061U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[4].name = "eml_scalar_eg";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[4].fileTimeLo = 2619026944U;
  c1_info[4].fileTimeHi = 30108061U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[5].name = "eml_scalexp_alloc";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[5].fileTimeLo = 2619026944U;
  c1_info[5].fileTimeHi = 30108061U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[6].name = "eml_index_class";
  c1_info[6].dominantType = "";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[6].fileTimeLo = 2439026944U;
  c1_info[6].fileTimeHi = 30108061U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[7].name = "eml_xgeqp3";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c1_info[7].fileTimeLo = 2699026944U;
  c1_info[7].fileTimeHi = 30108061U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c1_info[8].name = "eml_lapack_xgeqp3";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c1_info[8].fileTimeLo = 2739026944U;
  c1_info[8].fileTimeHi = 30108061U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c1_info[9].name = "eml_matlab_zgeqp3";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[9].fileTimeLo = 4086200064U;
  c1_info[9].fileTimeHi = 30115466U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[10].name = "colon";
  c1_info[10].dominantType = "int32";
  c1_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[10].fileTimeLo = 3039026944U;
  c1_info[10].fileTimeHi = 30108061U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[11].name = "floor";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[11].fileTimeLo = 2079026944U;
  c1_info[11].fileTimeHi = 30108061U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[12].name = "eml_scalar_floor";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[12].fileTimeLo = 1919026944U;
  c1_info[12].fileTimeHi = 30108061U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[13].name = "intmin";
  c1_info[13].dominantType = "char";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[13].fileTimeLo = 2219026944U;
  c1_info[13].fileTimeHi = 30108061U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[14].name = "intmax";
  c1_info[14].dominantType = "char";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[14].fileTimeLo = 2219026944U;
  c1_info[14].fileTimeHi = 30108061U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c1_info[15].name = "mrdivide";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[15].fileTimeLo = 3368733440U;
  c1_info[15].fileTimeHi = 30130985U;
  c1_info[15].mFileTimeLo = 529702400U;
  c1_info[15].mFileTimeHi = 30114350U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[16].name = "rdivide";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[16].fileTimeLo = 3099026944U;
  c1_info[16].fileTimeHi = 30108061U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[17].name = "eml_div";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[17].fileTimeLo = 1639026944U;
  c1_info[17].fileTimeHi = 30108061U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[18].name = "eps";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[18].fileTimeLo = 1519026944U;
  c1_info[18].fileTimeHi = 30108061U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[19].name = "eml_is_float_class";
  c1_info[19].dominantType = "char";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[19].fileTimeLo = 2479026944U;
  c1_info[19].fileTimeHi = 30108061U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[20].name = "sqrt";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[20].fileTimeLo = 2179026944U;
  c1_info[20].fileTimeHi = 30108061U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[21].name = "eml_error";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[21].fileTimeLo = 1659026944U;
  c1_info[21].fileTimeHi = 30108061U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[22].name = "eml_scalar_sqrt";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[22].fileTimeLo = 2039026944U;
  c1_info[22].fileTimeHi = 30108061U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[23].name = "eml_xnrm2";
  c1_info[23].dominantType = "int32";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[23].fileTimeLo = 1779026944U;
  c1_info[23].fileTimeHi = 30108061U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[24].name = "eml_refblas_xnrm2";
  c1_info[24].dominantType = "int32";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[24].fileTimeLo = 2779026944U;
  c1_info[24].fileTimeHi = 30108061U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[25].name = "eml_index_minus";
  c1_info[25].dominantType = "int32";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[25].fileTimeLo = 2439026944U;
  c1_info[25].fileTimeHi = 30108061U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[26].name = "eml_index_times";
  c1_info[26].dominantType = "int32";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[26].fileTimeLo = 2459026944U;
  c1_info[26].fileTimeHi = 30108061U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[27].name = "eml_index_plus";
  c1_info[27].dominantType = "int32";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[27].fileTimeLo = 2439026944U;
  c1_info[27].fileTimeHi = 30108061U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[28].name = "abs";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[28].fileTimeLo = 1599026944U;
  c1_info[28].fileTimeHi = 30108061U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[29].name = "eml_scalar_abs";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[29].fileTimeLo = 1779026944U;
  c1_info[29].fileTimeHi = 30108061U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[30].name = "eml_ixamax";
  c1_info[30].dominantType = "int32";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[30].fileTimeLo = 1699026944U;
  c1_info[30].fileTimeHi = 30108061U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[31].name = "eml_refblas_ixamax";
  c1_info[31].dominantType = "int32";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[31].fileTimeLo = 2439026944U;
  c1_info[31].fileTimeHi = 30108061U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[32].name = "eml_xcabs1";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[32].fileTimeLo = 1719026944U;
  c1_info[32].fileTimeHi = 30108061U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[33].name = "eml_xswap";
  c1_info[33].dominantType = "int32";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[33].fileTimeLo = 2699026944U;
  c1_info[33].fileTimeHi = 30108061U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[34].name = "eml_refblas_xswap";
  c1_info[34].dominantType = "int32";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[34].fileTimeLo = 2819026944U;
  c1_info[34].fileTimeHi = 30108061U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[35].name = "eml_matlab_zlarfg";
  c1_info[35].dominantType = "int32";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[35].fileTimeLo = 2879026944U;
  c1_info[35].fileTimeHi = 30108061U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[36].name = "eml_dlapy2";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c1_info[36].fileTimeLo = 1639026944U;
  c1_info[36].fileTimeHi = 30108061U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c1_info[37].name = "isnan";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[37].fileTimeLo = 2259026944U;
  c1_info[37].fileTimeHi = 30108061U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[38].name = "realmin";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[38].fileTimeLo = 2339026944U;
  c1_info[38].fileTimeHi = 30108061U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[39].name = "mpower";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[39].fileTimeLo = 3079026944U;
  c1_info[39].fileTimeHi = 30108061U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[40].name = "power";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[40].fileTimeLo = 3099026944U;
  c1_info[40].fileTimeHi = 30108061U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[41].name = "eml_xscal";
  c1_info[41].dominantType = "int32";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c1_info[41].fileTimeLo = 2699026944U;
  c1_info[41].fileTimeHi = 30108061U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[42].name = "eml_refblas_xscal";
  c1_info[42].dominantType = "int32";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[42].fileTimeLo = 2819026944U;
  c1_info[42].fileTimeHi = 30108061U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[43].name = "mtimes";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[43].fileTimeLo = 529702400U;
  c1_info[43].fileTimeHi = 30114350U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[44].name = "eml_matlab_zlarf";
  c1_info[44].dominantType = "int32";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[44].fileTimeLo = 2879026944U;
  c1_info[44].fileTimeHi = 30108061U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[45].name = "isequal";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[45].fileTimeLo = 2239026944U;
  c1_info[45].fileTimeHi = 30108061U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[46].name = "eml_isequal_core";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[46].fileTimeLo = 2519026944U;
  c1_info[46].fileTimeHi = 30108061U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[47].name = "eml_xgemv";
  c1_info[47].dominantType = "int32";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  c1_info[47].fileTimeLo = 1759026944U;
  c1_info[47].fileTimeHi = 30108061U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c1_info[48].name = "eml_refblas_xgemv";
  c1_info[48].dominantType = "int32";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[48].fileTimeLo = 2479026944U;
  c1_info[48].fileTimeHi = 30108061U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[49].name = "eml_conjtimes";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  c1_info[49].fileTimeLo = 1619026944U;
  c1_info[49].fileTimeHi = 30108061U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[50].name = "eml_xgerc";
  c1_info[50].dominantType = "int32";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[50].fileTimeLo = 1759026944U;
  c1_info[50].fileTimeHi = 30108061U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[51].name = "eml_xger";
  c1_info[51].dominantType = "int32";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[51].fileTimeLo = 1759026944U;
  c1_info[51].fileTimeHi = 30108061U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[52].name = "eml_refblas_xger";
  c1_info[52].dominantType = "int32";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[52].fileTimeLo = 2479026944U;
  c1_info[52].fileTimeHi = 30108061U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[53].name = "eml_refblas_xgerx";
  c1_info[53].dominantType = "int32";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[53].fileTimeLo = 2519026944U;
  c1_info[53].fileTimeHi = 30108061U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[54].name = "max";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[54].fileTimeLo = 1599026944U;
  c1_info[54].fileTimeHi = 30108061U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[55].name = "eml_flt2str";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[55].fileTimeLo = 2419026944U;
  c1_info[55].fileTimeHi = 30108061U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[56].name = "eml_warning";
  c1_info[56].dominantType = "char";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[56].fileTimeLo = 2679026944U;
  c1_info[56].fileTimeHi = 30108061U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
}

static void c1_mldivide(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_A[44], real_T c1_B[121], real_T c1_Y[44])
{
  int32_T c1_i34;
  real_T c1_b_A[44];
  int32_T c1_i35;
  real_T c1_b_B[121];
  int32_T c1_i36;
  int32_T c1_jpvt[4];
  int32_T c1_i37;
  real_T c1_work[4];
  real_T c1_TOL3Z;
  int32_T c1_k;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_i38;
  real_T c1_c_A[44];
  real_T c1_vn1[4];
  real_T c1_vn2[4];
  int32_T c1_a;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_b_a;
  int32_T c1_im1;
  int32_T c1_c_a;
  int32_T c1_ip1;
  int32_T c1_d_a;
  int32_T c1_c;
  int32_T c1_e_a;
  int32_T c1_b;
  int32_T c1_i_i;
  int32_T c1_b_b;
  int32_T c1_nmi;
  int32_T c1_c_b;
  int32_T c1_mmi;
  int32_T c1_d_b;
  int32_T c1_mmip1;
  int32_T c1_e_b;
  int32_T c1_nmip1;
  int32_T c1_f_a;
  int32_T c1_i39;
  real_T c1_b_vn1[4];
  int32_T c1_f_b;
  int32_T c1_pvt;
  int32_T c1_g_a;
  int32_T c1_b_c;
  int32_T c1_g_b;
  int32_T c1_c_c;
  int32_T c1_h_b;
  int32_T c1_pvtcol;
  int32_T c1_i_b;
  int32_T c1_d_c;
  int32_T c1_j_b;
  int32_T c1_mcol;
  int32_T c1_itemp;
  real_T c1_atmp;
  int32_T c1_h_a;
  int32_T c1_e_c;
  int32_T c1_n;
  real_T c1_alpha1;
  int32_T c1_ix0;
  real_T c1_b_atmp;
  real_T c1_d1;
  int32_T c1_q0;
  int32_T c1_q1;
  int32_T c1_qY;
  int32_T c1_nm1;
  int32_T c1_i40;
  real_T c1_d_A[44];
  real_T c1_xnorm;
  real_T c1_beta1;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_y;
  int32_T c1_knt;
  int32_T c1_i_a;
  real_T c1_j_a;
  real_T c1_k_a;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_y;
  int32_T c1_i41;
  real_T c1_e_A[44];
  real_T c1_e_x;
  real_T c1_c_y;
  real_T c1_f_x;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_f_y;
  int32_T c1_b_k;
  real_T c1_l_a;
  real_T c1_g_x;
  real_T c1_g_y;
  real_T c1_h_x;
  real_T c1_h_y;
  real_T c1_i_y;
  real_T c1_j_y;
  real_T c1_tau[4];
  real_T c1_c_atmp;
  real_T c1_d2;
  real_T c1_d3;
  int32_T c1_m_a;
  int32_T c1_f_c;
  int32_T c1_n_a;
  int32_T c1_k_b;
  int32_T c1_i_ip1;
  int32_T c1_b_ip1;
  int32_T c1_c_j;
  int32_T c1_o_a;
  int32_T c1_g_c;
  int32_T c1_l_b;
  int32_T c1_h_c;
  int32_T c1_p_a;
  int32_T c1_m_b;
  int32_T c1_i_j;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_y;
  real_T c1_temp1;
  real_T c1_q_a;
  real_T c1_n_b;
  real_T c1_l_y;
  real_T c1_temp2;
  real_T c1_r_a;
  real_T c1_o_b;
  real_T c1_m_y;
  real_T c1_s_a;
  real_T c1_p_b;
  int32_T c1_t_a;
  int32_T c1_i_c;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  real_T c1_n_y;
  int32_T c1_i42;
  real_T c1_f_A[44];
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_u_a;
  real_T c1_q_b;
  real_T c1_o_y;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_p_y;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_y;
  real_T c1_r_b;
  real_T c1_r_y;
  real_T c1_v_a;
  real_T c1_tol;
  real_T c1_rankR;
  real_T c1_c_k;
  real_T c1_d_k;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_y;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_t_y;
  real_T c1_u_x;
  int32_T c1_i43;
  static char_T c1_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c1_u[8];
  const mxArray *c1_u_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_x_y = NULL;
  char_T c1_str[14];
  int32_T c1_i44;
  char_T c1_b_str[14];
  int32_T c1_i45;
  real_T c1_d_j;
  real_T c1_e_j;
  real_T c1_tauj;
  real_T c1_e_k;
  real_T c1_wj;
  real_T c1_d4;
  real_T c1_c_i;
  real_T c1_d_i;
  real_T c1_w_a;
  real_T c1_s_b;
  real_T c1_z;
  real_T c1_x_a;
  real_T c1_t_b;
  real_T c1_d5;
  real_T c1_e_i;
  real_T c1_y_a;
  real_T c1_u_b;
  real_T c1_y_y;
  real_T c1_rr;
  real_T c1_f_k;
  real_T c1_f_i;
  real_T c1_b_rr;
  real_T c1_f_j;
  int32_T c1_pj;
  real_T c1_v_x;
  real_T c1_ab_y;
  real_T c1_w_x;
  real_T c1_bb_y;
  real_T c1_b_z;
  real_T c1_loop_ub;
  real_T c1_g_i;
  real_T c1_ab_a;
  real_T c1_v_b;
  real_T c1_cb_y;
  boolean_T exitg1;
  for (c1_i34 = 0; c1_i34 < 44; c1_i34++) {
    c1_b_A[c1_i34] = c1_A[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 121; c1_i35++) {
    c1_b_B[c1_i35] = c1_B[c1_i35];
  }

  c1_eml_scalar_eg(chartInstance);
  for (c1_i36 = 0; c1_i36 < 4; c1_i36++) {
    c1_jpvt[c1_i36] = 1 + c1_i36;
  }

  c1_eml_scalar_eg(chartInstance);
  for (c1_i37 = 0; c1_i37 < 4; c1_i37++) {
    c1_work[c1_i37] = 0.0;
  }

  c1_eps(chartInstance);
  c1_TOL3Z = 2.2204460492503131E-16;
  c1_b_sqrt(chartInstance, &c1_TOL3Z);
  c1_eml_scalar_eg(chartInstance);
  c1_k = 1;
  for (c1_j = 1; c1_j < 5; c1_j++) {
    c1_b_j = c1_j;
    for (c1_i38 = 0; c1_i38 < 44; c1_i38++) {
      c1_c_A[c1_i38] = c1_b_A[c1_i38];
    }

    c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_j), 1, 4, 1, 0) - 1] = c1_eml_xnrm2(chartInstance, c1_c_A,
      c1_k);
    c1_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_j), 1, 4, 1, 0) - 1] = c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) - 1];
    c1_a = c1_k + 11;
    c1_k = c1_a;
  }

  for (c1_i = 1; c1_i < 5; c1_i++) {
    c1_b_i = c1_i;
    c1_b_a = c1_b_i - 1;
    c1_im1 = c1_b_a;
    c1_c_a = c1_b_i;
    c1_ip1 = c1_c_a;
    c1_d_a = c1_im1;
    c1_c = c1_d_a * 11;
    c1_e_a = c1_b_i;
    c1_b = c1_c;
    c1_i_i = c1_e_a + c1_b;
    c1_b_b = c1_b_i - 4;
    c1_nmi = -c1_b_b;
    c1_c_b = c1_b_i - 11;
    c1_mmi = -c1_c_b;
    c1_d_b = c1_mmi + 1;
    c1_mmip1 = c1_d_b;
    c1_e_b = c1_nmi;
    c1_nmip1 = c1_e_b;
    c1_f_a = c1_im1;
    for (c1_i39 = 0; c1_i39 < 4; c1_i39++) {
      c1_b_vn1[c1_i39] = c1_vn1[c1_i39];
    }

    c1_f_b = c1_eml_ixamax(chartInstance, c1_nmip1 + 1, c1_b_vn1, c1_b_i);
    c1_pvt = c1_f_a + c1_f_b;
    if (c1_pvt != c1_b_i) {
      c1_g_a = c1_pvt;
      c1_b_c = c1_g_a;
      c1_g_b = c1_b_c;
      c1_c_c = 11 * (c1_g_b - 1);
      c1_h_b = c1_c_c;
      c1_pvtcol = c1_h_b;
      c1_i_b = c1_im1;
      c1_d_c = 11 * c1_i_b;
      c1_j_b = c1_d_c;
      c1_mcol = c1_j_b;
      c1_b_eml_xswap(chartInstance, c1_b_A, c1_pvtcol + 1, c1_mcol + 1);
      c1_itemp = c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_pvt), 1, 4, 1, 0) - 1];
      c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_pvt), 1, 4, 1, 0) - 1] = c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) - 1];
      c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_i), 1, 4, 1, 0) - 1] = c1_itemp;
      c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_pvt), 1, 4, 1, 0) - 1] = c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) - 1];
      c1_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_pvt), 1, 4, 1, 0) - 1] = c1_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) - 1];
    }

    c1_atmp = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c1_i_i), 1, 44, 1, 0) - 1];
    if (c1_b_i < 11) {
      c1_h_a = c1_i_i;
      c1_e_c = c1_h_a;
      c1_n = c1_mmip1;
      c1_alpha1 = c1_atmp;
      c1_ix0 = c1_e_c + 1;
      c1_b_atmp = c1_alpha1;
      c1_d1 = 0.0;
      if ((real_T)c1_n <= 0.0) {
      } else {
        c1_q0 = c1_n;
        c1_q1 = 1;
        c1_qY = c1_q0 - c1_q1;
        if ((c1_q0 < 0) && ((c1_q1 >= 0) && (c1_qY >= 0))) {
          c1_qY = MIN_int32_T;
        } else {
          if ((c1_q0 >= 0) && ((c1_q1 < 0) && (c1_qY < 0))) {
            c1_qY = MAX_int32_T;
          }
        }

        c1_nm1 = c1_qY;
        for (c1_i40 = 0; c1_i40 < 44; c1_i40++) {
          c1_d_A[c1_i40] = c1_b_A[c1_i40];
        }

        c1_xnorm = c1_b_eml_xnrm2(chartInstance, c1_nm1, c1_d_A, c1_ix0);
        if (c1_xnorm != 0.0) {
          c1_beta1 = c1_eml_dlapy2(chartInstance, c1_b_atmp, c1_xnorm);
          if (c1_b_atmp >= 0.0) {
            c1_beta1 = -c1_beta1;
          }

          c1_x = c1_beta1;
          c1_b_x = c1_x;
          c1_y = muDoubleScalarAbs(c1_b_x);
          if (c1_y < 1.0020841800044864E-292) {
            c1_knt = 0;
            do {
              c1_i_a = c1_knt + 1;
              c1_knt = c1_i_a;
              c1_c_eml_xscal(chartInstance, c1_nm1, 9.9792015476736E+291, c1_b_A,
                             c1_ix0);
              c1_j_a = c1_beta1;
              c1_beta1 = c1_j_a * 9.9792015476736E+291;
              c1_k_a = c1_b_atmp;
              c1_b_atmp = c1_k_a * 9.9792015476736E+291;
              c1_c_x = c1_beta1;
              c1_d_x = c1_c_x;
              c1_b_y = muDoubleScalarAbs(c1_d_x);
            } while (!(c1_b_y >= 1.0020841800044864E-292));

            for (c1_i41 = 0; c1_i41 < 44; c1_i41++) {
              c1_e_A[c1_i41] = c1_b_A[c1_i41];
            }

            c1_xnorm = c1_b_eml_xnrm2(chartInstance, c1_nm1, c1_e_A, c1_ix0);
            c1_beta1 = c1_eml_dlapy2(chartInstance, c1_b_atmp, c1_xnorm);
            if (c1_b_atmp >= 0.0) {
              c1_beta1 = -c1_beta1;
            }

            c1_e_x = c1_beta1 - c1_b_atmp;
            c1_c_y = c1_beta1;
            c1_f_x = c1_e_x;
            c1_d_y = c1_c_y;
            c1_d1 = c1_f_x / c1_d_y;
            c1_e_y = c1_b_atmp - c1_beta1;
            c1_f_y = c1_e_y;
            c1_b_atmp = 1.0 / c1_f_y;
            c1_c_eml_xscal(chartInstance, c1_nm1, c1_b_atmp, c1_b_A, c1_ix0);
            for (c1_b_k = 1; c1_b_k <= c1_knt; c1_b_k++) {
              c1_l_a = c1_beta1;
              c1_beta1 = c1_l_a * 1.0020841800044864E-292;
            }

            c1_b_atmp = c1_beta1;
          } else {
            c1_g_x = c1_beta1 - c1_b_atmp;
            c1_g_y = c1_beta1;
            c1_h_x = c1_g_x;
            c1_h_y = c1_g_y;
            c1_d1 = c1_h_x / c1_h_y;
            c1_i_y = c1_b_atmp - c1_beta1;
            c1_j_y = c1_i_y;
            c1_b_atmp = 1.0 / c1_j_y;
            c1_c_eml_xscal(chartInstance, c1_nm1, c1_b_atmp, c1_b_A, c1_ix0);
            c1_b_atmp = c1_beta1;
          }
        }
      }

      c1_atmp = c1_b_atmp;
      c1_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_i), 1, 4, 1, 0) - 1] = c1_d1;
    } else {
      c1_c_atmp = c1_atmp;
      c1_d2 = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c1_i_i), 1, 44, 1, 0) - 1];
      c1_d3 = c1_b_eml_matlab_zlarfg(chartInstance, &c1_c_atmp, &c1_d2);
      c1_atmp = c1_c_atmp;
      c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_i_i), 1, 44, 1, 0) - 1] = c1_d2;
      c1_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_i), 1, 4, 1, 0) - 1] = c1_d3;
    }

    c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_i_i), 1, 44, 1, 0) - 1] = c1_atmp;
    if (c1_b_i < 4) {
      c1_atmp = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_i_i), 1, 44, 1, 0) - 1];
      c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_i_i), 1, 44, 1, 0) - 1] = 1.0;
      c1_m_a = c1_b_i;
      c1_f_c = c1_m_a * 11;
      c1_n_a = c1_b_i;
      c1_k_b = c1_f_c;
      c1_i_ip1 = c1_n_a + c1_k_b;
      c1_b_eml_matlab_zlarf(chartInstance, c1_mmip1, c1_nmi, c1_i_i,
                            c1_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) - 1], c1_b_A,
                            c1_i_ip1, c1_work);
      c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_i_i), 1, 44, 1, 0) - 1] = c1_atmp;
    }

    c1_b_ip1 = c1_ip1;
    for (c1_c_j = c1_b_ip1 + 1; c1_c_j < 5; c1_c_j++) {
      c1_b_j = c1_c_j;
      c1_o_a = c1_b_j;
      c1_g_c = c1_o_a;
      c1_l_b = c1_g_c;
      c1_h_c = 11 * (c1_l_b - 1);
      c1_p_a = c1_b_i;
      c1_m_b = c1_h_c;
      c1_i_j = c1_p_a + c1_m_b;
      if (c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_j), 1, 4, 1, 0) - 1] != 0.0) {
        c1_i_x = c1_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 11, 1, 0) + 11 *
                         (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 2, 0) - 1)) - 1];
        c1_j_x = c1_i_x;
        c1_k_y = muDoubleScalarAbs(c1_j_x);
        c1_temp1 = c1_k_y / c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) - 1];
        c1_q_a = c1_temp1;
        c1_n_b = c1_temp1;
        c1_l_y = c1_q_a * c1_n_b;
        c1_temp1 = 1.0 - c1_l_y;
        if (c1_temp1 < 0.0) {
          c1_temp1 = 0.0;
        }

        c1_temp2 = c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) - 1] /
          c1_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 4, 1, 0) - 1];
        c1_r_a = c1_temp2;
        c1_o_b = c1_temp2;
        c1_m_y = c1_r_a * c1_o_b;
        c1_s_a = c1_temp1;
        c1_p_b = c1_m_y;
        c1_temp2 = c1_s_a * c1_p_b;
        if (c1_temp2 <= c1_TOL3Z) {
          if (c1_b_i < 11) {
            c1_t_a = c1_i_j;
            c1_i_c = c1_t_a;
            c1_b_n = c1_mmi;
            c1_b_ix0 = c1_i_c;
            c1_c_n = c1_b_n;
            c1_c_ix0 = c1_b_ix0;
            if ((real_T)c1_c_n < 1.0) {
              c1_n_y = 0.0;
            } else {
              for (c1_i42 = 0; c1_i42 < 44; c1_i42++) {
                c1_f_A[c1_i42] = c1_b_A[c1_i42];
              }

              c1_n_y = c1_ceval_xnrm2(chartInstance, c1_c_n, c1_f_A, c1_c_ix0 +
                1, 1);
            }

            c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c1_b_j), 1, 4, 1, 0) - 1] = c1_n_y;
            c1_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c1_b_j), 1, 4, 1, 0) - 1] =
              c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c1_b_j), 1, 4, 1, 0) - 1];
          } else {
            c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c1_b_j), 1, 4, 1, 0) - 1] = 0.0;
            c1_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c1_b_j), 1, 4, 1, 0) - 1] = 0.0;
          }
        } else {
          c1_k_x = c1_temp1;
          c1_l_x = c1_k_x;
          if (c1_l_x < 0.0) {
            c1_eml_error(chartInstance);
          }

          c1_l_x = muDoubleScalarSqrt(c1_l_x);
          c1_u_a = c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 1, 0) - 1];
          c1_q_b = c1_l_x;
          c1_o_y = c1_u_a * c1_q_b;
          c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_j), 1, 4, 1, 0) - 1] = c1_o_y;
        }
      }
    }
  }

  c1_m_x = c1_b_A[0];
  c1_n_x = c1_m_x;
  c1_p_y = muDoubleScalarAbs(c1_n_x);
  c1_o_x = 0.0;
  c1_p_x = c1_o_x;
  c1_q_y = muDoubleScalarAbs(c1_p_x);
  c1_r_b = c1_p_y + c1_q_y;
  c1_r_y = 11.0 * c1_r_b;
  c1_v_a = c1_r_y;
  c1_tol = c1_v_a * 2.2204460492503131E-16;
  c1_rankR = 0.0;
  c1_c_k = 1.0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c1_c_k <= 4.0)) {
    c1_d_k = c1_c_k;
    c1_q_x = c1_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c1_d_k), 1, 11, 1, 0) + 11 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_d_k), 1, 4, 2, 0) - 1)) - 1];
    c1_r_x = c1_q_x;
    c1_s_y = muDoubleScalarAbs(c1_r_x);
    c1_s_x = 0.0;
    c1_t_x = c1_s_x;
    c1_t_y = muDoubleScalarAbs(c1_t_x);
    if (c1_s_y + c1_t_y <= c1_tol) {
      c1_u_x = c1_tol;
      for (c1_i43 = 0; c1_i43 < 8; c1_i43++) {
        c1_u[c1_i43] = c1_cv0[c1_i43];
      }

      c1_u_y = NULL;
      sf_mex_assign(&c1_u_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 8));
      c1_b_u = 14.0;
      c1_v_y = NULL;
      sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
      c1_c_u = 6.0;
      c1_w_y = NULL;
      sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0));
      c1_d_u = c1_u_x;
      c1_x_y = NULL;
      sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0));
      c1_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c1_u_y, 14, c1_v_y, 14,
        c1_w_y), 14, c1_x_y), "sprintf", c1_str);
      for (c1_i44 = 0; c1_i44 < 14; c1_i44++) {
        c1_b_str[c1_i44] = c1_str[c1_i44];
      }

      c1_eml_warning(chartInstance, c1_rankR, c1_b_str);
      exitg1 = 1U;
    } else {
      c1_rankR++;
      c1_c_k++;
    }
  }

  for (c1_i45 = 0; c1_i45 < 44; c1_i45++) {
    c1_Y[c1_i45] = 0.0;
  }

  for (c1_d_j = 1.0; c1_d_j <= 4.0; c1_d_j++) {
    c1_e_j = c1_d_j;
    c1_tauj = c1_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", c1_e_j), 1, 4, 1, 0) - 1];
    if (c1_tauj != 0.0) {
      for (c1_e_k = 1.0; c1_e_k <= 11.0; c1_e_k++) {
        c1_d_k = c1_e_k;
        c1_wj = c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_e_j), 1, 11, 1, 0) + 11 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1)) - 1];
        c1_d4 = c1_e_j + 1.0;
        for (c1_c_i = c1_d4; c1_c_i <= 11.0; c1_c_i++) {
          c1_d_i = c1_c_i;
          c1_w_a = c1_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_d_i), 1, 11, 1, 0) + 11 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_e_j), 1, 4, 2, 0) - 1)) - 1];
          c1_s_b = c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_d_i), 1, 11, 1, 0) + 11 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1)) - 1];
          c1_z = c1_w_a * c1_s_b;
          c1_wj += c1_z;
        }

        c1_x_a = c1_tauj;
        c1_t_b = c1_wj;
        c1_wj = c1_x_a * c1_t_b;
        if (c1_wj != 0.0) {
          c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    c1_e_j), 1, 11, 1, 0) + 11 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1))
            - 1] = c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_e_j), 1, 11, 1, 0) + 11 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1)) - 1] - c1_wj;
          c1_d5 = c1_e_j + 1.0;
          for (c1_e_i = c1_d5; c1_e_i <= 11.0; c1_e_i++) {
            c1_d_i = c1_e_i;
            c1_y_a = c1_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", c1_d_i), 1, 11, 1, 0) + 11 *
                             (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", c1_e_j), 1, 4, 2, 0) - 1)) - 1];
            c1_u_b = c1_wj;
            c1_y_y = c1_y_a * c1_u_b;
            c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", c1_d_i), 1, 11, 1, 0) + 11 *
                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c1_d_k), 1, 11, 2, 0) - 1)) - 1] = c1_b_B
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c1_d_i), 1, 11, 1, 0) + 11 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1)) -
              1] - c1_y_y;
          }
        }
      }
    }
  }

  c1_rr = c1_rankR;
  for (c1_f_k = 1.0; c1_f_k <= 11.0; c1_f_k++) {
    c1_d_k = c1_f_k;
    for (c1_f_i = 1.0; c1_f_i <= c1_rr; c1_f_i++) {
      c1_d_i = c1_f_i;
      c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", c1_d_i), 1, 4, 1, 0) - 1]), 1, 4, 1, 0) +
            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c1_d_k), 1, 11, 2, 0) - 1) << 2)) - 1] = c1_b_B
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_d_i),
           1, 11, 1, 0) + 11 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1)) - 1];
    }

    c1_b_rr = c1_rr;
    for (c1_f_j = c1_b_rr; c1_f_j >= 1.0; c1_f_j += -1.0) {
      c1_e_j = c1_f_j;
      c1_pj = c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_e_j), 1, 4, 1, 0) - 1];
      c1_v_x = c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c1_pj), 1, 4, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1) << 2)) - 1];
      c1_ab_y = c1_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_e_j), 1, 11, 1, 0) + 11 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_e_j), 1, 4, 2, 0) - 1)) - 1];
      c1_w_x = c1_v_x;
      c1_bb_y = c1_ab_y;
      c1_b_z = c1_w_x / c1_bb_y;
      c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_pj), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1) << 2))
        - 1] = c1_b_z;
      c1_loop_ub = c1_e_j - 1.0;
      for (c1_g_i = 1.0; c1_g_i <= c1_loop_ub; c1_g_i++) {
        c1_d_i = c1_g_i;
        c1_ab_a = c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_pj), 1, 4, 1, 0) +
                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_d_k), 1, 11, 2, 0) - 1) << 2)) - 1];
        c1_v_b = c1_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_d_i), 1, 11, 1, 0) + 11 *
                         (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_e_j), 1, 4, 2, 0) - 1)) - 1];
        c1_cb_y = c1_ab_a * c1_v_b;
        c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                 _SFD_INTEGER_CHECK("", c1_d_i), 1, 4, 1, 0) - 1]), 1, 4, 1, 0)
              + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  c1_d_k), 1, 11, 2, 0) - 1) << 2)) - 1] = c1_Y
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", c1_d_i), 1, 4, 1, 0) - 1]), 1, 4, 1, 0) +
            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c1_d_k), 1, 11, 2, 0) - 1) << 2)) - 1] - c1_cb_y;
      }
    }
  }
}

static void c1_eml_scalar_eg(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance)
{
}

static void c1_eps(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance)
{
}

static real_T c1_sqrt(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
                      *chartInstance, real_T c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_eml_error(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance)
{
  int32_T c1_i46;
  static char_T c1_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  for (c1_i46 = 0; c1_i46 < 30; c1_i46++) {
    c1_u[c1_i46] = c1_varargin_1[c1_i46];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static real_T c1_eml_xnrm2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x[44], int32_T c1_ix0)
{
  int32_T c1_b_ix0;
  int32_T c1_i47;
  real_T c1_b_x[44];
  c1_b_ix0 = c1_ix0;
  for (c1_i47 = 0; c1_i47 < 44; c1_i47++) {
    c1_b_x[c1_i47] = c1_x[c1_i47];
  }

  return c1_ceval_xnrm2(chartInstance, 11, c1_b_x, c1_b_ix0, 1);
}

static real_T c1_ceval_xnrm2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0, int32_T c1_incx)
{
  return dnrm232(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 44, 1, 0) - 1], &c1_incx);
}

static int32_T c1_eml_ixamax(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[4], int32_T c1_ix0)
{
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_i48;
  real_T c1_b_x[4];
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    c1_b_x[c1_i48] = c1_x[c1_i48];
  }

  return c1_ceval_ixamax(chartInstance, c1_b_n, c1_b_x, c1_b_ix0, 1);
}

static int32_T c1_ceval_ixamax(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[4], int32_T c1_ix0, int32_T c1_incx)
{
  return idamax32(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 4, 1, 0) - 1], &c1_incx);
}

static void c1_eml_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x[44], int32_T c1_ix0, int32_T c1_iy0, real_T
  c1_b_x[44])
{
  int32_T c1_i49;
  for (c1_i49 = 0; c1_i49 < 44; c1_i49++) {
    c1_b_x[c1_i49] = c1_x[c1_i49];
  }

  c1_b_eml_xswap(chartInstance, c1_b_x, c1_ix0, c1_iy0);
}

static void c1_ceval_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0, int32_T c1_incx,
  int32_T c1_iy0, int32_T c1_incy, real_T c1_b_x[44])
{
  int32_T c1_i50;
  for (c1_i50 = 0; c1_i50 < 44; c1_i50++) {
    c1_b_x[c1_i50] = c1_x[c1_i50];
  }

  c1_b_ceval_xswap(chartInstance, c1_n, c1_b_x, c1_ix0, c1_incx, c1_iy0, c1_incy);
}

static real_T c1_b_eml_xnrm2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0)
{
  real_T c1_y;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_i51;
  real_T c1_b_x[44];
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  if ((real_T)c1_b_n < 1.0) {
    c1_y = 0.0;
  } else {
    for (c1_i51 = 0; c1_i51 < 44; c1_i51++) {
      c1_b_x[c1_i51] = c1_x[c1_i51];
    }

    c1_y = c1_ceval_xnrm2(chartInstance, c1_b_n, c1_b_x, c1_b_ix0, 1);
  }

  return c1_y;
}

static real_T c1_eml_dlapy2(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x1, real_T c1_x2)
{
  real_T c1_y;
  real_T c1_a;
  real_T c1_b;
  real_T c1_x;
  boolean_T c1_b_b;
  c1_a = muDoubleScalarAbs(c1_x1);
  c1_b = muDoubleScalarAbs(c1_x2);
  if (c1_a < c1_b) {
    c1_a /= c1_b;
    c1_y = muDoubleScalarSqrt(c1_a * c1_a + 1.0) * c1_b;
  } else if (c1_a > c1_b) {
    c1_b /= c1_a;
    c1_y = muDoubleScalarSqrt(c1_b * c1_b + 1.0) * c1_a;
  } else {
    c1_x = c1_b;
    c1_b_b = muDoubleScalarIsNaN(c1_x);
    if (c1_b_b) {
      c1_y = c1_b;
    } else {
      c1_y = c1_a * 1.4142135623730951;
    }
  }

  return c1_y;
}

static void c1_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0,
  real_T c1_b_x[44])
{
  int32_T c1_i52;
  for (c1_i52 = 0; c1_i52 < 44; c1_i52++) {
    c1_b_x[c1_i52] = c1_x[c1_i52];
  }

  c1_c_eml_xscal(chartInstance, c1_n, c1_a, c1_b_x, c1_ix0);
}

static void c1_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0,
  int32_T c1_incx, real_T c1_b_x[44])
{
  int32_T c1_i53;
  for (c1_i53 = 0; c1_i53 < 44; c1_i53++) {
    c1_b_x[c1_i53] = c1_x[c1_i53];
  }

  c1_c_ceval_xscal(chartInstance, c1_n, c1_a, c1_b_x, c1_ix0, c1_incx);
}

static void c1_eml_matlab_zlarfg(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *
  chartInstance, real_T c1_alpha1, real_T c1_x, real_T *c1_b_alpha1, real_T
  *c1_b_x, real_T *c1_tau)
{
  *c1_b_alpha1 = c1_alpha1;
  *c1_b_x = c1_x;
  *c1_tau = c1_b_eml_matlab_zlarfg(chartInstance, c1_b_alpha1, c1_b_x);
}

static real_T c1_b_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_a, real_T c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_d_eml_xscal(chartInstance, c1_a, &c1_b_x);
  return c1_b_x;
}

static real_T c1_b_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x, int32_T c1_ix0,
  int32_T c1_incx)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_d_ceval_xscal(chartInstance, c1_n, c1_a, &c1_b_x, c1_ix0, c1_incx);
  return c1_b_x;
}

static void c1_eml_matlab_zlarf(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[44], int32_T c1_ic0, real_T c1_work[4], real_T c1_b_C[44], real_T
  c1_b_work[4])
{
  int32_T c1_i54;
  int32_T c1_i55;
  for (c1_i54 = 0; c1_i54 < 44; c1_i54++) {
    c1_b_C[c1_i54] = c1_C[c1_i54];
  }

  for (c1_i55 = 0; c1_i55 < 4; c1_i55++) {
    c1_b_work[c1_i55] = c1_work[c1_i55];
  }

  c1_b_eml_matlab_zlarf(chartInstance, c1_m, c1_n, c1_iv0, c1_tau, c1_b_C,
                        c1_ic0, c1_b_work);
}

static void c1_eml_blas_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[44], int32_T c1_ia0,
  real_T c1_x[44], int32_T c1_ix0, real_T c1_y[4], real_T c1_b_y[4])
{
  int32_T c1_i56;
  int32_T c1_i57;
  real_T c1_b_A[44];
  int32_T c1_i58;
  real_T c1_b_x[44];
  for (c1_i56 = 0; c1_i56 < 4; c1_i56++) {
    c1_b_y[c1_i56] = c1_y[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 44; c1_i57++) {
    c1_b_A[c1_i57] = c1_A[c1_i57];
  }

  for (c1_i58 = 0; c1_i58 < 44; c1_i58++) {
    c1_b_x[c1_i58] = c1_x[c1_i58];
  }

  c1_b_eml_blas_xgemv(chartInstance, c1_m, c1_n, c1_b_A, c1_ia0, c1_b_x, c1_ix0,
                      c1_b_y);
}

static void c1_ceval_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[44],
  int32_T c1_ia0, int32_T c1_lda, real_T c1_x[44], int32_T c1_ix0, int32_T
  c1_incx, real_T c1_beta1, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy,
  real_T c1_b_y[4])
{
  int32_T c1_i59;
  int32_T c1_i60;
  real_T c1_b_A[44];
  int32_T c1_i61;
  real_T c1_b_x[44];
  for (c1_i59 = 0; c1_i59 < 4; c1_i59++) {
    c1_b_y[c1_i59] = c1_y[c1_i59];
  }

  for (c1_i60 = 0; c1_i60 < 44; c1_i60++) {
    c1_b_A[c1_i60] = c1_A[c1_i60];
  }

  for (c1_i61 = 0; c1_i61 < 44; c1_i61++) {
    c1_b_x[c1_i61] = c1_x[c1_i61];
  }

  c1_b_ceval_xgemv(chartInstance, c1_m, c1_n, c1_alpha1, c1_b_A, c1_ia0, c1_lda,
                   c1_b_x, c1_ix0, c1_incx, c1_beta1, c1_b_y, c1_iy0, c1_incy);
}

static void c1_ceval_xger(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_incx, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy, real_T c1_A
  [44], int32_T c1_ia0, int32_T c1_lda, real_T c1_b_A[44])
{
  int32_T c1_i62;
  int32_T c1_i63;
  real_T c1_b_y[4];
  for (c1_i62 = 0; c1_i62 < 44; c1_i62++) {
    c1_b_A[c1_i62] = c1_A[c1_i62];
  }

  for (c1_i63 = 0; c1_i63 < 4; c1_i63++) {
    c1_b_y[c1_i63] = c1_y[c1_i63];
  }

  c1_b_ceval_xger(chartInstance, c1_m, c1_n, c1_alpha1, c1_ix0, c1_incx, c1_b_y,
                  c1_iy0, c1_incy, c1_b_A, c1_ia0, c1_lda);
}

static void c1_eml_warning(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_varargin_2, char_T c1_varargin_3[14])
{
  int32_T c1_i64;
  static char_T c1_varargin_1[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i',
    'e', 'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c1_u[32];
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i65;
  char_T c1_c_u[14];
  const mxArray *c1_c_y = NULL;
  for (c1_i64 = 0; c1_i64 < 32; c1_i64++) {
    c1_u[c1_i64] = c1_varargin_1[c1_i64];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 32));
  c1_b_u = c1_varargin_2;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  for (c1_i65 = 0; c1_i65 < 14; c1_i65++) {
    c1_c_u[c1_i65] = c1_varargin_3[c1_i65];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 14));
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 3U,
    14, c1_y, 14, c1_b_y, 14, c1_c_y));
}

static void c1_d_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sprintf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_sprintf);
}

static void c1_e_emlrt_marshallIn(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14])
{
  char_T c1_cv1[14];
  int32_T c1_i66;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c1_i66 = 0; c1_i66 < 14; c1_i66++) {
    c1_y[c1_i66] = c1_cv1[c1_i66];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i67;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i67, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i67;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_b_is_active_c1_lin_model_PI_MRAC_Sim_CASE2, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_lin_model_PI_MRAC_Sim_CASE2), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_lin_model_PI_MRAC_Sim_CASE2);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sqrt(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
                      *chartInstance, real_T *c1_x)
{
  if (*c1_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarSqrt(*c1_x);
}

static void c1_b_eml_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_x[44], int32_T c1_ix0, int32_T c1_iy0)
{
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  c1_b_ix0 = c1_ix0;
  c1_b_iy0 = c1_iy0;
  c1_b_ceval_xswap(chartInstance, 11, c1_x, c1_b_ix0, 1, c1_b_iy0, 1);
}

static void c1_b_ceval_xswap(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[44], int32_T c1_ix0, int32_T c1_incx,
  int32_T c1_iy0, int32_T c1_incy)
{
  dswap32(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 44, 1, 0) - 1], &c1_incx,
          &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_iy0), 1, 44, 1, 0) - 1], &c1_incy);
}

static void c1_c_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0)
{
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_b_ix0;
  c1_b_n = c1_n;
  c1_b_a = c1_a;
  c1_b_ix0 = c1_ix0;
  c1_c_ceval_xscal(chartInstance, c1_b_n, c1_b_a, c1_x, c1_b_ix0, 1);
}

static void c1_c_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[44], int32_T c1_ix0,
  int32_T c1_incx)
{
  dscal32(&c1_n, &c1_a, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 44, 1, 0) - 1], &c1_incx);
}

static real_T c1_b_eml_matlab_zlarfg
  (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance, real_T
   *c1_alpha1, real_T *c1_x)
{
  return 0.0;
}

static void c1_d_eml_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, real_T c1_a, real_T *c1_x)
{
  real_T c1_b_a;
  c1_b_a = c1_a;
  c1_d_ceval_xscal(chartInstance, 0, c1_b_a, c1_x, 1, 1);
}

static void c1_d_ceval_xscal(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T *c1_x, int32_T c1_ix0,
  int32_T c1_incx)
{
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ix0),
    1, 1, 1, 0);
  dscal32(&c1_n, &c1_a, c1_x, &c1_incx);
}

static void c1_b_eml_matlab_zlarf(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[44], int32_T c1_ic0, real_T c1_work[4])
{
  int32_T c1_lastv;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_a;
  int32_T c1_b_b;
  int32_T c1_i;
  int32_T c1_c_a;
  int32_T c1_d_a;
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_ia0;
  int32_T c1_lastc;
  int32_T c1_e_a;
  int32_T c1_c_c;
  int32_T c1_f_a;
  int32_T c1_d_c;
  int32_T c1_g_a;
  int32_T c1_c_b;
  int32_T c1_coltop;
  int32_T c1_h_a;
  int32_T c1_e_c;
  int32_T c1_i_a;
  int32_T c1_d_b;
  int32_T c1_colbottom;
  int32_T c1_b_coltop;
  int32_T c1_ia;
  int32_T c1_b_ia;
  int32_T c1_j_a;
  int32_T c1_c_m;
  int32_T c1_c_n;
  int32_T c1_b_ia0;
  int32_T c1_ix0;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  real_T c1_b_C[44];
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  real_T c1_c_C[44];
  int32_T c1_d_m;
  int32_T c1_d_n;
  real_T c1_alpha1;
  int32_T c1_b_ix0;
  int32_T c1_c_ia0;
  int32_T c1_e_m;
  int32_T c1_e_n;
  real_T c1_b_alpha1;
  int32_T c1_c_ix0;
  int32_T c1_d_ia0;
  int32_T c1_f_m;
  int32_T c1_f_n;
  real_T c1_c_alpha1;
  int32_T c1_d_ix0;
  int32_T c1_e_ia0;
  int32_T c1_i74;
  real_T c1_b_work[4];
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  if (c1_tau != 0.0) {
    c1_lastv = c1_m;
    c1_a = c1_lastv;
    c1_c = c1_a;
    c1_b = c1_c;
    c1_b_c = c1_b - 1;
    c1_b_a = c1_iv0;
    c1_b_b = c1_b_c;
    c1_i = c1_b_a + c1_b_b;
    exitg3 = 0U;
    while ((exitg3 == 0U) && (c1_lastv > 0)) {
      if (c1_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_i), 1, 44, 1, 0) - 1] == 0.0) {
        c1_c_a = c1_lastv - 1;
        c1_lastv = c1_c_a;
        c1_d_a = c1_i - 1;
        c1_i = c1_d_a;
      } else {
        exitg3 = 1U;
      }
    }

    c1_b_m = c1_lastv;
    c1_b_n = c1_n;
    c1_ia0 = c1_ic0;
    c1_lastc = c1_b_n;
    exitg2 = 0U;
    while ((exitg2 == 0U) && ((real_T)c1_lastc > 0.0)) {
      c1_e_a = c1_lastc;
      c1_c_c = c1_e_a;
      c1_f_a = c1_c_c;
      c1_d_c = (c1_f_a - 1) * 11;
      c1_g_a = c1_ia0;
      c1_c_b = c1_d_c;
      c1_coltop = c1_g_a + c1_c_b;
      c1_h_a = c1_b_m;
      c1_e_c = c1_h_a;
      c1_i_a = c1_coltop;
      c1_d_b = c1_e_c;
      c1_colbottom = (c1_i_a + c1_d_b) - 1;
      c1_b_coltop = c1_coltop;
      c1_ia = c1_b_coltop;
      do {
        exitg1 = 0U;
        if (c1_ia <= c1_colbottom) {
          c1_b_ia = c1_ia;
          if (c1_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c1_b_ia), 1, 44, 1, 0) - 1] != 0.0) {
            exitg1 = 1U;
          } else {
            c1_ia++;
          }
        } else {
          c1_j_a = c1_lastc - 1;
          c1_lastc = c1_j_a;
          exitg1 = 2U;
        }
      } while (exitg1 == 0U);

      if (exitg1 == 1U) {
        exitg2 = 1U;
      }
    }
  } else {
    c1_lastv = 0;
    c1_lastc = 0;
  }

  if (c1_lastv > 0) {
    c1_c_m = c1_lastv;
    c1_c_n = c1_lastc;
    c1_b_ia0 = c1_ic0;
    c1_ix0 = c1_iv0;
    c1_i68 = 0;
    for (c1_i69 = 0; c1_i69 < 4; c1_i69++) {
      for (c1_i70 = 0; c1_i70 < 11; c1_i70++) {
        c1_b_C[c1_i70 + c1_i68] = c1_C[c1_i70 + c1_i68];
      }

      c1_i68 += 11;
    }

    c1_i71 = 0;
    for (c1_i72 = 0; c1_i72 < 4; c1_i72++) {
      for (c1_i73 = 0; c1_i73 < 11; c1_i73++) {
        c1_c_C[c1_i73 + c1_i71] = c1_C[c1_i73 + c1_i71];
      }

      c1_i71 += 11;
    }

    c1_b_eml_blas_xgemv(chartInstance, c1_c_m, c1_c_n, c1_b_C, c1_b_ia0, c1_c_C,
                        c1_ix0, c1_work);
    c1_d_m = c1_lastv;
    c1_d_n = c1_lastc;
    c1_alpha1 = -c1_tau;
    c1_b_ix0 = c1_iv0;
    c1_c_ia0 = c1_ic0;
    c1_e_m = c1_d_m;
    c1_e_n = c1_d_n;
    c1_b_alpha1 = c1_alpha1;
    c1_c_ix0 = c1_b_ix0;
    c1_d_ia0 = c1_c_ia0;
    c1_f_m = c1_e_m;
    c1_f_n = c1_e_n;
    c1_c_alpha1 = c1_b_alpha1;
    c1_d_ix0 = c1_c_ix0;
    c1_e_ia0 = c1_d_ia0;
    if ((real_T)c1_f_m < 1.0) {
    } else if ((real_T)c1_f_n < 1.0) {
    } else {
      for (c1_i74 = 0; c1_i74 < 4; c1_i74++) {
        c1_b_work[c1_i74] = c1_work[c1_i74];
      }

      c1_b_ceval_xger(chartInstance, c1_f_m, c1_f_n, c1_c_alpha1, c1_d_ix0, 1,
                      c1_b_work, 1, 1, c1_C, c1_e_ia0, 11);
    }
  }
}

static void c1_b_eml_blas_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[44], int32_T c1_ia0,
  real_T c1_x[44], int32_T c1_ix0, real_T c1_y[4])
{
  int32_T c1_i75;
  real_T c1_b_A[44];
  int32_T c1_i76;
  real_T c1_b_x[44];
  for (c1_i75 = 0; c1_i75 < 44; c1_i75++) {
    c1_b_A[c1_i75] = c1_A[c1_i75];
  }

  for (c1_i76 = 0; c1_i76 < 44; c1_i76++) {
    c1_b_x[c1_i76] = c1_x[c1_i76];
  }

  c1_b_ceval_xgemv(chartInstance, c1_m, c1_n, 1.0, c1_b_A, c1_ia0, 11, c1_b_x,
                   c1_ix0, 1, 0.0, c1_y, 1, 1);
}

static void c1_b_ceval_xgemv(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[44],
  int32_T c1_ia0, int32_T c1_lda, real_T c1_x[44], int32_T c1_ix0, int32_T
  c1_incx, real_T c1_beta1, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy)
{
  char_T c1_TRANSA;
  c1_TRANSA = 'C';
  dgemv32(&c1_TRANSA, &c1_m, &c1_n, &c1_alpha1,
          &c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_ia0), 1, 44, 1, 0) - 1], &c1_lda,
          &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_ix0), 1, 44, 1, 0) - 1], &c1_incx, &c1_beta1,
          &c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_iy0), 1, 4, 1, 0) - 1], &c1_incy);
}

static void c1_b_ceval_xger(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_incx, real_T c1_y[4], int32_T c1_iy0, int32_T c1_incy, real_T c1_A
  [44], int32_T c1_ia0, int32_T c1_lda)
{
  dger32(&c1_m, &c1_n, &c1_alpha1, &c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 44, 1, 0) - 1],
         &c1_incx, &c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_iy0), 1, 4, 1, 0) - 1], &c1_incy,
         &c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
           (real_T)c1_ia0), 1, 44, 1, 0) - 1], &c1_lda);
}

static void init_dsm_address_info(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_lin_model_PI_MRAC_Sim_CASE2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(827464428U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3879834168U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(56785382U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(929228629U);
}

mxArray *sf_c1_lin_model_PI_MRAC_Sim_CASE2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3108510928U);
    pr[1] = (double)(873894205U);
    pr[2] = (double)(3528656171U);
    pr[3] = (double)(2667430942U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(11);
      pr[1] = (double)(4);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(11);
      pr[1] = (double)(11);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(11);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_lin_model_PI_MRAC_Sim_CASE2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_lin_model_PI_MRAC_Sim_CASE2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_lin_model_PI_MRAC_Sim_CASE2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
    chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lin_model_PI_MRAC_Sim_CASE2MachineNumber_,
           1,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_lin_model_PI_MRAC_Sim_CASE2MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_lin_model_PI_MRAC_Sim_CASE2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_lin_model_PI_MRAC_Sim_CASE2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"b");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"A");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,51);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 11;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 11;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c1_b)[44];
          real_T (*c1_y)[44];
          real_T (*c1_A)[121];
          c1_A = (real_T (*)[121])ssGetInputPortSignal(chartInstance->S, 1);
          c1_y = (real_T (*)[44])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_b = (real_T (*)[44])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_b);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_A);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_lin_model_PI_MRAC_Sim_CASE2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_lin_model_PI_MRAC_Sim_CASE2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*) chartInstanceVar);
  initialize_c1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_lin_model_PI_MRAC_Sim_CASE2(void
  *chartInstanceVar)
{
  enable_c1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_lin_model_PI_MRAC_Sim_CASE2(void
  *chartInstanceVar)
{
  disable_c1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_lin_model_PI_MRAC_Sim_CASE2(void
  *chartInstanceVar)
{
  sf_c1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_lin_model_PI_MRAC_Sim_CASE2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_lin_model_PI_MRAC_Sim_CASE2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2(S);
}

static void sf_opaque_set_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2(S, st);
}

static void sf_opaque_terminate_c1_lin_model_PI_MRAC_Sim_CASE2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_lin_model_PI_MRAC_Sim_CASE2
      ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_lin_model_PI_MRAC_Sim_CASE2
    ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_lin_model_PI_MRAC_Sim_CASE2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_lin_model_PI_MRAC_Sim_CASE2
      ((SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_lin_model_PI_MRAC_Sim_CASE2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"lin_model_PI_MRAC_Sim_CASE2",
      "lin_model_PI_MRAC_Sim_CASE2",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"lin_model_PI_MRAC_Sim_CASE2",
                "lin_model_PI_MRAC_Sim_CASE2",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "lin_model_PI_MRAC_Sim_CASE2","lin_model_PI_MRAC_Sim_CASE2",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"lin_model_PI_MRAC_Sim_CASE2",
        "lin_model_PI_MRAC_Sim_CASE2",1,2);
      sf_mark_chart_reusable_outputs(S,"lin_model_PI_MRAC_Sim_CASE2",
        "lin_model_PI_MRAC_Sim_CASE2",1,1);
    }

    sf_set_rtw_dwork_info(S,"lin_model_PI_MRAC_Sim_CASE2",
                          "lin_model_PI_MRAC_Sim_CASE2",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(587894503U));
  ssSetChecksum1(S,(3861792502U));
  ssSetChecksum2(S,(1762284772U));
  ssSetChecksum3(S,(2459731576U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_lin_model_PI_MRAC_Sim_CASE2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "lin_model_PI_MRAC_Sim_CASE2",
      "lin_model_PI_MRAC_Sim_CASE2",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_lin_model_PI_MRAC_Sim_CASE2(SimStruct *S)
{
  SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *chartInstance;
  chartInstance = (SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct *)malloc
    (sizeof(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_lin_model_PI_MRAC_Sim_CASE2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_lin_model_PI_MRAC_Sim_CASE2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_lin_model_PI_MRAC_Sim_CASE2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_lin_model_PI_MRAC_Sim_CASE2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_lin_model_PI_MRAC_Sim_CASE2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_lin_model_PI_MRAC_Sim_CASE2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_lin_model_PI_MRAC_Sim_CASE2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
