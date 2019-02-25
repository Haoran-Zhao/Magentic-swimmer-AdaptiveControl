clc
clear
% Global Parameter ---->>  "parameter.m"
%open('parameter');
run('parameter');
global AA;
global Theta_a;
global Ar;
global Am;
global BB;
global CC;
global DD;
global Gn;
global Hn;
global nx;
global ny;
global u;
global x0;

%----------Introduce Disturbance-------------
G = eye(size(AA,1));
H = eye(size(CC,1));
w = randn(size(AA,1),1);
v = randn(size(CC,1),1);
%---------------------------------------------




%--------- Nominal plant model-----------
sys_orig = ss(Ar,BB,CC,DD);
%sys_orig = ss(AAt,[BB G],CC,[DD H]);
%--------------LQR Computing----------------
Qr = [
     1 0 0 0 0 0 0 0 0 0 0
     0 10 0 0 0 0 0 0 0 0 0
     0 0 1 0 0 0 0 0 0 0 0
     0 0 0 1 0 0 0 0 0 0 0
     0 0 0 0 10 0 0 0 0 0 0
     0 0 0 0 0 1e4 0 0 0 0 0
     0 0 0 0 0 0 1 0 0 0 0
     0 0 0 0 0 0 0 1e1 0 0 0
     0 0 0 0 0 0 0 0 1 0 0
     0 0 0 0 0 0 0 0 0 1 0
     0 0 0 0 0 0 0 0 0 0 1];

Rr = [ 1 0 0 0
      0 10 0 0
      0 0 1 0
      0 0 0 1];

[Kr,Sr,Er] = lqr(Ar,BB,Qr,Rr);

Am=Ar-BB*Kr;
bm = -(CC*inv(Am))\eye(11);
%------end of LQR Computing-----------



%------------Test------------------------

gamma = 1e6;
TIME=10;
x_hat0 = 0;
x0 = zeros(11,1);
x_hat0 = x0;
theta_hat0 = eye(11);
open('lin_model_PI_MRAC_Sim_CASE1');
sim('lin_model_PI_MRAC_Sim_CASE1');


