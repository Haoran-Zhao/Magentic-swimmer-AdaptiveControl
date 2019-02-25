%inputs:
R=5.05*0.3048; 
Omega=870/60*2*pi ; 
m=97.85/2.20462262;
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


theta_col=4:0.1:10;
vi0=2;
T_old=0;
beta_1s=0;
beta_1c=0;
theta_twist=4.864e-4;
bu=0;bv=0;bw=0;p=0;q=0;
theta_col=theta_col*pi/180;
A=pi*R^2;

vi=vi0;

T_MR=zeros(1,size(theta_col,2));
T_MR(1)=T_old;
w_r=bw+beta_1c*bu-beta_1s*bv;
for jj=1:size(theta_col,2)
w_b(jj)=w_r+(2/3)*Omega*R*(theta_col(jj)+0.75*theta_twist);

vi2=vi.^2;

for ii=1:20
    
    v2=bu^2+bv^2+w_r*(w_r-2*vi);
    vi2=sqrt((v2/2)^2+(T_MR(jj)/(2*rho*A))^2)-v2/2;
    vi=sqrt(vi2);
    T_MR(jj)=(w_b(jj)-sqrt(vi2))*(rho*Omega*R*a*B*c*R)/4;
    if abs(T_MR(jj)-429.7)<0.1 
        vi_critical1=vi;
    end
    
    if abs(T_MR(jj)-439.6)<0.1
        vi_critical2=vi;
    end
        
end
Q_MR(jj)=0.00036*T_MR(jj)^1.5+0.01;
end
