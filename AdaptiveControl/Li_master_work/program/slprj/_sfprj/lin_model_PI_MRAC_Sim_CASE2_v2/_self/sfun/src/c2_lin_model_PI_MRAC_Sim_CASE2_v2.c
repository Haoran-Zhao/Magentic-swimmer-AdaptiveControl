/* Include files */

#include "blascompat32.h"
#include "lin_model_PI_MRAC_Sim_CASE2_v2_sfun.h"
#include "c2_lin_model_PI_MRAC_Sim_CASE2_v2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lin_model_PI_MRAC_Sim_CASE2_v2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[5] = { "nargin", "nargout", "U", "V",
  "y" };

/* Function Declarations */
static void initialize_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void initialize_params_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void enable_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void disable_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void set_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void initSimStructsc2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_y, const char_T *c2_identifier, real_T c2_b_y[4]);
static void c2_b_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[57]);
static void c2_mldivide(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_A[44], real_T c2_B[11], real_T c2_Y[4]);
static void c2_eml_scalar_eg(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance);
static void c2_eps(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
                   *chartInstance);
static real_T c2_sqrt(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
                      *chartInstance, real_T c2_x);
static void c2_eml_error(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance);
static real_T c2_eml_xnrm2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x[44], int32_T c2_ix0);
static real_T c2_ceval_xnrm2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0, int32_T c2_incx);
static int32_T c2_eml_ixamax(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[4], int32_T c2_ix0);
static int32_T c2_ceval_ixamax(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[4], int32_T c2_ix0, int32_T c2_incx);
static void c2_eml_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x[44], int32_T c2_ix0, int32_T c2_iy0, real_T
  c2_b_x[44]);
static void c2_ceval_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[44]);
static real_T c2_b_eml_xnrm2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0);
static real_T c2_eml_dlapy2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x1, real_T c2_x2);
static void c2_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0,
  real_T c2_b_x[44]);
static void c2_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0,
  int32_T c2_incx, real_T c2_b_x[44]);
static void c2_eml_matlab_zlarfg
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, real_T
   c2_alpha1, real_T c2_x, real_T *c2_b_alpha1, real_T *c2_b_x, real_T *c2_tau);
static real_T c2_b_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_a, real_T c2_x);
static real_T c2_b_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x, int32_T c2_ix0,
  int32_T c2_incx);
static void c2_eml_matlab_zlarf
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, int32_T
   c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[44], int32_T
   c2_ic0, real_T c2_work[4], real_T c2_b_C[44], real_T c2_b_work[4]);
static void c2_eml_blas_xgemv(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *
  chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_A[44], int32_T c2_ia0,
  real_T c2_x[44], int32_T c2_ix0, real_T c2_y[4], real_T c2_b_y[4]);
static void c2_ceval_xgemv(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[44],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_x[44], int32_T c2_ix0, int32_T
  c2_incx, real_T c2_beta1, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy,
  real_T c2_b_y[4]);
static void c2_ceval_xger(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy, real_T c2_A
  [44], int32_T c2_ia0, int32_T c2_lda, real_T c2_b_A[44]);
static void c2_eml_warning(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_varargin_2, char_T c2_varargin_3[14]);
static void c2_d_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y[14]);
static void c2_e_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, char_T c2_y[14]);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2, const char_T
   *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
                      *chartInstance, real_T *c2_x);
static void c2_b_eml_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x[44], int32_T c2_ix0, int32_T c2_iy0);
static void c2_b_ceval_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy);
static void c2_c_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0);
static void c2_c_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0,
  int32_T c2_incx);
static real_T c2_b_eml_matlab_zlarfg
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, real_T
   *c2_alpha1, real_T *c2_x);
static void c2_d_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_a, real_T *c2_x);
static void c2_d_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T *c2_x, int32_T c2_ix0,
  int32_T c2_incx);
static void c2_b_eml_matlab_zlarf
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, int32_T
   c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[44], int32_T
   c2_ic0, real_T c2_work[4]);
static void c2_b_eml_blas_xgemv
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, int32_T
   c2_m, int32_T c2_n, real_T c2_A[44], int32_T c2_ia0, real_T c2_x[44], int32_T
   c2_ix0, real_T c2_y[4]);
static void c2_b_ceval_xgemv(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[44],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_x[44], int32_T c2_ix0, int32_T
  c2_incx, real_T c2_beta1, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy);
static void c2_b_ceval_xger(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy, real_T c2_A
  [44], int32_T c2_ia0, int32_T c2_lda);
static void init_dsm_address_info
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2 = 0U;
}

static void initialize_params_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
}

static void enable_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[4];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_d_y)[4];
  c2_d_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    c2_u[c2_i0] = (*c2_d_y)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal =
    chartInstance->c2_is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[4];
  int32_T c2_i1;
  real_T (*c2_y)[4];
  c2_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    (*c2_y)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2 =
    c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
}

static void sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  real_T c2_U[44];
  int32_T c2_i6;
  real_T c2_V[11];
  uint32_T c2_debug_family_var_map[5];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_y[4];
  int32_T c2_i7;
  real_T c2_b_U[44];
  int32_T c2_i8;
  real_T c2_b_V[11];
  real_T c2_dv1[4];
  int32_T c2_i9;
  int32_T c2_i10;
  real_T (*c2_b_y)[4];
  real_T (*c2_c_V)[11];
  real_T (*c2_c_U)[44];
  c2_c_V = (real_T (*)[11])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_c_U = (real_T (*)[44])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 44; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_U)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_y)[c2_i3], 1U);
  }

  for (c2_i4 = 0; c2_i4 < 11; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_V)[c2_i4], 2U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i5 = 0; c2_i5 < 44; c2_i5++) {
    c2_U[c2_i5] = (*c2_c_U)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 11; c2_i6++) {
    c2_V[c2_i6] = (*c2_c_V)[c2_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_U, 2U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_V, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_y, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i7 = 0; c2_i7 < 44; c2_i7++) {
    c2_b_U[c2_i7] = c2_U[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 11; c2_i8++) {
    c2_b_V[c2_i8] = c2_V[c2_i8];
  }

  c2_mldivide(chartInstance, c2_b_U, c2_b_V, c2_dv1);
  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    c2_y[c2_i9] = c2_dv1[c2_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    (*c2_b_y)[c2_i10] = c2_y[c2_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i11;
  real_T c2_b_inData[4];
  int32_T c2_i12;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
    c2_b_inData[c2_i11] = (*(real_T (*)[4])c2_inData)[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    c2_u[c2_i12] = c2_b_inData[c2_i12];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_y, const char_T *c2_identifier, real_T c2_b_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv2[4];
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_y[c2_i13] = c2_dv2[c2_i13];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[4];
  int32_T c2_i14;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
    (*(real_T (*)[4])c2_outData)[c2_i14] = c2_b_y[c2_i14];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  real_T c2_b_inData[11];
  int32_T c2_i16;
  real_T c2_u[11];
  const mxArray *c2_y = NULL;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i15 = 0; c2_i15 < 11; c2_i15++) {
    c2_b_inData[c2_i15] = (*(real_T (*)[11])c2_inData)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 11; c2_i16++) {
    c2_u[c2_i16] = c2_b_inData[c2_i16];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 11, 1));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  real_T c2_b_inData[44];
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  real_T c2_u[44];
  const mxArray *c2_y = NULL;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i17 = 0;
  for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
    for (c2_i19 = 0; c2_i19 < 11; c2_i19++) {
      c2_b_inData[c2_i19 + c2_i17] = (*(real_T (*)[44])c2_inData)[c2_i19 +
        c2_i17];
    }

    c2_i17 += 11;
  }

  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 4; c2_i21++) {
    for (c2_i22 = 0; c2_i22 < 11; c2_i22++) {
      c2_u[c2_i22 + c2_i20] = c2_b_inData[c2_i22 + c2_i20];
    }

    c2_i20 += 11;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 11, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[57];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i23;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 57));
  for (c2_i23 = 0; c2_i23 < 57; c2_i23++) {
    c2_r0 = &c2_info[c2_i23];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i23);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[57])
{
  c2_info[0].context = "";
  c2_info[0].name = "mldivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[0].fileTimeLo = 3368733440U;
  c2_info[0].fileTimeHi = 30130985U;
  c2_info[0].mFileTimeLo = 509702400U;
  c2_info[0].mFileTimeHi = 30114350U;
  c2_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[1].name = "eml_qrsolve";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[1].fileTimeLo = 2579026944U;
  c2_info[1].fileTimeHi = 30108061U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[2].name = "min";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[2].fileTimeLo = 1619026944U;
  c2_info[2].fileTimeHi = 30108061U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[3].name = "eml_min_or_max";
  c2_info[3].dominantType = "char";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[3].fileTimeLo = 2539026944U;
  c2_info[3].fileTimeHi = 30108061U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[4].name = "eml_scalar_eg";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[4].fileTimeLo = 2619026944U;
  c2_info[4].fileTimeHi = 30108061U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[5].name = "eml_scalexp_alloc";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[5].fileTimeLo = 2619026944U;
  c2_info[5].fileTimeHi = 30108061U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[6].name = "eml_index_class";
  c2_info[6].dominantType = "";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[6].fileTimeLo = 2439026944U;
  c2_info[6].fileTimeHi = 30108061U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[7].name = "eml_xgeqp3";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c2_info[7].fileTimeLo = 2699026944U;
  c2_info[7].fileTimeHi = 30108061U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c2_info[8].name = "eml_lapack_xgeqp3";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c2_info[8].fileTimeLo = 2739026944U;
  c2_info[8].fileTimeHi = 30108061U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c2_info[9].name = "eml_matlab_zgeqp3";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[9].fileTimeLo = 4086200064U;
  c2_info[9].fileTimeHi = 30115466U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[10].name = "colon";
  c2_info[10].dominantType = "int32";
  c2_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[10].fileTimeLo = 3039026944U;
  c2_info[10].fileTimeHi = 30108061U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[11].name = "floor";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[11].fileTimeLo = 2079026944U;
  c2_info[11].fileTimeHi = 30108061U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[12].name = "eml_scalar_floor";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[12].fileTimeLo = 1919026944U;
  c2_info[12].fileTimeHi = 30108061U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[13].name = "intmin";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[13].fileTimeLo = 2219026944U;
  c2_info[13].fileTimeHi = 30108061U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[14].name = "intmax";
  c2_info[14].dominantType = "char";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[14].fileTimeLo = 2219026944U;
  c2_info[14].fileTimeHi = 30108061U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c2_info[15].name = "mrdivide";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[15].fileTimeLo = 3368733440U;
  c2_info[15].fileTimeHi = 30130985U;
  c2_info[15].mFileTimeLo = 529702400U;
  c2_info[15].mFileTimeHi = 30114350U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[16].name = "rdivide";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[16].fileTimeLo = 3099026944U;
  c2_info[16].fileTimeHi = 30108061U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[17].name = "eml_div";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[17].fileTimeLo = 1639026944U;
  c2_info[17].fileTimeHi = 30108061U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[18].name = "eps";
  c2_info[18].dominantType = "char";
  c2_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[18].fileTimeLo = 1519026944U;
  c2_info[18].fileTimeHi = 30108061U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[19].name = "eml_is_float_class";
  c2_info[19].dominantType = "char";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[19].fileTimeLo = 2479026944U;
  c2_info[19].fileTimeHi = 30108061U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[20].name = "sqrt";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[20].fileTimeLo = 2179026944U;
  c2_info[20].fileTimeHi = 30108061U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[21].name = "eml_error";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[21].fileTimeLo = 1659026944U;
  c2_info[21].fileTimeHi = 30108061U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[22].name = "eml_scalar_sqrt";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[22].fileTimeLo = 2039026944U;
  c2_info[22].fileTimeHi = 30108061U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[23].name = "eml_xnrm2";
  c2_info[23].dominantType = "int32";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c2_info[23].fileTimeLo = 1779026944U;
  c2_info[23].fileTimeHi = 30108061U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[24].name = "eml_refblas_xnrm2";
  c2_info[24].dominantType = "int32";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[24].fileTimeLo = 2779026944U;
  c2_info[24].fileTimeHi = 30108061U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[25].name = "eml_index_minus";
  c2_info[25].dominantType = "int32";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[25].fileTimeLo = 2439026944U;
  c2_info[25].fileTimeHi = 30108061U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[26].name = "eml_index_times";
  c2_info[26].dominantType = "int32";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[26].fileTimeLo = 2459026944U;
  c2_info[26].fileTimeHi = 30108061U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[27].name = "eml_index_plus";
  c2_info[27].dominantType = "int32";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[27].fileTimeLo = 2439026944U;
  c2_info[27].fileTimeHi = 30108061U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[28].name = "abs";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[28].fileTimeLo = 1599026944U;
  c2_info[28].fileTimeHi = 30108061U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[29].name = "eml_scalar_abs";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[29].fileTimeLo = 1779026944U;
  c2_info[29].fileTimeHi = 30108061U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[30].name = "eml_ixamax";
  c2_info[30].dominantType = "int32";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[30].fileTimeLo = 1699026944U;
  c2_info[30].fileTimeHi = 30108061U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c2_info[31].name = "eml_refblas_ixamax";
  c2_info[31].dominantType = "int32";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[31].fileTimeLo = 2439026944U;
  c2_info[31].fileTimeHi = 30108061U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[32].name = "eml_xcabs1";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[32].fileTimeLo = 1719026944U;
  c2_info[32].fileTimeHi = 30108061U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[33].name = "eml_xswap";
  c2_info[33].dominantType = "int32";
  c2_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[33].fileTimeLo = 2699026944U;
  c2_info[33].fileTimeHi = 30108061U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c2_info[34].name = "eml_refblas_xswap";
  c2_info[34].dominantType = "int32";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[34].fileTimeLo = 2819026944U;
  c2_info[34].fileTimeHi = 30108061U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[35].name = "eml_matlab_zlarfg";
  c2_info[35].dominantType = "int32";
  c2_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c2_info[35].fileTimeLo = 2879026944U;
  c2_info[35].fileTimeHi = 30108061U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c2_info[36].name = "eml_dlapy2";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c2_info[36].fileTimeLo = 1639026944U;
  c2_info[36].fileTimeHi = 30108061U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c2_info[37].name = "isnan";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[37].fileTimeLo = 2259026944U;
  c2_info[37].fileTimeHi = 30108061U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c2_info[38].name = "realmin";
  c2_info[38].dominantType = "char";
  c2_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[38].fileTimeLo = 2339026944U;
  c2_info[38].fileTimeHi = 30108061U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[39].name = "mpower";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[39].fileTimeLo = 3079026944U;
  c2_info[39].fileTimeHi = 30108061U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[40].name = "power";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[40].fileTimeLo = 3099026944U;
  c2_info[40].fileTimeHi = 30108061U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c2_info[41].name = "eml_xscal";
  c2_info[41].dominantType = "int32";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c2_info[41].fileTimeLo = 2699026944U;
  c2_info[41].fileTimeHi = 30108061U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c2_info[42].name = "eml_refblas_xscal";
  c2_info[42].dominantType = "int32";
  c2_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[42].fileTimeLo = 2819026944U;
  c2_info[42].fileTimeHi = 30108061U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c2_info[43].name = "mtimes";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[43].fileTimeLo = 529702400U;
  c2_info[43].fileTimeHi = 30114350U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c2_info[44].name = "eml_matlab_zlarf";
  c2_info[44].dominantType = "int32";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c2_info[44].fileTimeLo = 2879026944U;
  c2_info[44].fileTimeHi = 30108061U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c2_info[45].name = "isequal";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[45].fileTimeLo = 2239026944U;
  c2_info[45].fileTimeHi = 30108061U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[46].name = "eml_isequal_core";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[46].fileTimeLo = 2519026944U;
  c2_info[46].fileTimeHi = 30108061U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c2_info[47].name = "eml_xgemv";
  c2_info[47].dominantType = "int32";
  c2_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  c2_info[47].fileTimeLo = 1759026944U;
  c2_info[47].fileTimeHi = 30108061U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c2_info[48].name = "eml_refblas_xgemv";
  c2_info[48].dominantType = "int32";
  c2_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c2_info[48].fileTimeLo = 2479026944U;
  c2_info[48].fileTimeHi = 30108061U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c2_info[49].name = "eml_conjtimes";
  c2_info[49].dominantType = "double";
  c2_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  c2_info[49].fileTimeLo = 1619026944U;
  c2_info[49].fileTimeHi = 30108061U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c2_info[50].name = "eml_xgerc";
  c2_info[50].dominantType = "int32";
  c2_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c2_info[50].fileTimeLo = 1759026944U;
  c2_info[50].fileTimeHi = 30108061U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c2_info[51].name = "eml_xger";
  c2_info[51].dominantType = "int32";
  c2_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[51].fileTimeLo = 1759026944U;
  c2_info[51].fileTimeHi = 30108061U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c2_info[52].name = "eml_refblas_xger";
  c2_info[52].dominantType = "int32";
  c2_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[52].fileTimeLo = 2479026944U;
  c2_info[52].fileTimeHi = 30108061U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[53].name = "eml_refblas_xgerx";
  c2_info[53].dominantType = "int32";
  c2_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[53].fileTimeLo = 2519026944U;
  c2_info[53].fileTimeHi = 30108061U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[54].name = "max";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[54].fileTimeLo = 1599026944U;
  c2_info[54].fileTimeHi = 30108061U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[55].name = "eml_flt2str";
  c2_info[55].dominantType = "double";
  c2_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c2_info[55].fileTimeLo = 2419026944U;
  c2_info[55].fileTimeHi = 30108061U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c2_info[56].name = "eml_warning";
  c2_info[56].dominantType = "char";
  c2_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[56].fileTimeLo = 2679026944U;
  c2_info[56].fileTimeHi = 30108061U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
}

static void c2_mldivide(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_A[44], real_T c2_B[11], real_T c2_Y[4])
{
  int32_T c2_i24;
  real_T c2_b_A[44];
  int32_T c2_i25;
  real_T c2_b_B[11];
  int32_T c2_i26;
  int32_T c2_jpvt[4];
  int32_T c2_i27;
  real_T c2_work[4];
  real_T c2_TOL3Z;
  int32_T c2_k;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_i28;
  real_T c2_c_A[44];
  real_T c2_vn1[4];
  real_T c2_vn2[4];
  int32_T c2_a;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_b_a;
  int32_T c2_im1;
  int32_T c2_c_a;
  int32_T c2_ip1;
  int32_T c2_d_a;
  int32_T c2_c;
  int32_T c2_e_a;
  int32_T c2_b;
  int32_T c2_i_i;
  int32_T c2_b_b;
  int32_T c2_nmi;
  int32_T c2_c_b;
  int32_T c2_mmi;
  int32_T c2_d_b;
  int32_T c2_mmip1;
  int32_T c2_e_b;
  int32_T c2_nmip1;
  int32_T c2_f_a;
  int32_T c2_i29;
  real_T c2_b_vn1[4];
  int32_T c2_f_b;
  int32_T c2_pvt;
  int32_T c2_g_a;
  int32_T c2_b_c;
  int32_T c2_g_b;
  int32_T c2_c_c;
  int32_T c2_h_b;
  int32_T c2_pvtcol;
  int32_T c2_i_b;
  int32_T c2_d_c;
  int32_T c2_j_b;
  int32_T c2_mcol;
  int32_T c2_itemp;
  real_T c2_atmp;
  int32_T c2_h_a;
  int32_T c2_e_c;
  int32_T c2_n;
  real_T c2_alpha1;
  int32_T c2_ix0;
  real_T c2_b_atmp;
  real_T c2_d1;
  int32_T c2_q0;
  int32_T c2_q1;
  int32_T c2_qY;
  int32_T c2_nm1;
  int32_T c2_i30;
  real_T c2_d_A[44];
  real_T c2_xnorm;
  real_T c2_beta1;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_y;
  int32_T c2_knt;
  int32_T c2_i_a;
  real_T c2_j_a;
  real_T c2_k_a;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b_y;
  int32_T c2_i31;
  real_T c2_e_A[44];
  real_T c2_e_x;
  real_T c2_c_y;
  real_T c2_f_x;
  real_T c2_d_y;
  real_T c2_e_y;
  real_T c2_f_y;
  int32_T c2_b_k;
  real_T c2_l_a;
  real_T c2_g_x;
  real_T c2_g_y;
  real_T c2_h_x;
  real_T c2_h_y;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_tau[4];
  real_T c2_c_atmp;
  real_T c2_d2;
  real_T c2_d3;
  int32_T c2_m_a;
  int32_T c2_f_c;
  int32_T c2_n_a;
  int32_T c2_k_b;
  int32_T c2_i_ip1;
  int32_T c2_b_ip1;
  int32_T c2_c_j;
  int32_T c2_o_a;
  int32_T c2_g_c;
  int32_T c2_l_b;
  int32_T c2_h_c;
  int32_T c2_p_a;
  int32_T c2_m_b;
  int32_T c2_i_j;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_y;
  real_T c2_temp1;
  real_T c2_q_a;
  real_T c2_n_b;
  real_T c2_l_y;
  real_T c2_temp2;
  real_T c2_r_a;
  real_T c2_o_b;
  real_T c2_m_y;
  real_T c2_s_a;
  real_T c2_p_b;
  int32_T c2_t_a;
  int32_T c2_i_c;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  real_T c2_n_y;
  int32_T c2_i32;
  real_T c2_f_A[44];
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_u_a;
  real_T c2_q_b;
  real_T c2_o_y;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_p_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_y;
  real_T c2_r_b;
  real_T c2_r_y;
  real_T c2_v_a;
  real_T c2_tol;
  real_T c2_rankR;
  real_T c2_c_k;
  real_T c2_d_k;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_t_y;
  real_T c2_u_x;
  int32_T c2_i33;
  static char_T c2_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c2_u[8];
  const mxArray *c2_u_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_v_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_w_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_x_y = NULL;
  char_T c2_str[14];
  int32_T c2_i34;
  char_T c2_b_str[14];
  int32_T c2_i35;
  real_T c2_d_j;
  real_T c2_e_j;
  real_T c2_tauj;
  real_T c2_wj;
  real_T c2_d4;
  real_T c2_c_i;
  real_T c2_d_i;
  real_T c2_w_a;
  real_T c2_s_b;
  real_T c2_z;
  real_T c2_x_a;
  real_T c2_t_b;
  real_T c2_d5;
  real_T c2_e_i;
  real_T c2_y_a;
  real_T c2_u_b;
  real_T c2_y_y;
  real_T c2_rr;
  real_T c2_f_i;
  real_T c2_b_rr;
  real_T c2_f_j;
  int32_T c2_pj;
  real_T c2_v_x;
  real_T c2_ab_y;
  real_T c2_w_x;
  real_T c2_bb_y;
  real_T c2_b_z;
  real_T c2_loop_ub;
  real_T c2_g_i;
  real_T c2_ab_a;
  real_T c2_v_b;
  real_T c2_cb_y;
  boolean_T exitg1;
  for (c2_i24 = 0; c2_i24 < 44; c2_i24++) {
    c2_b_A[c2_i24] = c2_A[c2_i24];
  }

  for (c2_i25 = 0; c2_i25 < 11; c2_i25++) {
    c2_b_B[c2_i25] = c2_B[c2_i25];
  }

  c2_eml_scalar_eg(chartInstance);
  for (c2_i26 = 0; c2_i26 < 4; c2_i26++) {
    c2_jpvt[c2_i26] = 1 + c2_i26;
  }

  c2_eml_scalar_eg(chartInstance);
  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    c2_work[c2_i27] = 0.0;
  }

  c2_eps(chartInstance);
  c2_TOL3Z = 2.2204460492503131E-16;
  c2_b_sqrt(chartInstance, &c2_TOL3Z);
  c2_eml_scalar_eg(chartInstance);
  c2_k = 1;
  for (c2_j = 1; c2_j < 5; c2_j++) {
    c2_b_j = c2_j;
    for (c2_i28 = 0; c2_i28 < 44; c2_i28++) {
      c2_c_A[c2_i28] = c2_b_A[c2_i28];
    }

    c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_j), 1, 4, 1, 0) - 1] = c2_eml_xnrm2(chartInstance, c2_c_A,
      c2_k);
    c2_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_j), 1, 4, 1, 0) - 1] = c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 1, 0) - 1];
    c2_a = c2_k + 11;
    c2_k = c2_a;
  }

  for (c2_i = 1; c2_i < 5; c2_i++) {
    c2_b_i = c2_i;
    c2_b_a = c2_b_i - 1;
    c2_im1 = c2_b_a;
    c2_c_a = c2_b_i;
    c2_ip1 = c2_c_a;
    c2_d_a = c2_im1;
    c2_c = c2_d_a * 11;
    c2_e_a = c2_b_i;
    c2_b = c2_c;
    c2_i_i = c2_e_a + c2_b;
    c2_b_b = c2_b_i - 4;
    c2_nmi = -c2_b_b;
    c2_c_b = c2_b_i - 11;
    c2_mmi = -c2_c_b;
    c2_d_b = c2_mmi + 1;
    c2_mmip1 = c2_d_b;
    c2_e_b = c2_nmi;
    c2_nmip1 = c2_e_b;
    c2_f_a = c2_im1;
    for (c2_i29 = 0; c2_i29 < 4; c2_i29++) {
      c2_b_vn1[c2_i29] = c2_vn1[c2_i29];
    }

    c2_f_b = c2_eml_ixamax(chartInstance, c2_nmip1 + 1, c2_b_vn1, c2_b_i);
    c2_pvt = c2_f_a + c2_f_b;
    if (c2_pvt != c2_b_i) {
      c2_g_a = c2_pvt;
      c2_b_c = c2_g_a;
      c2_g_b = c2_b_c;
      c2_c_c = 11 * (c2_g_b - 1);
      c2_h_b = c2_c_c;
      c2_pvtcol = c2_h_b;
      c2_i_b = c2_im1;
      c2_d_c = 11 * c2_i_b;
      c2_j_b = c2_d_c;
      c2_mcol = c2_j_b;
      c2_b_eml_xswap(chartInstance, c2_b_A, c2_pvtcol + 1, c2_mcol + 1);
      c2_itemp = c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_pvt), 1, 4, 1, 0) - 1];
      c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_pvt), 1, 4, 1, 0) - 1] = c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) - 1];
      c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_i), 1, 4, 1, 0) - 1] = c2_itemp;
      c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_pvt), 1, 4, 1, 0) - 1] = c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) - 1];
      c2_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_pvt), 1, 4, 1, 0) - 1] = c2_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) - 1];
    }

    c2_atmp = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c2_i_i), 1, 44, 1, 0) - 1];
    if (c2_b_i < 11) {
      c2_h_a = c2_i_i;
      c2_e_c = c2_h_a;
      c2_n = c2_mmip1;
      c2_alpha1 = c2_atmp;
      c2_ix0 = c2_e_c + 1;
      c2_b_atmp = c2_alpha1;
      c2_d1 = 0.0;
      if ((real_T)c2_n <= 0.0) {
      } else {
        c2_q0 = c2_n;
        c2_q1 = 1;
        c2_qY = c2_q0 - c2_q1;
        if ((c2_q0 < 0) && ((c2_q1 >= 0) && (c2_qY >= 0))) {
          c2_qY = MIN_int32_T;
        } else {
          if ((c2_q0 >= 0) && ((c2_q1 < 0) && (c2_qY < 0))) {
            c2_qY = MAX_int32_T;
          }
        }

        c2_nm1 = c2_qY;
        for (c2_i30 = 0; c2_i30 < 44; c2_i30++) {
          c2_d_A[c2_i30] = c2_b_A[c2_i30];
        }

        c2_xnorm = c2_b_eml_xnrm2(chartInstance, c2_nm1, c2_d_A, c2_ix0);
        if (c2_xnorm != 0.0) {
          c2_beta1 = c2_eml_dlapy2(chartInstance, c2_b_atmp, c2_xnorm);
          if (c2_b_atmp >= 0.0) {
            c2_beta1 = -c2_beta1;
          }

          c2_x = c2_beta1;
          c2_b_x = c2_x;
          c2_y = muDoubleScalarAbs(c2_b_x);
          if (c2_y < 1.0020841800044864E-292) {
            c2_knt = 0;
            do {
              c2_i_a = c2_knt + 1;
              c2_knt = c2_i_a;
              c2_c_eml_xscal(chartInstance, c2_nm1, 9.9792015476736E+291, c2_b_A,
                             c2_ix0);
              c2_j_a = c2_beta1;
              c2_beta1 = c2_j_a * 9.9792015476736E+291;
              c2_k_a = c2_b_atmp;
              c2_b_atmp = c2_k_a * 9.9792015476736E+291;
              c2_c_x = c2_beta1;
              c2_d_x = c2_c_x;
              c2_b_y = muDoubleScalarAbs(c2_d_x);
            } while (!(c2_b_y >= 1.0020841800044864E-292));

            for (c2_i31 = 0; c2_i31 < 44; c2_i31++) {
              c2_e_A[c2_i31] = c2_b_A[c2_i31];
            }

            c2_xnorm = c2_b_eml_xnrm2(chartInstance, c2_nm1, c2_e_A, c2_ix0);
            c2_beta1 = c2_eml_dlapy2(chartInstance, c2_b_atmp, c2_xnorm);
            if (c2_b_atmp >= 0.0) {
              c2_beta1 = -c2_beta1;
            }

            c2_e_x = c2_beta1 - c2_b_atmp;
            c2_c_y = c2_beta1;
            c2_f_x = c2_e_x;
            c2_d_y = c2_c_y;
            c2_d1 = c2_f_x / c2_d_y;
            c2_e_y = c2_b_atmp - c2_beta1;
            c2_f_y = c2_e_y;
            c2_b_atmp = 1.0 / c2_f_y;
            c2_c_eml_xscal(chartInstance, c2_nm1, c2_b_atmp, c2_b_A, c2_ix0);
            for (c2_b_k = 1; c2_b_k <= c2_knt; c2_b_k++) {
              c2_l_a = c2_beta1;
              c2_beta1 = c2_l_a * 1.0020841800044864E-292;
            }

            c2_b_atmp = c2_beta1;
          } else {
            c2_g_x = c2_beta1 - c2_b_atmp;
            c2_g_y = c2_beta1;
            c2_h_x = c2_g_x;
            c2_h_y = c2_g_y;
            c2_d1 = c2_h_x / c2_h_y;
            c2_i_y = c2_b_atmp - c2_beta1;
            c2_j_y = c2_i_y;
            c2_b_atmp = 1.0 / c2_j_y;
            c2_c_eml_xscal(chartInstance, c2_nm1, c2_b_atmp, c2_b_A, c2_ix0);
            c2_b_atmp = c2_beta1;
          }
        }
      }

      c2_atmp = c2_b_atmp;
      c2_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_i), 1, 4, 1, 0) - 1] = c2_d1;
    } else {
      c2_c_atmp = c2_atmp;
      c2_d2 = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c2_i_i), 1, 44, 1, 0) - 1];
      c2_d3 = c2_b_eml_matlab_zlarfg(chartInstance, &c2_c_atmp, &c2_d2);
      c2_atmp = c2_c_atmp;
      c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_i_i), 1, 44, 1, 0) - 1] = c2_d2;
      c2_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_i), 1, 4, 1, 0) - 1] = c2_d3;
    }

    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_i_i), 1, 44, 1, 0) - 1] = c2_atmp;
    if (c2_b_i < 4) {
      c2_atmp = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_i_i), 1, 44, 1, 0) - 1];
      c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_i_i), 1, 44, 1, 0) - 1] = 1.0;
      c2_m_a = c2_b_i;
      c2_f_c = c2_m_a * 11;
      c2_n_a = c2_b_i;
      c2_k_b = c2_f_c;
      c2_i_ip1 = c2_n_a + c2_k_b;
      c2_b_eml_matlab_zlarf(chartInstance, c2_mmip1, c2_nmi, c2_i_i,
                            c2_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) - 1], c2_b_A,
                            c2_i_ip1, c2_work);
      c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_i_i), 1, 44, 1, 0) - 1] = c2_atmp;
    }

    c2_b_ip1 = c2_ip1;
    for (c2_c_j = c2_b_ip1 + 1; c2_c_j < 5; c2_c_j++) {
      c2_b_j = c2_c_j;
      c2_o_a = c2_b_j;
      c2_g_c = c2_o_a;
      c2_l_b = c2_g_c;
      c2_h_c = 11 * (c2_l_b - 1);
      c2_p_a = c2_b_i;
      c2_m_b = c2_h_c;
      c2_i_j = c2_p_a + c2_m_b;
      if (c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_j), 1, 4, 1, 0) - 1] != 0.0) {
        c2_i_x = c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 11, 1, 0) + 11 *
                         (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 2, 0) - 1)) - 1];
        c2_j_x = c2_i_x;
        c2_k_y = muDoubleScalarAbs(c2_j_x);
        c2_temp1 = c2_k_y / c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 1, 0) - 1];
        c2_q_a = c2_temp1;
        c2_n_b = c2_temp1;
        c2_l_y = c2_q_a * c2_n_b;
        c2_temp1 = 1.0 - c2_l_y;
        if (c2_temp1 < 0.0) {
          c2_temp1 = 0.0;
        }

        c2_temp2 = c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 1, 0) - 1] /
          c2_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 4, 1, 0) - 1];
        c2_r_a = c2_temp2;
        c2_o_b = c2_temp2;
        c2_m_y = c2_r_a * c2_o_b;
        c2_s_a = c2_temp1;
        c2_p_b = c2_m_y;
        c2_temp2 = c2_s_a * c2_p_b;
        if (c2_temp2 <= c2_TOL3Z) {
          if (c2_b_i < 11) {
            c2_t_a = c2_i_j;
            c2_i_c = c2_t_a;
            c2_b_n = c2_mmi;
            c2_b_ix0 = c2_i_c;
            c2_c_n = c2_b_n;
            c2_c_ix0 = c2_b_ix0;
            if ((real_T)c2_c_n < 1.0) {
              c2_n_y = 0.0;
            } else {
              for (c2_i32 = 0; c2_i32 < 44; c2_i32++) {
                c2_f_A[c2_i32] = c2_b_A[c2_i32];
              }

              c2_n_y = c2_ceval_xnrm2(chartInstance, c2_c_n, c2_f_A, c2_c_ix0 +
                1, 1);
            }

            c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_b_j), 1, 4, 1, 0) - 1] = c2_n_y;
            c2_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_b_j), 1, 4, 1, 0) - 1] =
              c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c2_b_j), 1, 4, 1, 0) - 1];
          } else {
            c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_b_j), 1, 4, 1, 0) - 1] = 0.0;
            c2_vn2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_b_j), 1, 4, 1, 0) - 1] = 0.0;
          }
        } else {
          c2_k_x = c2_temp1;
          c2_l_x = c2_k_x;
          if (c2_l_x < 0.0) {
            c2_eml_error(chartInstance);
          }

          c2_l_x = muDoubleScalarSqrt(c2_l_x);
          c2_u_a = c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 1, 0) - 1];
          c2_q_b = c2_l_x;
          c2_o_y = c2_u_a * c2_q_b;
          c2_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_j), 1, 4, 1, 0) - 1] = c2_o_y;
        }
      }
    }
  }

  c2_m_x = c2_b_A[0];
  c2_n_x = c2_m_x;
  c2_p_y = muDoubleScalarAbs(c2_n_x);
  c2_o_x = 0.0;
  c2_p_x = c2_o_x;
  c2_q_y = muDoubleScalarAbs(c2_p_x);
  c2_r_b = c2_p_y + c2_q_y;
  c2_r_y = 11.0 * c2_r_b;
  c2_v_a = c2_r_y;
  c2_tol = c2_v_a * 2.2204460492503131E-16;
  c2_rankR = 0.0;
  c2_c_k = 1.0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c2_c_k <= 4.0)) {
    c2_d_k = c2_c_k;
    c2_q_x = c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c2_d_k), 1, 11, 1, 0) + 11 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_d_k), 1, 4, 2, 0) - 1)) - 1];
    c2_r_x = c2_q_x;
    c2_s_y = muDoubleScalarAbs(c2_r_x);
    c2_s_x = 0.0;
    c2_t_x = c2_s_x;
    c2_t_y = muDoubleScalarAbs(c2_t_x);
    if (c2_s_y + c2_t_y <= c2_tol) {
      c2_u_x = c2_tol;
      for (c2_i33 = 0; c2_i33 < 8; c2_i33++) {
        c2_u[c2_i33] = c2_cv0[c2_i33];
      }

      c2_u_y = NULL;
      sf_mex_assign(&c2_u_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 8));
      c2_b_u = 14.0;
      c2_v_y = NULL;
      sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
      c2_c_u = 6.0;
      c2_w_y = NULL;
      sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
      c2_d_u = c2_u_x;
      c2_x_y = NULL;
      sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
      c2_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c2_u_y, 14, c2_v_y, 14,
        c2_w_y), 14, c2_x_y), "sprintf", c2_str);
      for (c2_i34 = 0; c2_i34 < 14; c2_i34++) {
        c2_b_str[c2_i34] = c2_str[c2_i34];
      }

      c2_eml_warning(chartInstance, c2_rankR, c2_b_str);
      exitg1 = 1U;
    } else {
      c2_rankR++;
      c2_c_k++;
    }
  }

  for (c2_i35 = 0; c2_i35 < 4; c2_i35++) {
    c2_Y[c2_i35] = 0.0;
  }

  for (c2_d_j = 1.0; c2_d_j <= 4.0; c2_d_j++) {
    c2_e_j = c2_d_j;
    c2_tauj = c2_tau[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", c2_e_j), 1, 4, 1, 0) - 1];
    if (c2_tauj != 0.0) {
      c2_wj = c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", c2_e_j), 1, 11, 1, 0) - 1];
      c2_d4 = c2_e_j + 1.0;
      for (c2_c_i = c2_d4; c2_c_i <= 11.0; c2_c_i++) {
        c2_d_i = c2_c_i;
        c2_w_a = c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c2_d_i), 1, 11, 1, 0) + 11 *
                         (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c2_e_j), 1, 4, 2, 0) - 1)) - 1];
        c2_s_b = c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c2_d_i), 1, 11, 1, 0) - 1];
        c2_z = c2_w_a * c2_s_b;
        c2_wj += c2_z;
      }

      c2_x_a = c2_tauj;
      c2_t_b = c2_wj;
      c2_wj = c2_x_a * c2_t_b;
      if (c2_wj != 0.0) {
        c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c2_e_j), 1, 11, 1, 0) - 1] = c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", c2_e_j), 1, 11, 1, 0) - 1] - c2_wj;
        c2_d5 = c2_e_j + 1.0;
        for (c2_e_i = c2_d5; c2_e_i <= 11.0; c2_e_i++) {
          c2_d_i = c2_e_i;
          c2_y_a = c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c2_d_i), 1, 11, 1, 0) + 11 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c2_e_j), 1, 4, 2, 0) - 1)) - 1];
          c2_u_b = c2_wj;
          c2_y_y = c2_y_a * c2_u_b;
          c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            c2_d_i), 1, 11, 1, 0) - 1] = c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c2_d_i), 1, 11, 1, 0) - 1] - c2_y_y;
        }
      }
    }
  }

  c2_rr = c2_rankR;
  for (c2_f_i = 1.0; c2_f_i <= c2_rr; c2_f_i++) {
    c2_d_i = c2_f_i;
    c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_d_i), 1, 4, 1, 0) - 1]), 1, 4, 1, 0) - 1] =
      c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_d_i), 1, 11, 1, 0) - 1];
  }

  c2_b_rr = c2_rr;
  for (c2_f_j = c2_b_rr; c2_f_j >= 1.0; c2_f_j += -1.0) {
    c2_e_j = c2_f_j;
    c2_pj = c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c2_e_j), 1, 4, 1, 0) - 1];
    c2_v_x = c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_pj), 1, 4, 1, 0) - 1];
    c2_ab_y = c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_e_j), 1, 11, 1, 0) + 11 *
                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_e_j), 1, 4, 2, 0) - 1)) - 1];
    c2_w_x = c2_v_x;
    c2_bb_y = c2_ab_y;
    c2_b_z = c2_w_x / c2_bb_y;
    c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_pj), 1, 4, 1, 0) - 1] = c2_b_z;
    c2_loop_ub = c2_e_j - 1.0;
    for (c2_g_i = 1.0; c2_g_i <= c2_loop_ub; c2_g_i++) {
      c2_d_i = c2_g_i;
      c2_ab_a = c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c2_pj), 1, 4, 1, 0) - 1];
      c2_v_b = c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_d_i), 1, 11, 1, 0) + 11 *
                       (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_e_j), 1, 4, 2, 0) - 1)) - 1];
      c2_cb_y = c2_ab_a * c2_v_b;
      c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_d_i), 1, 4, 1, 0) - 1]), 1, 4, 1, 0) - 1] =
        c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_d_i), 1, 4, 1, 0) - 1]), 1, 4, 1, 0) - 1] -
        c2_cb_y;
    }
  }
}

static void c2_eml_scalar_eg(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance)
{
}

static void c2_eps(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
                   *chartInstance)
{
}

static real_T c2_sqrt(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
                      *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_eml_error(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance)
{
  int32_T c2_i36;
  static char_T c2_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i36 = 0; c2_i36 < 30; c2_i36++) {
    c2_u[c2_i36] = c2_varargin_1[c2_i36];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static real_T c2_eml_xnrm2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x[44], int32_T c2_ix0)
{
  int32_T c2_b_ix0;
  int32_T c2_i37;
  real_T c2_b_x[44];
  c2_b_ix0 = c2_ix0;
  for (c2_i37 = 0; c2_i37 < 44; c2_i37++) {
    c2_b_x[c2_i37] = c2_x[c2_i37];
  }

  return c2_ceval_xnrm2(chartInstance, 11, c2_b_x, c2_b_ix0, 1);
}

static real_T c2_ceval_xnrm2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0, int32_T c2_incx)
{
  return dnrm232(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 44, 1, 0) - 1], &c2_incx);
}

static int32_T c2_eml_ixamax(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[4], int32_T c2_ix0)
{
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_i38;
  real_T c2_b_x[4];
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  for (c2_i38 = 0; c2_i38 < 4; c2_i38++) {
    c2_b_x[c2_i38] = c2_x[c2_i38];
  }

  return c2_ceval_ixamax(chartInstance, c2_b_n, c2_b_x, c2_b_ix0, 1);
}

static int32_T c2_ceval_ixamax(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[4], int32_T c2_ix0, int32_T c2_incx)
{
  return idamax32(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 4, 1, 0) - 1], &c2_incx);
}

static void c2_eml_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x[44], int32_T c2_ix0, int32_T c2_iy0, real_T
  c2_b_x[44])
{
  int32_T c2_i39;
  for (c2_i39 = 0; c2_i39 < 44; c2_i39++) {
    c2_b_x[c2_i39] = c2_x[c2_i39];
  }

  c2_b_eml_xswap(chartInstance, c2_b_x, c2_ix0, c2_iy0);
}

static void c2_ceval_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[44])
{
  int32_T c2_i40;
  for (c2_i40 = 0; c2_i40 < 44; c2_i40++) {
    c2_b_x[c2_i40] = c2_x[c2_i40];
  }

  c2_b_ceval_xswap(chartInstance, c2_n, c2_b_x, c2_ix0, c2_incx, c2_iy0, c2_incy);
}

static real_T c2_b_eml_xnrm2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0)
{
  real_T c2_y;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_i41;
  real_T c2_b_x[44];
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  if ((real_T)c2_b_n < 1.0) {
    c2_y = 0.0;
  } else {
    for (c2_i41 = 0; c2_i41 < 44; c2_i41++) {
      c2_b_x[c2_i41] = c2_x[c2_i41];
    }

    c2_y = c2_ceval_xnrm2(chartInstance, c2_b_n, c2_b_x, c2_b_ix0, 1);
  }

  return c2_y;
}

static real_T c2_eml_dlapy2(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x1, real_T c2_x2)
{
  real_T c2_y;
  real_T c2_a;
  real_T c2_b;
  real_T c2_x;
  boolean_T c2_b_b;
  c2_a = muDoubleScalarAbs(c2_x1);
  c2_b = muDoubleScalarAbs(c2_x2);
  if (c2_a < c2_b) {
    c2_a /= c2_b;
    c2_y = muDoubleScalarSqrt(c2_a * c2_a + 1.0) * c2_b;
  } else if (c2_a > c2_b) {
    c2_b /= c2_a;
    c2_y = muDoubleScalarSqrt(c2_b * c2_b + 1.0) * c2_a;
  } else {
    c2_x = c2_b;
    c2_b_b = muDoubleScalarIsNaN(c2_x);
    if (c2_b_b) {
      c2_y = c2_b;
    } else {
      c2_y = c2_a * 1.4142135623730951;
    }
  }

  return c2_y;
}

static void c2_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0,
  real_T c2_b_x[44])
{
  int32_T c2_i42;
  for (c2_i42 = 0; c2_i42 < 44; c2_i42++) {
    c2_b_x[c2_i42] = c2_x[c2_i42];
  }

  c2_c_eml_xscal(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0);
}

static void c2_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0,
  int32_T c2_incx, real_T c2_b_x[44])
{
  int32_T c2_i43;
  for (c2_i43 = 0; c2_i43 < 44; c2_i43++) {
    c2_b_x[c2_i43] = c2_x[c2_i43];
  }

  c2_c_ceval_xscal(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0, c2_incx);
}

static void c2_eml_matlab_zlarfg
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, real_T
   c2_alpha1, real_T c2_x, real_T *c2_b_alpha1, real_T *c2_b_x, real_T *c2_tau)
{
  *c2_b_alpha1 = c2_alpha1;
  *c2_b_x = c2_x;
  *c2_tau = c2_b_eml_matlab_zlarfg(chartInstance, c2_b_alpha1, c2_b_x);
}

static real_T c2_b_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_a, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_d_eml_xscal(chartInstance, c2_a, &c2_b_x);
  return c2_b_x;
}

static real_T c2_b_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x, int32_T c2_ix0,
  int32_T c2_incx)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_d_ceval_xscal(chartInstance, c2_n, c2_a, &c2_b_x, c2_ix0, c2_incx);
  return c2_b_x;
}

static void c2_eml_matlab_zlarf
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, int32_T
   c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[44], int32_T
   c2_ic0, real_T c2_work[4], real_T c2_b_C[44], real_T c2_b_work[4])
{
  int32_T c2_i44;
  int32_T c2_i45;
  for (c2_i44 = 0; c2_i44 < 44; c2_i44++) {
    c2_b_C[c2_i44] = c2_C[c2_i44];
  }

  for (c2_i45 = 0; c2_i45 < 4; c2_i45++) {
    c2_b_work[c2_i45] = c2_work[c2_i45];
  }

  c2_b_eml_matlab_zlarf(chartInstance, c2_m, c2_n, c2_iv0, c2_tau, c2_b_C,
                        c2_ic0, c2_b_work);
}

static void c2_eml_blas_xgemv(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *
  chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_A[44], int32_T c2_ia0,
  real_T c2_x[44], int32_T c2_ix0, real_T c2_y[4], real_T c2_b_y[4])
{
  int32_T c2_i46;
  int32_T c2_i47;
  real_T c2_b_A[44];
  int32_T c2_i48;
  real_T c2_b_x[44];
  for (c2_i46 = 0; c2_i46 < 4; c2_i46++) {
    c2_b_y[c2_i46] = c2_y[c2_i46];
  }

  for (c2_i47 = 0; c2_i47 < 44; c2_i47++) {
    c2_b_A[c2_i47] = c2_A[c2_i47];
  }

  for (c2_i48 = 0; c2_i48 < 44; c2_i48++) {
    c2_b_x[c2_i48] = c2_x[c2_i48];
  }

  c2_b_eml_blas_xgemv(chartInstance, c2_m, c2_n, c2_b_A, c2_ia0, c2_b_x, c2_ix0,
                      c2_b_y);
}

static void c2_ceval_xgemv(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[44],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_x[44], int32_T c2_ix0, int32_T
  c2_incx, real_T c2_beta1, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy,
  real_T c2_b_y[4])
{
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_b_A[44];
  int32_T c2_i51;
  real_T c2_b_x[44];
  for (c2_i49 = 0; c2_i49 < 4; c2_i49++) {
    c2_b_y[c2_i49] = c2_y[c2_i49];
  }

  for (c2_i50 = 0; c2_i50 < 44; c2_i50++) {
    c2_b_A[c2_i50] = c2_A[c2_i50];
  }

  for (c2_i51 = 0; c2_i51 < 44; c2_i51++) {
    c2_b_x[c2_i51] = c2_x[c2_i51];
  }

  c2_b_ceval_xgemv(chartInstance, c2_m, c2_n, c2_alpha1, c2_b_A, c2_ia0, c2_lda,
                   c2_b_x, c2_ix0, c2_incx, c2_beta1, c2_b_y, c2_iy0, c2_incy);
}

static void c2_ceval_xger(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy, real_T c2_A
  [44], int32_T c2_ia0, int32_T c2_lda, real_T c2_b_A[44])
{
  int32_T c2_i52;
  int32_T c2_i53;
  real_T c2_b_y[4];
  for (c2_i52 = 0; c2_i52 < 44; c2_i52++) {
    c2_b_A[c2_i52] = c2_A[c2_i52];
  }

  for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
    c2_b_y[c2_i53] = c2_y[c2_i53];
  }

  c2_b_ceval_xger(chartInstance, c2_m, c2_n, c2_alpha1, c2_ix0, c2_incx, c2_b_y,
                  c2_iy0, c2_incy, c2_b_A, c2_ia0, c2_lda);
}

static void c2_eml_warning(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_varargin_2, char_T c2_varargin_3[14])
{
  int32_T c2_i54;
  static char_T c2_varargin_1[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i',
    'e', 'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c2_u[32];
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i55;
  char_T c2_c_u[14];
  const mxArray *c2_c_y = NULL;
  for (c2_i54 = 0; c2_i54 < 32; c2_i54++) {
    c2_u[c2_i54] = c2_varargin_1[c2_i54];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 32));
  c2_b_u = c2_varargin_2;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  for (c2_i55 = 0; c2_i55 < 14; c2_i55++) {
    c2_c_u[c2_i55] = c2_varargin_3[c2_i55];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 14));
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 3U,
    14, c2_y, 14, c2_b_y, 14, c2_c_y));
}

static void c2_d_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y[14])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_e_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, char_T c2_y[14])
{
  char_T c2_cv1[14];
  int32_T c2_i56;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c2_i56 = 0; c2_i56 < 14; c2_i56++) {
    c2_y[c2_i56] = c2_cv1[c2_i56];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i57;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i57, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i57;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
                      *chartInstance, real_T *c2_x)
{
  if (*c2_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void c2_b_eml_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_x[44], int32_T c2_ix0, int32_T c2_iy0)
{
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_ceval_xswap(chartInstance, 11, c2_x, c2_b_ix0, 1, c2_b_iy0, 1);
}

static void c2_b_ceval_xswap(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[44], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy)
{
  dswap32(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 44, 1, 0) - 1], &c2_incx,
          &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy0), 1, 44, 1, 0) - 1], &c2_incy);
}

static void c2_c_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_ceval_xscal(chartInstance, c2_b_n, c2_b_a, c2_x, c2_b_ix0, 1);
}

static void c2_c_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T c2_x[44], int32_T c2_ix0,
  int32_T c2_incx)
{
  dscal32(&c2_n, &c2_a, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 44, 1, 0) - 1], &c2_incx);
}

static real_T c2_b_eml_matlab_zlarfg
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, real_T
   *c2_alpha1, real_T *c2_x)
{
  return 0.0;
}

static void c2_d_eml_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, real_T c2_a, real_T *c2_x)
{
  real_T c2_b_a;
  c2_b_a = c2_a;
  c2_d_ceval_xscal(chartInstance, 0, c2_b_a, c2_x, 1, 1);
}

static void c2_d_ceval_xscal(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_a, real_T *c2_x, int32_T c2_ix0,
  int32_T c2_incx)
{
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ix0),
    1, 1, 1, 0);
  dscal32(&c2_n, &c2_a, c2_x, &c2_incx);
}

static void c2_b_eml_matlab_zlarf
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, int32_T
   c2_m, int32_T c2_n, int32_T c2_iv0, real_T c2_tau, real_T c2_C[44], int32_T
   c2_ic0, real_T c2_work[4])
{
  int32_T c2_lastv;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_i;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_b_m;
  int32_T c2_b_n;
  int32_T c2_ia0;
  int32_T c2_lastc;
  int32_T c2_e_a;
  int32_T c2_c_c;
  int32_T c2_f_a;
  int32_T c2_d_c;
  int32_T c2_g_a;
  int32_T c2_c_b;
  int32_T c2_coltop;
  int32_T c2_h_a;
  int32_T c2_e_c;
  int32_T c2_i_a;
  int32_T c2_d_b;
  int32_T c2_colbottom;
  int32_T c2_b_coltop;
  int32_T c2_ia;
  int32_T c2_b_ia;
  int32_T c2_j_a;
  int32_T c2_c_m;
  int32_T c2_c_n;
  int32_T c2_b_ia0;
  int32_T c2_ix0;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  real_T c2_b_C[44];
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  real_T c2_c_C[44];
  int32_T c2_d_m;
  int32_T c2_d_n;
  real_T c2_alpha1;
  int32_T c2_b_ix0;
  int32_T c2_c_ia0;
  int32_T c2_e_m;
  int32_T c2_e_n;
  real_T c2_b_alpha1;
  int32_T c2_c_ix0;
  int32_T c2_d_ia0;
  int32_T c2_f_m;
  int32_T c2_f_n;
  real_T c2_c_alpha1;
  int32_T c2_d_ix0;
  int32_T c2_e_ia0;
  int32_T c2_i64;
  real_T c2_b_work[4];
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  if (c2_tau != 0.0) {
    c2_lastv = c2_m;
    c2_a = c2_lastv;
    c2_c = c2_a;
    c2_b = c2_c;
    c2_b_c = c2_b - 1;
    c2_b_a = c2_iv0;
    c2_b_b = c2_b_c;
    c2_i = c2_b_a + c2_b_b;
    exitg3 = 0U;
    while ((exitg3 == 0U) && (c2_lastv > 0)) {
      if (c2_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_i), 1, 44, 1, 0) - 1] == 0.0) {
        c2_c_a = c2_lastv - 1;
        c2_lastv = c2_c_a;
        c2_d_a = c2_i - 1;
        c2_i = c2_d_a;
      } else {
        exitg3 = 1U;
      }
    }

    c2_b_m = c2_lastv;
    c2_b_n = c2_n;
    c2_ia0 = c2_ic0;
    c2_lastc = c2_b_n;
    exitg2 = 0U;
    while ((exitg2 == 0U) && ((real_T)c2_lastc > 0.0)) {
      c2_e_a = c2_lastc;
      c2_c_c = c2_e_a;
      c2_f_a = c2_c_c;
      c2_d_c = (c2_f_a - 1) * 11;
      c2_g_a = c2_ia0;
      c2_c_b = c2_d_c;
      c2_coltop = c2_g_a + c2_c_b;
      c2_h_a = c2_b_m;
      c2_e_c = c2_h_a;
      c2_i_a = c2_coltop;
      c2_d_b = c2_e_c;
      c2_colbottom = (c2_i_a + c2_d_b) - 1;
      c2_b_coltop = c2_coltop;
      c2_ia = c2_b_coltop;
      do {
        exitg1 = 0U;
        if (c2_ia <= c2_colbottom) {
          c2_b_ia = c2_ia;
          if (c2_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_b_ia), 1, 44, 1, 0) - 1] != 0.0) {
            exitg1 = 1U;
          } else {
            c2_ia++;
          }
        } else {
          c2_j_a = c2_lastc - 1;
          c2_lastc = c2_j_a;
          exitg1 = 2U;
        }
      } while (exitg1 == 0U);

      if (exitg1 == 1U) {
        exitg2 = 1U;
      }
    }
  } else {
    c2_lastv = 0;
    c2_lastc = 0;
  }

  if (c2_lastv > 0) {
    c2_c_m = c2_lastv;
    c2_c_n = c2_lastc;
    c2_b_ia0 = c2_ic0;
    c2_ix0 = c2_iv0;
    c2_i58 = 0;
    for (c2_i59 = 0; c2_i59 < 4; c2_i59++) {
      for (c2_i60 = 0; c2_i60 < 11; c2_i60++) {
        c2_b_C[c2_i60 + c2_i58] = c2_C[c2_i60 + c2_i58];
      }

      c2_i58 += 11;
    }

    c2_i61 = 0;
    for (c2_i62 = 0; c2_i62 < 4; c2_i62++) {
      for (c2_i63 = 0; c2_i63 < 11; c2_i63++) {
        c2_c_C[c2_i63 + c2_i61] = c2_C[c2_i63 + c2_i61];
      }

      c2_i61 += 11;
    }

    c2_b_eml_blas_xgemv(chartInstance, c2_c_m, c2_c_n, c2_b_C, c2_b_ia0, c2_c_C,
                        c2_ix0, c2_work);
    c2_d_m = c2_lastv;
    c2_d_n = c2_lastc;
    c2_alpha1 = -c2_tau;
    c2_b_ix0 = c2_iv0;
    c2_c_ia0 = c2_ic0;
    c2_e_m = c2_d_m;
    c2_e_n = c2_d_n;
    c2_b_alpha1 = c2_alpha1;
    c2_c_ix0 = c2_b_ix0;
    c2_d_ia0 = c2_c_ia0;
    c2_f_m = c2_e_m;
    c2_f_n = c2_e_n;
    c2_c_alpha1 = c2_b_alpha1;
    c2_d_ix0 = c2_c_ix0;
    c2_e_ia0 = c2_d_ia0;
    if ((real_T)c2_f_m < 1.0) {
    } else if ((real_T)c2_f_n < 1.0) {
    } else {
      for (c2_i64 = 0; c2_i64 < 4; c2_i64++) {
        c2_b_work[c2_i64] = c2_work[c2_i64];
      }

      c2_b_ceval_xger(chartInstance, c2_f_m, c2_f_n, c2_c_alpha1, c2_d_ix0, 1,
                      c2_b_work, 1, 1, c2_C, c2_e_ia0, 11);
    }
  }
}

static void c2_b_eml_blas_xgemv
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance, int32_T
   c2_m, int32_T c2_n, real_T c2_A[44], int32_T c2_ia0, real_T c2_x[44], int32_T
   c2_ix0, real_T c2_y[4])
{
  int32_T c2_i65;
  real_T c2_b_A[44];
  int32_T c2_i66;
  real_T c2_b_x[44];
  for (c2_i65 = 0; c2_i65 < 44; c2_i65++) {
    c2_b_A[c2_i65] = c2_A[c2_i65];
  }

  for (c2_i66 = 0; c2_i66 < 44; c2_i66++) {
    c2_b_x[c2_i66] = c2_x[c2_i66];
  }

  c2_b_ceval_xgemv(chartInstance, c2_m, c2_n, 1.0, c2_b_A, c2_ia0, 11, c2_b_x,
                   c2_ix0, 1, 0.0, c2_y, 1, 1);
}

static void c2_b_ceval_xgemv(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[44],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_x[44], int32_T c2_ix0, int32_T
  c2_incx, real_T c2_beta1, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy)
{
  char_T c2_TRANSA;
  c2_TRANSA = 'C';
  dgemv32(&c2_TRANSA, &c2_m, &c2_n, &c2_alpha1,
          &c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_ia0), 1, 44, 1, 0) - 1], &c2_lda,
          &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_ix0), 1, 44, 1, 0) - 1], &c2_incx, &c2_beta1,
          &c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy0), 1, 4, 1, 0) - 1], &c2_incy);
}

static void c2_b_ceval_xger(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, real_T c2_y[4], int32_T c2_iy0, int32_T c2_incy, real_T c2_A
  [44], int32_T c2_ia0, int32_T c2_lda)
{
  dger32(&c2_m, &c2_n, &c2_alpha1, &c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 44, 1, 0) - 1],
         &c2_incx, &c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_iy0), 1, 4, 1, 0) - 1], &c2_incy,
         &c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
           (real_T)c2_ia0), 1, 44, 1, 0) - 1], &c2_lda);
}

static void init_dsm_address_info
  (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(902126834U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3850227436U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(956007880U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(778696782U);
}

mxArray *sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2194974187U);
    pr[1] = (double)(877612486U);
    pr[2] = (double)(103785340U);
    pr[3] = (double)(3680874603U);
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
      pr[1] = (double)(1);
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
      pr[1] = (double)(1);
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

static const mxArray *sf_get_sim_state_info_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_lin_model_PI_MRAC_Sim_CASE2_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
    chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_,
           2,
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
            (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"U");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"V");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,41);
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
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 11;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c2_U)[44];
          real_T (*c2_y)[4];
          real_T (*c2_V)[11];
          c2_V = (real_T (*)[11])ssGetInputPortSignal(chartInstance->S, 1);
          c2_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_U = (real_T (*)[44])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_U);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_V);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_lin_model_PI_MRAC_Sim_CASE2_v2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*) chartInstanceVar);
  initialize_c2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_lin_model_PI_MRAC_Sim_CASE2_v2(void
  *chartInstanceVar)
{
  enable_c2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_lin_model_PI_MRAC_Sim_CASE2_v2(void
  *chartInstanceVar)
{
  disable_c2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_lin_model_PI_MRAC_Sim_CASE2_v2(void
  *chartInstanceVar)
{
  sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lin_model_PI_MRAC_Sim_CASE2_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lin_model_PI_MRAC_Sim_CASE2_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2(S);
}

static void sf_opaque_set_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2(S, st);
}

static void sf_opaque_terminate_c2_lin_model_PI_MRAC_Sim_CASE2_v2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_lin_model_PI_MRAC_Sim_CASE2_v2
      ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_lin_model_PI_MRAC_Sim_CASE2_v2
    ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_lin_model_PI_MRAC_Sim_CASE2_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_lin_model_PI_MRAC_Sim_CASE2_v2
      ((SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_lin_model_PI_MRAC_Sim_CASE2_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"lin_model_PI_MRAC_Sim_CASE2_v2",
      "lin_model_PI_MRAC_Sim_CASE2_v2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"lin_model_PI_MRAC_Sim_CASE2_v2",
                "lin_model_PI_MRAC_Sim_CASE2_v2",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "lin_model_PI_MRAC_Sim_CASE2_v2","lin_model_PI_MRAC_Sim_CASE2_v2",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"lin_model_PI_MRAC_Sim_CASE2_v2",
        "lin_model_PI_MRAC_Sim_CASE2_v2",2,2);
      sf_mark_chart_reusable_outputs(S,"lin_model_PI_MRAC_Sim_CASE2_v2",
        "lin_model_PI_MRAC_Sim_CASE2_v2",2,1);
    }

    sf_set_rtw_dwork_info(S,"lin_model_PI_MRAC_Sim_CASE2_v2",
                          "lin_model_PI_MRAC_Sim_CASE2_v2",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2225860923U));
  ssSetChecksum1(S,(2208537899U));
  ssSetChecksum2(S,(3324562048U));
  ssSetChecksum3(S,(1107365107U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_lin_model_PI_MRAC_Sim_CASE2_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "lin_model_PI_MRAC_Sim_CASE2_v2",
      "lin_model_PI_MRAC_Sim_CASE2_v2",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_lin_model_PI_MRAC_Sim_CASE2_v2(SimStruct *S)
{
  SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct *)malloc
    (sizeof(SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_lin_model_PI_MRAC_Sim_CASE2_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_lin_model_PI_MRAC_Sim_CASE2_v2;
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

void c2_lin_model_PI_MRAC_Sim_CASE2_v2_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_lin_model_PI_MRAC_Sim_CASE2_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_lin_model_PI_MRAC_Sim_CASE2_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_lin_model_PI_MRAC_Sim_CASE2_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_lin_model_PI_MRAC_Sim_CASE2_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
