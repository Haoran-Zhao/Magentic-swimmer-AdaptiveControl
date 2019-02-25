R=5.05*0.3048; 
y_m=0; 
h_t=0;
l_m=0; 
l_t=1.2 ; 
h_m = 0.2 ; 
i_x =0.1997*7.345;
i_y =0.6231*7.345;
i_z = 0.6*7.345; 
Omega=870/60*2*pi ; 
rho =1.29; 
A= pi*R^2 ; 
a=6.0 ; 
B=2; 
c=0.354*0.3048;
m=97.85/2.20462262 ;
sigma=(B*c)/(pi*R) ;
f_wake =0; 
Ib=0.86754;
e_MR=0;
r_cr_t=0.5 ;
r_crp=0.42 ;
g=9.81 ; 
i_s =0;
mb=1.5*0.2;
e =0; 
Mb=(m_b*R^2)/(2)*(1-e/R)^2*g ;

K_MR=0.2; 
K_cr=0.8;
gamma=rho*a*c*R^4/Ib ; %
xi=-1+(r_crp^4/r_cr_t^4); %
C_T=0.00226 ;
Omega_f=gamma*Omega/R*(1+8/3*e_MR/R) ;

K_1=0; 
K_2=3/4*e_MR/R*Omega/Omega_f ; %
K_c=K_1+K_2 ; 


A_Q_MR=0.000018*20; %
B_Q_MR= 0.01 ; %