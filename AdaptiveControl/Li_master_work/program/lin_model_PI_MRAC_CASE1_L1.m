clc
clear
%open('parameter');

global mode
global AA;
global Ar;
global Am;
global BB;
global CC;
global DD;
hover = 1;
cruise = 2;
mode = 1;

run('parameter');
%--------- Nominal plant model-----------
sys_orig = ss(Ar,BB,CC,DD);
%sys_orig = ss(AAt,[BB G],CC,[DD H]);
%--------------LQR Computing----------------
% Qr = [
%      1 0 0 0 0 0 0 0 0 0 0
%      0 10 0 0 0 0 0 0 0 0 0
%      0 0 1 0 0 0 0 0 0 0 0
%      0 0 0 1 0 0 0 0 0 0 0
%      0 0 0 0 10 0 0 0 0 0 0
%      0 0 0 0 0 1e4 0 0 0 0 0
%      0 0 0 0 0 0 1 0 0 0 0
%      0 0 0 0 0 0 0 1e1 0 0 0
%      0 0 0 0 0 0 0 0 1 0 0
%      0 0 0 0 0 0 0 0 0 1 0
%      0 0 0 0 0 0 0 0 0 0 1];
Qr = eye(11);
Rr = eye(4);


[Kr,Sr,Er] = lqr(Ar,BB,Qr,Rr);

Am=Ar-BB*Kr;
bm = -(CC*inv(Am))\eye(11);
%------end of LQR Computing-----------



%------------Test------------------------
unmodeled = 1; % -1 
tau = 0.01; % time delay.
pulse = 1;
noise = 0.1;
omega = 10;
gamma = 1e4;
TIME=20;
x0 = zeros(11,1);
%x0 = [15 0 0 0 0 0 0 0 0 0 0]';
x_hat0 = x0;
theta_hat0 = eye(11);
%open('lin_model_PI_MRAC_Sim_CASE1_L1');
sim('lin_model_PI_MRAC_Sim_CASE1_L1');
run('compute_u')

