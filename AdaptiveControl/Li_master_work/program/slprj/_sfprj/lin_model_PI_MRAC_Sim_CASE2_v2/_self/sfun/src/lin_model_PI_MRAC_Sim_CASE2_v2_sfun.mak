# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64
!include <ntwin32.mak>

MACHINE     = lin_model_PI_MRAC_Sim_CASE2_v2
TARGET      = sfun
CHART_SRCS 	= \
     c2_lin_model_PI_MRAC_Sim_CASE2_v2.c
MACHINE_SRC	= lin_model_PI_MRAC_Sim_CASE2_v2_sfun.c
MACHINE_REG = lin_model_PI_MRAC_Sim_CASE2_v2_sfun_registry.c
MEX_WRAPPER =
MAKEFILE    = lin_model_PI_MRAC_Sim_CASE2_v2_sfun.mak
MATLAB_ROOT	= F:\MATLAB\R2011a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
ML_INCLUDES     = /I "$(MATLAB_ROOT)\extern\include"
SL_INCLUDES     = /I "$(MATLAB_ROOT)\simulink\include"
SF_INCLUDES     = /I "F:\MATLAB\R2011a\stateflow\c\mex\include" /I "F:\MATLAB\R2011a\stateflow\c\debugger\include"

DSP_INCLUDES    =

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(ML_INCLUDES) $(SL_INCLUDES) $(SF_INCLUDES) $(DSP_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD $(COMPFLAGS)  
LDFLAGS = /nologo /dll /OPT:NOREF /export:mexFunction 
AUXLDFLAGS = 

#----------------------------- Source Files -----------------------------------

REQ_SRCS  = $(MACHINE_SRC) $(MACHINE_REG) $(MEX_WRAPPER) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = lin_model_PI_MRAC_Sim_CASE2_v2_sfun.mol
SFCLIB = "F:\MATLAB\R2011a\stateflow\c\mex\lib\win64\sfc_mex.lib" "F:\MATLAB\R2011a\stateflow\c\debugger\lib\win64\sfc_debug.lib"
AUX_LNK_OBJS =
USER_LIBS =
LINK_MACHINE_LIBS =

DSP_LIBS    =
BLAS_LIBS   = "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libmwblascompat32.lib"

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

MEXLIB = "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libmx.lib" "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libmex.lib" "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libmat.lib" "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libfixedpoint.lib" "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libut.lib" "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libmwmathutil.lib" "F:\MATLAB\R2011a\extern\lib\win64\microsoft\libemlrt.lib" "F:\MATLAB\R2011a\lib\win64\libippmwipt.lib"

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) $(AUXLDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS) $(MEXLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

