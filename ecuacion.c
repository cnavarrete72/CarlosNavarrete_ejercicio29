#include <math.h>
#include <stdlib.h>
#include <stdio.h>
void initial(double delta_x, double *x, double *u, int N)
{ 
  int i;
  double val=0.0;
  for(i = 0; i < N; i++)
  {
      x[i] = val;
      u[i]=0.0;
      if(val<2.0){
	u[i]=1.0;
      }
      val+=delta_ x ;
      
  }
}

void flux (double *u)
{
  int i;
  int size=(int) sizeof(u)/sizeof(u[0]);

  for(i=0; i<size; i++)
  {
    val=u[i];
    u[i]=val*val*0.5;
  }
      
}

double * Lax(double *u_final, double *u, double t_max, double delta_t, double delta_x){
  int N_t = (int) t_max/delta_t;
  int size=(int) sizeof(u)/sizeof(u[0]);
  double *u_final;
  u_final = malloc(sizeof(double *)*size);
  u_final=copia(u);
  int i;
  for(i=0;i<N_t;i++){
    double *F;
    F = malloc(sizeof(double *)*size);
    flux(F);
    int j;
    for(j=1;j<(size-1);j++)
    {
      u_final[j]=0.5*(u[j+1]+u[j-1]);
      u_final[j]-=(0.5*delta_t/delta_x)*(F[j+1] - F[j-1]);
      u=copia(u_final);		      
    }
    return u_final;
  }

double * copia(double *original){
  int size=(int) sizeof(original)/sizeof(original[0]);
  int i;
  double *replica;
  replica = malloc(sizeof(double *)*size);
  
  for (i=0; i<size; i++)
  {
    replica[i]=original[i];
  }
  return replica;
}


void main()
{
  double L = 4.0;
  int N = (int) L/delta_x+1;
  double *x;
  x = malloc(sizeof(double *)*N);
  double *u;
  u = malloc(sizeof(double *)*N);
}
