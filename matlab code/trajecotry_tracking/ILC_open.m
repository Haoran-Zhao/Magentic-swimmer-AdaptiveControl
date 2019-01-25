close all
clear all
%circle X Y Z
wp = plotCircle([0 0 0], [0 0 0], 30);

%variables
iters = 30000; %control steps
spacingDist = 0.5; % in mm.  Make smaller to get more points
var = 0.5; %variance of guassin
control_hist = zeros(size(wp,1),1,3);
error_p = [0 0 0]';
error_c = [0 0 0]';
error_d = 0;
error_direct = zeros(size(wp,1),3);
error = NaN*ones(iters,1);
error_h = NaN*ones(iters,1);
error_list = NaN*ones(size(wp,1),100);
error_ind = ones(size(wp,1),1);

% model: gravity pulls on our 2nd order system.
x0 = [0,0,-40,0,0,0]';  %inital conditions: [x,y,z,vx,vy,vz]
u = [0 0 0];
X = repmat(x0, 1,iters); % state

mg = 50; %N
Dt = 0.02; %seconds
Drag = 0.9;
thrust  = 100; %N

%cl pid term
Kp =1;
Ki = 0;
Kd = 0;
errInt = [0;0;0];

% This while loop evenly spaces the points along the trajectory
smallnumber = .02;  % make this smaller to get more waypoints
w2o = interp1(1:numel(wp(:,1)),wp,1:smallnumber:numel(wp(:,1)),'spline');
w2 = w2o(1:2,:);
c1 = 2;
c2 = 1;

while c1< size(w2o,1)
    if norm( w2(c2,:)- w2o(c1,:) ) > spacingDist
        c2=c2+1;
        w2(c2,:) = w2o(c1,:);
    end
    c1=c1+1;
end
w2(c2+1,:)  =  w2(1,:);
w2ILC = wp;

%%%%%%%%%%%%%% PLOTTING
figure(1);clf
subplot(2,2,1);
plot3(w2(:,1),w2(:,2),w2(:,3),'linewidth',.1 );
hold on
plot3(wp(:,1),wp(:,2),wp(:,3),'.k' );

% ANIMATE
hrpath = plot3(X(1,1),X(2,1),X(3,1),'r','linewidth',1);
hrobot = plot3(X(1,1),X(2,1),X(3,1),'ro','linewidth',1);
hlead = plot3(wp(1,1),wp(1,2),wp(1,3),'bo','linewidth',1);
hdirect = quiver3(X(1,1),X(2,1),X(3,1),u(1),u(2),u(3));
% hILC = plot3(w2ILC(:,1),w2ILC(:,2),w2ILC(:,3),'m','linewidth',.2 );

%axis([-40 40 -40 40 -40 40])
axis equal
htit = title('0');
subplot(2,2,2);
hILC = plot3(w2ILC(:,1),w2ILC(:,2),w2ILC(:,3),'m','linewidth',.2 );
axis([-40 40 -40 40 -40 40])

subplot(2,2,3);
herr = plot(Dt*(1:iters),error,'linewidth',1);
xlabel('time (s)');ylabel('error (mm)');

subplot(2,2,4);
herr_h = plot(Dt*(1:iters),error_h,'linewidth',1);
xlabel('time (s)');ylabel('error_m (mm)');
%%%%%%%%%%%%%% END PLOTTING

%%%%%%%%%%%%%%Main Loop
for i = 1: iters-1
    % lead point index
    ind = mod(i+5, size(w2ILC,1));
    if ind == 0
        ind = size(w2ILC,1);
    end
    cp = w2ILC(ind,:);
    %ILC part: change the wp values via a smooth bump to the values.
    error_c = cp - X(1:3,i);
    error(i) = norm( cp - X(1:3,i));
    error_list(ind,error_ind(ind,1)) = error(i);
    error_ind(ind)= error_ind(ind)+1; 
    %rangeInfluence = round(rangeInfluence*tanh(error(i)));
    if i<=1000
        error_m = mean(error(1:i));
    else
        error_m = mean(error(i-999:i)); 
    end
    error_h(i) = error_m;
    cp = w2ILC(ind,:)';
    T = (iters-i)/iters;
    error_cpt = error_list(ind,~isnan(error_list(ind,:))); %closest point error history
    if length(error_cpt) >1
    error_d = error_cpt(end-1)-error_cpt(end); %error deriviative
    end
    
    if (error_ind(ind)-1) ==1
        learningRate_entro = 0.5;
    %     elseif error_d<0
    %         learningRate_direct =1tanh(error_d);
    else
        learningRate_entro = tanh(error_d);
    end
    
    learningRate = 2*exp(-error_m/T); %simulated annealing
    %w2ILC(ind,:) = w2ILC(ind,:) + learningRate.*(wp(ind,:)-X(1:3,i)');
    p2c_vector = wp(ind,:)-X(1:3,i)';
    w2ILC(ind,:) = w2ILC(ind,:) + abs(learningRate_entro).*learningRate.*p2c_vector;
    
% look ahead
    ind_ahead = ind+ 1;
    if ind_ahead >size(wp,1)
        ind_ahead = ind_ahead-size(wp,1);
    end
    
    wpDiff = cp - X(1:3,i); %direction between waypoints
    errInt = errInt+ (cp - X(1:3,i)); %integral term
     
    % deriv term
    if i ==1
        vel = [0;0;0];
    else
        vel = X(1:3,i)-X(1:3,i-1);
    end
    orient = wpDiff/norm(wpDiff);
    control_cl = Kp*norm(cp - X(1:3,i)) + Ki*norm(errInt) - Kd*norm(vel);
    control =  control_cl;
    % controller steers the thrust (only controls the orientation)
    disp(control/norm(control))
    u = thrust*control_cl*orient;
    
    
    
    X(:,i+1) = [ ...
        X(1,i) + Drag*Dt*X(4,i) + 1/2*Dt*Dt*u(1);
        X(2,i) + Drag*Dt*X(5,i) + 1/2*Dt*Dt*u(2);
        X(3,i) + Drag*Dt*X(6,i) + 1/2*Dt*Dt*(u(3)-mg);
        Drag*X(4,i) + Dt*u(1);
        Drag*X(5,i) + Dt*u(2);
        Drag*X(6,i) + Dt*(u(3)-mg)];
    
    %update
    if mod(i,20) ==0
        set( hdirect, 'Xdata',X(1,i),'Ydata',X(2,i),'Zdata',X(3,i),'Udata',0.25*u(1),'Vdata',0.25*u(2),'Wdata',0.25*u(3));
        set( hrpath,  'Xdata', X(1,1:i),'Ydata',X(2,1:i),'Zdata',X(3,1:i));
        set( hrobot, 'Xdata',X(1,i),'Ydata',X(2,i),'Zdata',X(3,i));
        set( hlead, 'Xdata',wp(ind,1),'Ydata',wp(ind,2),'Zdata',wp(ind,3));
        set( hILC, 'Xdata',[w2ILC(:,1);w2ILC(1,1)],'Ydata',[w2ILC(:,2);w2ILC(1,2)],'Zdata',[w2ILC(:,3);w2ILC(1,3)] );
        set(htit,'String',num2str(i));
        set(herr,'Ydata',error);
        set(herr_h,'Ydata',error_h);
        drawnow
    end
    
    error_p = error_c;
    
    if ~mod(iters,1000)==0
        pause(1)
    end
end

%%%%%%%%%%%%%%functions
function points = plotCircle(center,normal,radius)
theta=0:0.01:2*pi;
v=null(normal);
points=repmat(center',1,size(theta,2))+radius*(v(:,1)*cos(theta)+v(:,2)*sin(theta));
points = points';
% plot3(points(:,1),points(:, 2),points(:,3),'r-');
end

function [cp,ind] = closestPt(arr,pt) % pick the closest point in arr to py
[~,ind] = min( sum( (arr - repmat(pt',size(arr,1),1)).^2,2));
cp = arr(ind,:)';
end