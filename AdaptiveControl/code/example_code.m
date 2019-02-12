%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    Model Reference Adaptive Control with Sigma Modification    %
%                   Wing Rock Dynamics Example                   %
%                Tansel Yucelen (tansel@gatech.edu)              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Simulation Setup 
clc;        % Clear command window
clear all;  % Clear variables and functions from memory
close all;  % Close all figures
ft = 100;   % Simulation final time (seconds)
dt = 0.005; % Simulation sampling time for calculations (seconds)

%% Switches
uncertainty_on = 1; % If = 0, then there is no uncertainty in the
                    % system; if = 1, then there is uncertainty
                    % in the system.=
adaptation_on = 1;  % If = 0, then there is no adaptation in the
                    % controller; if = 1, then there is adapta-
                    % tion in the controller

%% Uncertain System
   % xdot = A*x + B*[u + W'*beta(x)]
   % beta(x) = [x(1); x(2); |x(1)|*x(2); |x(2)|*x(2); x(1)^3]
A = [0 1; 0 0];        % System matrix A (known)
B = [0; 1];            % Input matrix B (known)
W = [0.1414; 0.5504; -0.0624; ... 
     0.0095; 0.0215];  % Ideal weight (unknown)
 
%% Reference Model
   % xmdot = Am*xm + Bm*r
wn = 0.4;   % Reference model natural frequency
rn = 0.707; % Reference model damping
Am = [0 1;-wn^2 -2*wn*rn];  % Reference model matrix Am (designed)
Bm = [0; wn^2];             % Reference model matrix Bm (designed)

%% Nominal Control Gains
K1  = pinv(B)*(A-Am); % Nominal feedback gain K1 
K2  = pinv(B)*Bm;     % Nominal feedforward gain K2

%% Adaptive Control Learning Rate
P     = lyap(Am',eye(2)); % Solution of Lyapunov equation
Gamma = 1;               % Learning rate
                    
%% Numerical Simulation
x  = [0; 0];            % Initial value for system states
xm = [0; 0];            % Initial value for reference model states
What = [0; 0; 0; 0; 0]; % Initial value for weight update law

    % Simulation
    index = 1;
    for k = 0:dt:ft;
        
        % Generate reference command r(t)
        if k <= 25;            r = +30*pi/180; end;
        if k >  25 && k <= 50; r = -30*pi/180; end;
        if k >  50 && k <= 75; r = +30*pi/180; end;
        if k >  75;            r = -30*pi/180; end;    

        % Basis function
        beta = [x(1); x(2); abs(x(1))*x(2); ... 
                abs(x(2))*x(2); x(1)^3];
        
        % Controller
        un  = -K1*x + K2*r;             % Nominal controller
        uad = What'*beta;               % Adaptive controller
        u   = un - uad*(adaptation_on); % Augmentation
    
        % Weight update law
        What = [Gamma*(beta*(x-xm)'*P*B)]*dt + What;
        
        % Reference model
        xm = [Am*xm + Bm*r]*dt + xm;
        
        % Uncertain system
        x = [A*x + B*(u+W'*beta*(uncertainty_on))]*dt + x;
            
        % Save the data
        r_rec(index,1:1)     = r*180/pi;
        x_rec(index,1:2)     = x*180/pi;
        xm_rec(index,1:2)    = xm*180/pi;
        u_rec(index,1:1)     = u*180/pi;
        un_rec(index,1:1)    = un*180/pi;
        uad_rec(index,1:1)   = uad*180/pi;
        wb_rec(index,1:1)    = W'*beta*uncertainty_on;
        whatb_rec(index,1:1) = What'*beta*adaptation_on;
        t_rec(index,1:1)     = k;
        
        % Go to next iteration
        index = index + 1;
        
    end;

%% Generate Plots
subplot(2,2,1); hold on; box on;
p1 = plot(t_rec,r_rec,'k-');
p2 = plot(t_rec,xm_rec(:,1),'r-');
p3 = plot(t_rec,x_rec(:,1),'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
set(p3,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$r(t)$, \ $x_\mathrm{m1}(t)$, \ $x_1(t)$ \ [deg]'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

subplot(2,2,2); hold on; box on;
p1 = plot(t_rec,xm_rec(:,2),'r-');
p2 = plot(t_rec,x_rec(:,2),'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$x_\mathrm{m2}(t)$, \ $x_2(t)$ \ [deg/s]'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

subplot(2,2,3); hold on; box on;
p1 = plot(t_rec,u_rec,'k-');
p2 = plot(t_rec,un_rec,'r-');
p3 = plot(t_rec,uad_rec,'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
set(p3,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$r(t)$, \ $u_\mathrm{n}(t)$, \ $u_\mathrm{ad}(t)$ \ [deg]'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

subplot(2,2,4); hold on; box on;
p1 = plot(t_rec,wb_rec,'r-');
p2 = plot(t_rec,whatb_rec,'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$W^T\beta(x(t))$, \ $\hat{W}^T(t)\beta(x(t))$'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;