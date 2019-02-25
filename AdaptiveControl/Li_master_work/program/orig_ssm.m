function x_dot = orig_ssm(t,x)

%#codegen
x_dot=zeros(11,1);
global AA;
global BB;
global u;
x_dot=AA*x+BB*u;

