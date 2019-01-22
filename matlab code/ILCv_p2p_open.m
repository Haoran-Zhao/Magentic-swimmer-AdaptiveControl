
% TODO: Loop condition is bad
% only update control points 1x per iteration.

%Z,X,Y
wp = [-37.5000000000000,0,0;-36.5050000000000,0,-8.58000000000000;-32.7890000000000,0,-18.1900000000000;-28.8600000000000,0,-23.9300000000000;-21.7250000000000,0,-30.5660000000000;-12.4100000000000,0,-35.3800000000000;0,0,-37.5000000000000;8.75000000000000,0,-37.5000000000000;11.3200000000000,0,-37.1630000000000;14.9000000000000,0,-35.3800000000000;17.7280000000000,0,-31.9040000000000;18.7500000000000,0,-25.6980000000000;18.7500000000000,0,-18.7500000000000;18.7500000000000,0,-14.0150000000000;18.2850000000000,0,-6.98600000000000;13.4390000000000,0,-1.16800000000000;6.55000000000000,0,0.614000000000000;1.27000000000000,0,5.12200000000000;0,0,12.1430000000000;0,0,23.7500000000000;0,0,27.5000000000000;0,0.874000000000000,31.5800000000000;0,3.80000000000000,35.3400000000000;0,10,37.5000000000000;0,19,37.5000000000000;0,28.8000000000000,37.5000000000000;-0.548000000000000,43.2660000000000,37.5000000000000;-2.92900000000000,47.0710000000000,37.5000000000000;-7.15000000000000,49.5800000000000,37.5000000000000;-11.8160000000000,50,37.5000000000000;-19.6000000000000,50,37.5000000000000;-27.5000000000000,50,37.5000000000000;-31.3200000000000,49.2400000000000,37.5000000000000;-35.4800000000000,46.0270000000000,37.5000000000000;-37.2850000000000,42.0610000000000,37.5000000000000;-37.5000000000000,36.3700000000000,37.5000000000000;-37.5000000000000,19.7500000000000,37.5000000000000;-37.5000000000000,10,37.5000000000000;-37.5000000000000,3.80000000000000,35.3490000000000;-37.5000000000000,0.516000000000000,30.6700000000000;-37.5000000000000,0,20.7190000000000;-37.5000000000000,0,7.89000000000000];
wp = [wp(:,3),wp(:,1),wp(:,2)];
wp(end,:) = wp(1,:); %loop the trajectory
smallnumber = .02;  % make this smaller to get more waypoints
w2o = interp1(1:numel(wp(:,1)),wp,1:smallnumber:numel(wp(:,1)),'spline');

% This while loop evenly spaces the points along the trajectory
w2 = w2o(1:2,:);
c1 = 2;
c2 = 1;
spacingDist = 0.5; % in mm.  Make smaller to get more points
var = 0.5;
% length = 0;
% for i = 2: size(w2o,1)
%     length = length + norm( w2o(i,:)- w2o(i-1,:) );
% end
% display(length)
% return

while c1< size(w2o,1)
    if norm( w2(c2,:)- w2o(c1,:) ) > spacingDist
        c2=c2+1;
        w2(c2,:) = w2o(c1,:);
    end
    c1=c1+1;
end
w2(c2+1,:)  =  w2(1,:);

% avoid the repeat of the last node
wp = w2(1:end-1,:);
w2ILC = wp;


% model: gravity pulls on our 2nd order system.
x0 = [0,0,0,0,0,0]';  %inital conditions: [x,y,z,vx,vy,vz]

iters = 30000; %control steps
X = repmat(x0, 1,iters); % state

mg = 50; %mm/s^2
Dt = 0.02; %seconds
Kp = 1;
Ki = 0;
Kd = 0;

Drag = 0.9;
Speed  = 100; %mm/s
%learningRate = 0.25;

%%%%%%%%%%%%%% PLOTTING
figure(1);clf
subplot(2,2,1);
plot3(w2(:,1),w2(:,2),w2(:,3),'linewidth',.1 );
hold on
plot3(wp(:,1),wp(:,2),wp(:,3),'.k' );

% ANIMATE
hrpath = plot3(X(1,1),X(2,1),X(3,1),'r','linewidth',1);
hrobot = plot3(X(1,1),X(2,1),X(3,1),'ro','linewidth',1);
hnear = plot3(wp(1,1),wp(1,2),wp(1,3),'bo','linewidth',1);

% hILC = plot3(w2ILC(:,1),w2ILC(:,2),w2ILC(:,3),'m','linewidth',.2 );
axis equal
htit = title('0');
control_hist = zeros(size(wp,1),1,3);
error_p = [0 0 0]';
error_c = [0 0 0]';
error_d = NaN;
error_direct = zeros(size(wp,1),3);
error = NaN*ones(iters,1);
error_h = NaN*ones(iters,1);
error_list = NaN*ones(size(wp,1),100);
error_ind = ones(size(wp,1),1);
subplot(2,2,2);
hILC = plot3(w2ILC(:,1),w2ILC(:,2),w2ILC(:,3),'m','linewidth',.2 );

subplot(2,2,3);
herr = plot(Dt*(1:iters),error,'linewidth',1);
xlabel('time (s)');ylabel('error (mm)');

subplot(2,2,4);
herr_h = plot(Dt*(1:iters),error_h,'linewidth',1);
xlabel('time (s)');ylabel('error_m (mm)');


%%%%%%%%%%%%%% END PLOTTING
learningRate = 1;
rangeInfluence = 10;

errInt = [0;0;0];
for i = 1: iters-1
    % determine closest point on trajectory
    [cp,ind]  = closestPt(wp, X(1:3,i));
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
 
%     inds = ind-rangeInfluence:ind+rangeInfluence;
%     scales = 1/(sqrt(2*pi*var)) * exp(-(inds-ind).^2./(2*var^2));
%     %uniform
%     scales = scales / sum(scales);
%     scales = 1-abs(-rangeInfluence:0)/rangeInfluence;
%     indILC = inds;
%     indILC(indILC<1) = size(wp,1)+ indILC(indILC<1);
%     indILC(indILC>size(wp,1)) = indILC(indILC>size(wp,1)) - size(wp,1);
    %indILC
    T = (iters-i)/iters;
    
    error_cpt = error_list(ind,~isnan(error_list(ind,:))); %closest point error history
%     if length(error_cpt) >1
%     error_d = error_cpt(end-1)-error_cpt(end); %error deriviative
%     end
    disp(error_d)
   %     elseif error_d<0
%         learningRate_direct =1tanh(error_d);

    learningRate = exp(-error_m/T); %simulated annealing
    %w2ILC(ind,:) = w2ILC(ind,:) + learningRate.*(wp(ind,:)-X(1:3,i)');
    p2c_vector = wp(ind,:)-X(1:3,i)';
%     error_direct(ind,:) = abs(learningRate_direct).*error_direct(ind,:)+(1-abs(learningRate_direct)).*(p2c_vector/norm(p2c_vector));
%     w2ILC(ind,:) = w2ILC(ind,:) + learningRate.*error_direct(ind,:).*norm(p2c_vector);

   
  % comment to turn off ILC
  
    % look ahead
    ind = ind+ 1;
    if ind>size(wp,1)
        ind = ind-size(wp,1);
    end
    
    wpDiff = w2(ind+1,:)'-w2(ind,:)'; %direction between waypoints
    
    errInt = errInt+ (cp - X(1:3,i)); %integral term
    
    % deriv term
    if i ==1
        vel = [0;0;0];
    else
        vel = X(1:3,i)-X(1:3,i-1);
    end
    
    control = [control_hist(ind,1,1);control_hist(ind,1,2);control_hist(ind,1,3)] + Kp * (cp - X(1:3,i)) + Ki * errInt - Kd * (error_c- error_p); % PID type ILC
    control_hist(ind,1,:) = control ; 
    % controller steers the thrust (only controls the orientation)
    u = Speed*control/norm(control);
    
    
    
    X(:,i+1) = [ ...
        X(1,i) + Drag*Dt*X(4,i) + 1/2*Dt*Dt*u(1);
        X(2,i) + Drag*Dt*X(5,i) + 1/2*Dt*Dt*u(2);
        X(3,i) + Drag*Dt*X(6,i) + 1/2*Dt*Dt*(u(3)-mg);
        Drag*X(4,i) + Dt*u(1);
        Drag*X(5,i) + Dt*u(2);
        Drag*X(6,i) + Dt*(u(3)-mg)];
    
    %update
    if mod(i,20) ==0
        set( hrpath,  'Xdata', X(1,1:i),'Ydata',X(2,1:i),'Zdata',X(3,1:i));
        set( hrobot, 'Xdata',X(1,i),'Ydata',X(2,i),'Zdata',X(3,i));
        set( hnear, 'Xdata',wp(ind,1),'Ydata',wp(ind,2),'Zdata',wp(ind,3));
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





function [cp,ind] = closestPt(arr,pt) % pick the closest point in arr to py
[~,ind] = min( sum( (arr - repmat(pt',size(arr,1),1)).^2,2));
cp = arr(ind,:)';
end




