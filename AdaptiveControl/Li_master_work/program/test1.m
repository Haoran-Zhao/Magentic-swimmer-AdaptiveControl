%inputs:
R=5.05*0.3048; 
Omega=870/60*2*pi ; 

rho =1.29;  
a=6.0 ; 
B=2; 
c=0.354*0.3048;
Ib=0.86754;
g=9.81 ;
e =0; 
mb=0.3;
Mb=(mb*R^2)/(2)*(1-e/R)^2*g ;
K=100;

u=[0.01;2;50];
theta_col=[1 0 0]*u;
vi0=[0 1 0]*u;
T_old=[0 0 1]*u;
beta_1s=0;
beta_1c=0;
theta_twist=4.864e-4;
bu=0;bv=0;bw=0;p=0;q=0;

A=pi*R^2;

vi=vi0;


w_r=bw+beta_1c*bu+beta_1s*bv;
w_b=w_r+(2/3)*Omega*R*(theta_col+0.75*theta_twist);


for ii=1:20
    T_MR(ii)=(rho*Omega^2*R^2*a*B*c*R)*((theta_col+0.75*theta_twist)-vi(ii)+w_r);
    v2=bu^2+bv^2+(bw*beta_1s*beta_1c)^2;
    vi(ii+1)=sqrt(sqrt((v2/2+w_r*(w_r-2*vi(ii)))^2+(T_MR(ii)/(2*rho*A))^2)-(v2+w_r*(w_r-2*vi(ii)))/2);
    
end

