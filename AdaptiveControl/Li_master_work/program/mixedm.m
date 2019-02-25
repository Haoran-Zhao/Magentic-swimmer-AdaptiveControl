function [sys, x0, str, ts]=mixedm(t,x,u,flag)
dperiod=1;
doffset=0;
switch flag,
    case 0
        [sys, x0, str, ts]=mdlInitializeSizes(dperiod, doffset);
    case 1
        sys=mdlDerivatives(t,x,u);
    case 2
        sys=mdlUpdate(t,x,u,dperiod, doffset);
    case 3
        sys=mdlOutputs(t,x,u,doffset,dperiod);
    case{4,9}
        sys=[];
    otherwise
        error(['unhandled flag=',num2str(flag)]);
end

function [sys, x0, str, ts]=mdlInitializeSizes(dperiod,doffset)
sizes=simsizes;
sizes.NumContStates=1;
sizes.NumDiscStates=1;
sizes.NumOutputs=1;
sizes.NumInputs=1;
sizes.DirFeedthrough=0;
sizes.NumSampletimes=2;
sys=simsizes(sizes);
x0=ones(2,1);
str=[];
ts=[0,0;dperiod,doffset];

function sys=mdlDerivatives(t,x,u)
sys=u;

function sys=mdlUpdate(t,x,u,dperiod,doffset)
if abs(round((t-doffset)/dperiod)-(t-doffset)/dperiod)<1e-8
    sys=x(1);
else
    sys=[]
end

function sys=mdlOutputs(t,x,u,doffset,dperiod)
if abs(round((t-doffset)/dperiod)-(t-doffset)/dperiod)<1e-8
    sys=x(2);
else
    sys=[];
    
end
