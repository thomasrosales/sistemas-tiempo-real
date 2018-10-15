#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matrices.h"

int *A, *Ai, *R;
double timetick;

int main(int argc, const char* argv[]){

	if (argc < 2){
    	printf("Falta un parametro.\n");
    	printf("1. Dimension de la matriz: 512, 1024 y 2048\n");
    	return 0;
  	}

  	N = atoi(argv[1]);

  	int i, j, k;
	double timetick;

	//print_hello();
	A = matrix_declaration(A, N);
	Ai = matrix_declaration(Ai, N);
	R = matrix_declaration(R, N);
	
	init_matriz(A, R, Ai,N);

	mullti_matrix(R, A, Ai,N);

	print_matrix(R,N,0);

	free_matriz(A,R,Ai);
}