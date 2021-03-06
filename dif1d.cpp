#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<double> data_t;

void initial_conditions(data_t & u,int N);
void boudary_conditions(data_t & u,int N,double t);
void evolve(data_t & u,double a,int N,double t,double dt,double dx);

int main(int argc,char ** argv){

  double dt=0.001;
  double dx=0.1;
  double L= 5;
  double T= 15;
  
  int Nx= L/dx;
  int Nt= T/dt;
  
  double a=1;

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
    evolve(u,a,Nx,t,dt,dx);
  }
    
  return 0;
}

void initial_conditions(data_t & u,int N){
  for(int ii=0;ii<N;++ii){
    u[ii]=0;
  }
}
void boudary_conditions(data_t & u,int N,double t){
  u[0]=20*std::cos(10*t+M_PI*0.5);
  u[N-1]=u[N-2];
}
void evolve(data_t & u,double a,int N,double t,double dt,double dx){
  for(int ii=1;ii<N-1;ii++){
    u[ii]=dt*a/(dx*dx)*(u[ii+1]-2*u[ii]+u[ii-1])+u[ii];
  }
  boudary_conditions(u,N,t);
}
