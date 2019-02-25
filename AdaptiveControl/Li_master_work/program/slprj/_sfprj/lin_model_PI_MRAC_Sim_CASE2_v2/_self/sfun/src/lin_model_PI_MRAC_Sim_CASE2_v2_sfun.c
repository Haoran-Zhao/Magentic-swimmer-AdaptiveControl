/* Include files */

#include "lin_model_PI_MRAC_Sim_CASE2_v2_sfun.h"
#include "c2_lin_model_PI_MRAC_Sim_CASE2_v2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void lin_model_PI_MRAC_Sim_CASE2_v2_initializer(void)
{
}

void lin_model_PI_MRAC_Sim_CASE2_v2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_lin_model_PI_MRAC_Sim_CASE2_v2_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==2) {
    c2_lin_model_PI_MRAC_Sim_CASE2_v2_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_lin_model_PI_MRAC_Sim_CASE2_v2_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1021866631U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(282327095U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3568432525U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2307609779U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4150930336U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4246807627U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2578104633U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2522189797U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_check_sum(mxArray
            *plhs[]);
          sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1489836072U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(732216922U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2312615898U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1204684543U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lin_model_PI_MRAC_Sim_CASE2_v2_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern mxArray
          *sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_autoinheritance_info(void);
        plhs[0] = sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_lin_model_PI_MRAC_Sim_CASE2_v2_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_lin_model_PI_MRAC_Sim_CASE2_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void lin_model_PI_MRAC_Sim_CASE2_v2_debug_initialize(void)
{
  _lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_ = sf_debug_initialize_machine(
    "lin_model_PI_MRAC_Sim_CASE2_v2","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_lin_model_PI_MRAC_Sim_CASE2_v2MachineNumber_,0);
}

void lin_model_PI_MRAC_Sim_CASE2_v2_register_exported_symbols(SimStruct* S)
{
}
