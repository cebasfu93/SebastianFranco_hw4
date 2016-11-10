#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define T 40.0
#define rho 10.0
#define L 100.0
#define tfin 200.0
#define N 100
#define N_time 1000

int main(){

  float *cuerda;
  cuerda=malloc(N*sizeof(float));
  float *cuerda_new;
  cuerda_new=malloc(N*sizeof(float));
  float *cuerda_bef;
  cuerda_bef=malloc(N*sizeof(float));

  float x=0.0;
  float delx=L/(N-1);
  float delt=tfin/N_time;
  float c=pow(T/rho, 0.5);
  float r=c*delt/delx;

  if(r>=1){
    printf("Paila, r= %f \n", r);
  }

  int i;
  int j;
  for(i=0;i<N;i++){
    if (x<=0.8*L){
      cuerda[i]=1.25*x/L;
    }
    else{
      cuerda[i]=5.0-5.0*x/L;
    }
    x+=delx;
  }

  for(i=0;i<N;i++){
    printf("%f ", cuerda[i]);
  }
  printf("\n");
  for(j=0;j<(N_time-1);j++){
    if(j==0){
      for(i=1;i<N-1;i++){
        cuerda_new[i]=cuerda[i]+pow(r,2)/2*(cuerda[i+1]-2*cuerda[i]+cuerda[i-1]);
      }
    }
    else{
      for(i=1;i<N-1;i++){
        cuerda_new[i]=2*(1-pow(r,2))*cuerda[i]-cuerda_bef[i]+pow(r,2)*(cuerda[i+1]+ cuerda[i-1]);
      }
    }

    for(i=0;i<N;i++){
      cuerda_bef[i]=cuerda[i];
    }
    for(i=0;i<N;i++){
      cuerda[i]=cuerda_new[i];
    }
    for(i=0;i<N;i++){
      printf("%f ", cuerda[i]);
    }
    printf("\n");
  }
  return 0;
}
