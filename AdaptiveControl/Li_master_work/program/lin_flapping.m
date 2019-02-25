function[sys, x0, str, ts]=lin_flapping(t, x, u, flag)
%estimated data...to be updated

R=5.05*0.3048; 
Omega=142;%870/60*2*pi ; 

rho =1.29;  
a=6.0 ; 
B=2; 
c=0.354*0.3048;
Ib=0.86754;
g=9.81 ;
e =0.0; 
mb=0.3;
Mb=(mb*R^2)/(2)*(1-e/R)^2*g ;
K=100;

switch flag,

  case 0
    [sys,x0,str,ts]=mdlInitializeSizes(t,x,u,B,rho,a,e,c,Ib,R,g,Omega,K,Mb);

    case 3
    sys=mdlOutputs(t,x,u,B,rho,a,e,c,Ib,R,g,Omega,K,Mb);
    
    case {1, 2, 4, 9}
    sys=[];

  otherwise
    error(['Unhandled flag =', num2str(flag)]);

end


function [sys,x0,str,ts]=mdlInitializeSizes(t,x,u,B,rho,a,e,c,Ib,R,g,Omega,K,Mb)

sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 2;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed

sys = simsizes(sizes);

x0  = [];
str = [];
ts  = [-1 0];


function sys=mdlOutputs(t,x,u,B,rho,a,e,c,Ib,R,g,Omega,K,Mb)

%inputs:

bu=0;bv=0;bw=0;
p=0;q=0;

A1=[1 0]*u;
B1=[0 1]*u;
theta_0=4/180*pi;
vi=4.7616;


a11=0.5*rho*a*c*(R-e)^2*Omega^2*R^2*(e/(6*R)-1/4);
a12=-Omega^2*(Ib+e*Mb/g)+Ib*Omega^2-K;
a21=Omega^2*(Ib+e*Mb/g)-Ib*Omega^2+K;
a22=0.5*rho*a*c*(R-e)^2*Omega^2*R^2*(e/(6*R)-1/4);


b1=0.5*rho*a*c*(R-e)^2*Omega^2*R^2*( (bu*e/(3*Omega*R^2)+2*bu/(3*R*Omega))*theta_0+((-0.375*bu^2/(Omega^2*R^2))-0.25-e/(6*R)-bv^2/(8*Omega^2*R^2))*B1-0.25*bu*bv*A1/(Omega^2*R^2)-0.5*vi*bu/(Omega^2*R^2)+(e/(Omega*R*6)+1/(4*Omega))*p+0.5*bw*bu/(Omega^2*R^2))-2*q*Omega*Ib;
b2=0.5*rho*a*c*(R-e)^2*Omega^2*R^2*(-(bv*e/(3*Omega*R^2)+2*bv/(3*R*Omega))*theta_0-((-0.375*bv^2/(Omega^2*R^2))-0.25-e/(6*R)-bu^2/(8*Omega^2*R^2))*A1+0.25*bu*bv*B1/(Omega^2*R^2)+0.5*vi*bv/(Omega^2*R^2)+(e/(Omega*R*6)+1/(4*Omega))*q-0.5*bw*bv/(Omega^2*R^2))-2*p*Omega*Ib;
b1=-b1;
b2=-b2;

beta_1c=[1 0]*([a11 a12;a21 a22]\[b1;b2]);
beta_1s=[0 1]*([a11 a12;a21 a22]\[b1;b2]);




%Outputs:

sys(1)=beta_1c;
%beta_1s:
sys(2)=beta_1s;



