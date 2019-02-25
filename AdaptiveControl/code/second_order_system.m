%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    Model Reference Adaptive Control with Sigma Modification    %
%                second order system example                     %
%                Haoran Zhao (hzhao9@uh.edu)                     %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Simulation Setup 
clc;        % Clear command window
clear all;  % Clear variables and functions from memory
close all;  % Close all figures
ft =100;   % Simulation final time (seconds)
dt = 0.02; % Simulation sampling time for calculations (seconds)

%% Switches
uncertainty_on = 1; % If = 0, then there is no uncertainty in the
                    % system; if = 1, then there is uncertainty
                    % in the system
reference = 1;

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
K1  = [0 0]; % Kx initial
K2  = 0;     % Kr initial
k1  = pinv(B)*(A-Am); % Nominal feedback gain K1 
k2  = pinv(B)*Bm;     % Nominal feedforward gain K2
%% Adaptive Control Learning Rate
P     = lyap(Am',eye(2)); % Solution of Lyapunov equation
Gamma = 10;               % Learning rate
        
%% Numerical Simulation
x  = [0; 0];            % Initial value for system states
xm = [0; 0];            % Initial value for reference model states
What = [0; 0; 0; 0; 0]; % Initial value for weight update law

    % Simulation
    index = 1;
    for k = 0:dt:ft
        
        % Generate reference command r(t)
        if reference == 1
            r = 4;
        else
            r = 4*sin(3*k);
        end

        % Basis function
        beta = 0.1*[x(1); x(2); abs(x(1))*x(2); ... 
                abs(x(2))*x(2); x(1)^3];
        
        % Controller
        u   = K1*x + K2*r + What'*beta*(uncertainty_on); % Augmentation
    
        % Reference model
        xm = [Am*xm + Bm*r]*dt + xm;
        
        % Uncertain system
        x = [A*x + B*(u+W'*beta*(uncertainty_on))]*dt + x;
        
        %error
        e = x-xm;
        
        % adaption parameter
        K1 = K1 - (Gamma*eye(2)*x*e'*P*B*dt)';
        K2 = K2 - Gamma*r*e'*P*B*dt;
        What = What - Gamma*eye(5)*beta*e'*P*B*dt;
        
        % Save the data
        r_rec(index,1)     = r;
        x_rec(index,1:2)     = x';
        xm_rec(index,1:2)    = xm';
        k1_rec(index,1:2) = K1;
        k2_rec(index,1) = K2;
        t_rec(index,1)     = k;
        
        % Go to next iteration
        index = index + 1;
        if index ==316
            pause('on')
        end
    end

%% Generate Plots
subplot(4,1,1); hold on; box on;
p1 = plot(t_rec,r_rec,'k-');
p2 = plot(t_rec,xm_rec(:,1),'r-');
p3 = plot(t_rec,x_rec(:,1),'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
set(p3,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$r(t)$, \ $x_\mathrm{m}(t)$, \ $x(t)$'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

subplot(4,1,2); hold on; box on;
p1 = plot(t_rec,k1(1)*ones(size(t_rec)),'r-');
p2 = plot(t_rec,k1_rec(:,1),'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$k1_{x_1}(t)$, \ $k1_\mathrm{m1}(t)$'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

subplot(4,1,3); hold on; box on;
p1 = plot(t_rec,k1(2)*ones(size(t_rec)),'r-');
p2 = plot(t_rec,k1_rec(:,2),'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$k1_{x_2}(t)$, \ $k1_\mathrm{m2}(t)$'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

subplot(4,1,4); hold on; box on;
p1 = plot(t_rec,k2*ones(size(t_rec)),'k-');
p2 = plot(t_rec,k2_rec,'r-');

set(p1,'LineWidth',2);
set(p2,'LineWidth',2);

xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$k2_x(t)$, \ $k2_\mathrm{m}(t)$'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;