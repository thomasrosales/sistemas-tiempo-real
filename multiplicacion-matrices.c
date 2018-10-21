//Ejercicio-1.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define DEBUG 0

/*A es una matriz de NxN. Analizar el producto AA
Evaluar N=512, 1024 y 2048.*/

int N, *A, *Ai, *R;
/* Funcion para calcular el tiempo de ejecucion */
double dwalltime(){
    double sec;
    struct timeval tv;
    gettimeofday(&tv,NULL);
    sec = tv.tv_sec + tv.tv_usec/1000000.0;
    return sec;
}

/*
	Imprime en la salida estandar
	el contenido de la matriz NXN
  o = 1 por columnas
  o = 0 por filas
	pasada como parametro
*/
void print_matrix(int *m, int N, int o){
  int i, j;
  for(i=0;i<N;i++){
     for(j=0;j<N;j++){
       if(o)
	      printf("%d ", m[i+j*N]);
       else
       printf("%d ", m[i*N+j]);
     }
  printf("\n");
  }
}

int main(int argc,char*argv[]){

	if (argc < 2){
    printf("\n Falta un parametro ");
    printf("\n 1. Dimension de la matriz: 512, 1024 y 2048 ");
    return 0;
  }

  N = atoi(argv[1]);

  int i, j, k;
  double timetick;

  //Aloca memoria para las matrices que son iguales pero ordenadas diferentes
  A=(int*)malloc(sizeof(int)*N*N);
  Ai=(int*)malloc(sizeof(int)*N*N);
  R=(int*)malloc(sizeof(int)*N*N);


	/*   Inicializa las matrices  */
  for(i=0;i<N;i++){
  	for(j=0;j<N;j++){
  		R[i*N+j]=0; // inicializacion matriz resultado
  		A[i*N+j]=rand()%10; //lo ordeno normal (xfilas)
  		Ai[i+N*j]=A[i*N+j]; //lo ordeno diferente (xcolumnas)para aprovechar la cache
  	}
  }

	timetick = dwalltime();

	/*   Multiplicacion de la Matriz A por Ai ordenada por columnas   */
	for (i=0;i<N;i++){
    for (j=0;j<N;j++){
			for (k=0;k<N;k++){
				R[i*N+j] = R[i*N+j] + (A[i*N+k]*Ai[k+j*N]);
			}
		}
	}


	printf("Tiempo en segundos %f\n", dwalltime() - timetick);
  #if DEBUG
    print_matrix(A,N,0);
    print_matrix(Ai,N,1);
    print_matrix(R,N,0);
  #endif

	free(A);
  free(Ai);
	free(R);

	return(0);
}
