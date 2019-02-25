function[sys, x0, str, ts]=thrust(t, x, u, flag)
%estimated data...to be updated

R=5.05*0.3048; 
Omega=870/60*2*pi ; 
rho =1.29;  
a=6.0 ; 
B=2; 
c=0.354*0.3048;
theta_twist=0;
switch flag,

  case 0
    [sys,x0,str,ts]=mdlInitializeSizes(t,x,u,theta_twist,Omega,rho,R,a,B,c);

    case 3
    sys=mdlOutputs(t,x,u,theta_twist,Omega,rho,R,a,B,c);
    
    case {1, 2, 4, 9}
    sys=[];

  otherwise
    error(['Unhandled flag =', num2str(flag)]);

end


function [sys,x0,str,ts]=mdlInitializeSizes(t,x,u,theta_twist,Omega,rho,R,a,B,c)

sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 7;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed

sys = simsizes(sizes);

x0  = [];
str = [];
ts  = [-1 0];


function sys=mdlOutputs(t,x,u,theta_twist,Omega,rho,R,a,B,c)
%inputs:
bu=[1 0 0 0 0 0 0]*u;
bv=[0 1 0 0 0 0 0]*u;
bw=[0 0 1 0 0 0 0]*u;
beta_1c=[0 0 0 1 0 0 0]*u;
beta_1s=[0 0 0 0 1 0 0]*u;
theta_col=[0 0 0 0 0 1 0]*u;
vi0=[0 0 0 0 0 0 1]*u;
A=pi*R^2;
w_r=bw+beta_1c*bu-beta_1s*bv;
w_b=w_r+(2/3)*Omega*R*(theta_col+theta_twist);

 T_MR=-1;
 vi=vi0;
vi2=vi^2;

    for ii=1:5
    T_MR=(w_b-sqrt(vi2))*(rho*Omega*R*a*B*c*R)/4;
    v2=bu^2+bv^2+w_r*(w_r-2*vi);
    vi2=sqrt((v2/2)^2+(T_MR/(2*rho*A))^2)-v2/2;
    vi=sqrt(vi2);
end

%Outputs:
% w_r=bw+bu*beta_1c+bv*beta_1s;
% Vhat2=bu^2+bv^2+(bw*beta_1s*beta_1c)^2;
% for ii=1:5
% T_MR=1/6*rho*Omega^2*R^3*B*c*a*((theta_col+0.75*theta_twist)-vi+w_r);
% vi=sqrt(-0.5*(Vhat2+w_r*(w_r-2*vi))+sqrt((T_MR/(2*rho*A))^2+(0.5*(Vhat2+w_r*(w_r-2*vi)))^2));
% end
sys(1)=T_MR;
sys(2)=vi;



