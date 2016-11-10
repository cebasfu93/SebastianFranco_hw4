#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 5.0
#define l 2.0
#define d 1.0
#define h 0.02
#define V0 100.0

int main(){
  int N = 2*pow(L/h,2) ;
  int M = L/h ;
  int M2=pow(M,2);
  int ls=l/h;
  int ds=d/h;

  int plac1i=M/2-ds/2;
  int plac2i=M/2+ds/2;
  int placj=M/2-ls/2;

  float *space;
  space = malloc(M2*sizeof(float));

  int i ;
  int j ;
  int k;
  for(i=0; i<M;i++){
    for(j=0;j<M;j++){
      if(i==plac1i && j>=placj && j<=(placj+ls)){
        space[i*M+j]=V0/2;
      }
      else if(i==plac2i && j>=placj && j<=(placj+ls)){
        space[i*M+j]=-V0/2;
      }
      else{
        space[i*M+j]=0.0;
      }
    }
  }

  for(k=0;k<N;k++){
    for(i=1; i<(M-1);i++){
      for(j=1; j<(M-1); j++){
        if(space[i*M+j]!=V0/2 && space[i*M+j]!=-V0/2){
          space[i*M+j]=1.0/4*(space[(i-1)*M+j]+space[i*M+j+1]+space[i*M+j-1]+space[(i+1)*M+j]);
        }
      }
    }
  }

  float *campox;
  float *campoy;
  campox=malloc(M2*sizeof(float));
  campoy=malloc(M2*sizeof(float));

  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      if(space[i*M+j]!=V0/2 && space[i*M+j]!=-V0/2 && space[i*M+j]!=0){
        campox[i*M+j]=-1.0/(2*h)*(space[i*M+j+1]-space[i*M+j-1]);
        campoy[i*M+j]=-1.0/(2*h)*(space[(i+1)*M+j]-space[(i-1)*M+j]);
      }
      else{
        campox[i*M+j]=0;
        campoy[i*M+j]=0;
      }
    }
  }

/* Imprime*/
FILE *fp;
fp=fopen("M.txt", "w");
fprintf(fp, "%i \n", M);

  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      printf("%f ", space[i*M+j]);
    }
    printf("\n");
  }

  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      printf("%f ", campox[i*M+j]);
    }
    printf("\n");
  }

  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      printf("%f ", campoy[i*M+j]);
    }
    printf("\n");
  }
  return 0;
}
