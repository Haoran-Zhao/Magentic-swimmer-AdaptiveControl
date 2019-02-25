function[sys, x0, str, ts]=beta_crS(t, x, u, flag)
%estimated data...to be updated

r_cr=0.325;%0.5;
r_crl=0.22;%0.42;
Icr=0.006;
c_cr=0.06;
a_cr=3;
rho=1.29;
Omega=142;%870/60*2*pi;
gamma=rho*c_cr*a_cr*(r_cr)^4/Icr;
M1=gamma*( (r_crl/r_cr)^4-1)/4;
M2=gamma*(-(r_crl/r_cr)^4+1)/(4*Omega);

% B=[-0.5*Omega^2*M1 0 -2*Omega -0.5*Omega^2*M2;
%    0 -0.5*Omega^2*M1 -0.5*Omega^2*M2 2*Omega];
% 
% A=[0 0.5*Omega^2*M1 -0.5*Omega^2*M2 -2*Omega;
%    -0.5*Omega^2*M1 0 2*Omega -0.5*Omega^2*M2];



switch flag,

  case 0
    [sys,x0,str,ts]=mdlInitializeSizes(M1,M2,Omega);

    case 1
        sys=mdlDerivatives(t,x,u,M1,M2,Omega);
        
    case 3
    sys=mdlOutputs(t,x,u);
    
    case {2, 4, 9}
    sys=[];

  otherwise
    error(['Unhandled flag =', num2str(flag)]);

end


function [sys,x0,str,ts]=mdlInitializeSizes(M1,M2,Omega)

sizes = simsizes;
sizes.NumContStates  = 4;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 2;
sizes.NumInputs      = 4;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed

sys = simsizes(sizes);

x0  = [0;0;0;0];
str = [];
ts  = [0 0];

function sys=mdlDerivatives(t,x,u,M1,M2,Omega)
%inputs:
Asw1=[0 0 1 0]*u;
Bsw1=[0 0 0 1]*u;
p=[1 0 0 0]*u;
q=[0 1 0 0]*u;
% xdot(1)=x(3);
% xdot(2)=x(4);
% xdot(3)=[1 0]*(B*[Asw1;Bsw1;p;q])+[1 0]*(A*[x(1);x(2);x(3);x(4)]);
% xdot(4)=[0 1]*(B*[Asw1;Bsw1;p;q])+[0 1]*(A*[x(1);x(2);x(3);x(4)]);


xdot(3)=-Omega^(2)*(0.5*M1*Asw1+2*p/Omega+0.5*M2*q-0.5*M1*x(2)+2*x(4)/Omega+0.5*M2*x(3));
xdot(4)=-Omega^(2)*(0.5*M1*Bsw1+0.5*M2*p-2*q/Omega+0.5*M1*x(1)-2*x(3)/Omega+0.5*M2*x(4));
xdot(1)=x(3);
xdot(2)=x(4);

sys=[xdot(1);xdot(2);xdot(3);xdot(4)];
%end mdlDerivatives

function sys=mdlOutputs(t,x,u)


% Outputs
sys(1)=x(1);  %beta_cr1c
sys(2)=x(2);  %beta_cr1s

%end mdlOutputs




