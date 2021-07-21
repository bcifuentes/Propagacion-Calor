#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<double> data_t;

void initial_conditions(data_t & u,int N);
void boudary_conditions(data_t & u,int N,double t);
void evolve(data_t & u,int N,double t);

double a=8.69e-5;
double h=14.4;
double k=209.3;
double L= 0.109;
double l=0.012;
double T= 60*5;
double e= 0.003;
double m= std::sqrt(h*(2*(l+e))/(k*l*e));
double dt=0.1;
double dx=4.36e-3;


int main(int argc,char ** argv){  
  int Nx= L/dx;
  int Nt= T/dt;
  

  data_t u(Nx);

  initial_conditions(u,Nx);
  boudary_conditions(u,Nx,0.);


  for(int tt=0;tt<=Nt;++tt){
    std::cout<<tt*dt<<" ";
    for(int ii=0;ii<Nx;++ii){
      std::cout<<u[ii]<<" ";
    }
    std::cout<<"\n";
    double t=tt*dt;
    evolve(u,Nx,t);
  }
    
  return 0;
}

void initial_conditions(data_t & u,int N){
  for(int ii=0;ii<N;++ii){
    u[ii]=5;
  }
}
void boudary_conditions(data_t & u,int N,double t){
  //u[0]=15*std::cos(5*t)-5;
  u[0]=-10;
  u[N-1]=u[N-2]*(1-dx*h/k);
}
void evolve(data_t & u,int N,double t){

  for(int ii=1;ii<N;ii++){
    u[ii]=dt*a/(dx*dx)*(u[ii+1]-2*u[ii]+u[ii-1])+u[ii]*(1-a*dt*m*m);
  }
  boudary_conditions(u,N,t);
}
