%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    Model Reference Adaptive Control with Sigma Modification    %
%         first order system without uncertainties example       %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Simulation Setup 
clc;        % Clear command window
clear all;  % Clear variables and functions from memory
close all;  % Close all figures
ft = 10;   % Simulation final time (seconds)
dt = 0.02; % Simulation sampling time for calculations (seconds)
reference = 0;

%% Uncertain System
   % xdot = A*x + B*[u + W'*beta(x)]
   % beta(x) = [x(1); x(2); |x(1)|*x(2); |x(2)|*x(2); x(1)^3]
A = 1;        % System matrix A (known)
B = 3;            % Input matrix B (known)
 
%% Reference Model
   % xmdot = Am*xm + Bm*r
Am = -4;  % Reference model matrix Am (designed)
Bm = 4;             % Reference model matrix Bm (designed)

%% Nominal Control Gains
K1  = 0; % Nominal feedback gain K1 
K2  = 0;     % Nominal feedforward gain K2
                    
%% Numerical Simulation
x  = [0];            % Initial value for system states
xm = [0];            % Initial value for reference model states

    % Simulation
    index = 1;
    for k = 0:dt:ft
        
        % Generate reference command r(t)
        if reference == 1
            r = 4;
        else
            r = 4*sin(3*k);
        end

        
        % Controller

        u   = K1*x + K2*r; % Augmentation
        
        % Reference model
        xm = [Am*xm + Bm*r]*dt + xm;
        
        % Uncertain system
        x = [A*x + B*u]*dt + x;
        
        %error
        e = x - xm;
        
        % control parameter
        K1 = K1 - 2*x'*e*dt;
        K2 = K2 - 2*r*e*dt;
            
        % Save the data
        r_rec(index,1)     = r;
        x_rec(index,1)     = x;
        xm_rec(index,1)    = xm;
        k1_rec(index,1) = K1;
        k2_rec(index,1) = K2;
        t_rec(index,1)     = k;
        % Go to next iteration
        index = index + 1;
        
    end

%% Generate Plots
subplot(3,1,1); hold on; box on;
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

subplot(3,1,2); hold on; box on;
p1 = plot(t_rec,-5/3*ones(size(t_rec)),'r-');
p2 = plot(t_rec,k1_rec(:,1),'b-');
set(p1,'LineWidth',2);
set(p2,'LineWidth',2);
xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$k1_x(t)$, \ $k2_\mathrm{m}(t)$'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

subplot(3,1,3); hold on; box on;
p1 = plot(t_rec,4/3*ones(size(t_rec)),'k-');
p2 = plot(t_rec,k2_rec,'r-');

set(p1,'LineWidth',2);
set(p2,'LineWidth',2);

xlabel({'$t$ [s]'},'FontSize',16,'Interpreter','latex'); 
ylabel({'$k2_x(t)$, \ $k2_\mathrm{m}(t)$'}, ...
       'FontSize',16,'Interpreter','latex');
axis tight;

