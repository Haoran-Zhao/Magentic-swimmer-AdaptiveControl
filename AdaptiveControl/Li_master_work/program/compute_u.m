close all
ux = yout.signals(7).values(1:11,:);
u=zeros(4,size(ux,2));
for ii = 1:size(ux,2)
    u(:,ii)=BB\ux(:,ii);
end
figure
subplot(2,2,1)
plot(tout,u(1,:));
subplot(2,2,2)
plot(tout,u(2,:));
subplot(2,2,3)
plot(tout,u(3,:));
subplot(2,2,4)
plot(tout,u(4,:));

figure
xx = yout.signals(1).values(1:3,:);
reff = yout.signals(5).values(:,1:3)';
plot(tout,xx)

xx = yout.signals(5).values(1:3,:);

reff = yout.signals(6).values(:,1:3)';
plot3(xx(1,:),xx(2,:),xx(3,:),'-r');hold on 
plot3(reff(1,:),reff(2,:),reff(3,:),'-b');grid on