#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matrices.h"

double dwalltime(){
    double sec;
    struct timeval tv;
    gettimeofday(&tv,NULL);
    sec = tv.tv_sec + tv.tv_usec/1000000.0;
    return sec;
}


int* declaration_matrix(int *M, int N){
	return M=(int*)malloc(sizeof(int)*N*N);
}

void init_matrix(int *A, int *R, int *Ai, int N){

  for(i=0;i<N;i++){
  	for(j=0;j<N;j++){
  		R[i*N+j] = 0; // inicializacion matriz resultado
  		A[i*N+j] = rand()%10; //lo ordeno normal (xfilas)
  		Ai[i+N*j] = A[i*N+j]; //lo ordeno diferente (xcolumnas)para aprovechar la cache
  	}
  }

}

void multi_matrix(int *R, int *A, int *Ai, int N){
	/*   Multiplicacion de la Matriz A por Ai ordenada por columnas   */
	for (i=0;i<N;i++){
    	for (j=0;j<N;j++){
			for (k=0;k<N;k++){
				R[i*N+j] = R[i*N+j] + (A[i*N+k]*Ai[k+j*N]);
			}
		}
	}
}

/*
	Imprime en la salida estandar
	el contenido de la matriz NXN
  o = 1 por columnas
  o = 0 por filas
	pasada como parametro
*/
void print_matrix(int *M, int N, int o){
  int i, j;
  for(i=0;i<N;i++){
     for(j=0;j<N;j++){
       if(o)
	      printf("%d ", M[i+j*N]);
       else
       printf("%d ", M[i*N+j]);
     }
  printf("\n");
  }
}

void free_matrix(int *A, int *R, int *Ai){
	free(A);
  	free(Ai);
	free(R);
}
