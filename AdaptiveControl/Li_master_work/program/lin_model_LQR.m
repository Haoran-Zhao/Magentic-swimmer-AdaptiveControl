clc
clear
%open('parameter');

global mode
global AA;
global BB;
global CC;
global DD;

hover0 = 0;
mode = hover0;
run('parameter');


%--------------LQR Computing----------------
Qr=[
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

Rr=[ 1 0 0 0
      0 10 0 0
      0 0 1 0
      0 0 0 1];

[Kr,Sr,Er]=lqr(AA,BB,Qr,Rr);


%------end of LQR Computing-----------
Am = AA - BB*Kr;
sys = ss(Am,BB,CC,DD);


%------------Test------------------------

t=0:0.01:10;
t=t';
%u = zeros(size(t,1),4);
[t,u]=gensig('pulse',4,10,0.05);
x0 = [3 3 3 0 0 0 0 0 0 0 0]';

[out,tout,xout]=lsim(sys,u,t,x0);
y=xout(:,:)';
plot(tout,y(1:3,:));i
%axis([0 20 -0.4 1.2])

