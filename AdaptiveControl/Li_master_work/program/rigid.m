function [sys,x0,str,ts] = rigid(t,x,u,flag)

switch flag,

  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes(m,i_x,i_y,i_z);

  %%%%%%%%%%%%%%%
  % Derivatives %
  %%%%%%%%%%%%%%%
  case {1, 2, 4, 9}
      sys=[];
      
  case 3,
    sys=mdlOutputs(t,x,u,m,i_x,i_y,i_z);

  otherwise
    error(['Simulink:blocks:unhandledFlag', num2str(flag)]);

end

%
function [sys,x0,str,ts]=mdlInitializeSizes(m,i_x,i_y,i_z)

sizes = simsizes;

sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 12;
sizes.NumInputs      = 15;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed

sys = simsizes(sizes);

%
% initialize the initial conditions
%
x0  = [];

%
% str is always an empty matrix
%
str = [];

%
% initialize the array of sample times
%
ts  = [-1 0];

function sys=mdlOutputs(t,x,u,m,i_x,i_y,i_z)
phi=u(1);
theta=u(2);
psi=u(3);
fx=u(4);
fy=u(5);
fz=u(6);
p=u(7);
q=u(8);
r=u(9);
L=u(10);
M=u(11);
N=u(12);
ux=u(13);
uy=u(14);
uz=u(15);

eu=(cos(theta)*cos(psi)*ux+(sin(phi)*sin(theta)*cos(psi)-cos(phi)*sin(psi))*uy+(cos(phi)*sin(theta)*cos(psi)+sin(phi)*sin(psi))*uz);

ev=(cos(theta)*sin(psi)*ux+(sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi))*uy+(cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi))*uz);

ew=(-sin(theta)*ux+sin(phi)*cos(theta)*uy+cos(phi)*cos(theta)*uz);

phi_d=p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r;

theta_d=cos(phi)*q-sin(phi)*r;

psi_d=(sin(phi)/cos(theta))*q+(cos(phi)/cos(theta))*r;

p_d=(i_y*q*r-i_z*q*r+L)/i_x;

q_d=(-(i_x*p*r-i_z*p*r-M))/i_y;

r_d=(i_x*p*q-i_y*p*q+N)/i_z;

bu_d=1/m*fx-q*uz+r*uy;

bv_d=1/m*fy+p*uz-r*ux;

bw_d=1/m*fz-p*uy+q*ux;

%Outputs:
sys(1)=eu;
sys(2)=ev;
sys(3)=ew;
sys(4)=phi_d;
sys(5)=theta_d;
sys(6)=psi_d;
sys(7)=p_d;
sys(8)=q_d;
sys(9)=r_d;
sys(10)=bu_d;
sys(11)=bv_d;
sys(12)=bw_d;





