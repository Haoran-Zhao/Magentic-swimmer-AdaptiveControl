function[sys, x0, str, ts]=beta_cr(t, x, u, flag)
%estimated data...to be updated

r_cr=0.5;
r_crl=0.42;
Icr=0.08;
c_cr=0.06;
a_cr=3;
rho=1.29;
Omega=870/60*2*pi;
gamma=rho*c_cr*a_cr*(r_cr)^4/Icr;
M1=gamma*( (r_crl/r_cr)^4-1)/4;
M2=gamma*(-(r_crl/r_cr)^4+1)/(4*Omega);

B=[-0.5*Omega^2*M1 0 -2*Omega -0.5*Omega^2*M2;
   0 -0.5*Omega^2*M1 -0.5*Omega^2*M2 2*Omega];

A=[0 0.5*Omega^2*M1 -0.5*Omega^2*M2 -2*Omega;
   -0.5*Omega^2*M1 0 2*Omega -0.5*Omega^2*M2];



switch flag,

  case 0
    [sys,x0,str,ts]=mdlInitializeSizes(A,B);

    case 3
    sys=mdlOutputs(t,x,u,A,B);
    
    case {1, 2, 4, 9}
    sys=[];

  otherwise
    error(['Unhandled flag =', num2str(flag)]);

end


function [sys,x0,str,ts]=mdlInitializeSizes(A,B)

sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 4;
sizes.NumInputs      = 8;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed

sys = simsizes(sizes);

x0  = [];
str = [];
ts  = [-1 0];


function sys=mdlOutputs(t,x,u,A,B)
%inputs:
Asw1=[1 0 0 0 0 0 0 0]*u;
Bsw1=[0 1 0 0 0 0 0 0]*u;
p=[0 0 1 0 0 0 0 0]*u;
q=[0 0 0 1 0 0 0 0]*u;
beta1c=[0 0 0 0 1 0 0 0]*u;
beta1s=[0 0 0 0 0 1 0 0]*u;
beta1c_dot=[0 0 0 0 0 0 1 0]*u;
beta1s_dot=[0 0 0 0 0 0 0 1]*u;

% Outputs
sys(1)=[1 0]*(B*[Asw1;Bsw1;p;q]);  %B*u_(11)
sys(2)=[0 1]*(B*[Asw1;Bsw1;p;q]);  %B*u_(21)
sys(3)=[1 0]*(A*[beta1c;beta1s;beta1c_dot;beta1s_dot]); %A*beta1c_dot
sys(4)=[0 1]*(A*[beta1c;beta1s;beta1c_dot;beta1s_dot]); %A*beta1s_dot




 