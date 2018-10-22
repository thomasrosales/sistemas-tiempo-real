#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matrices.h"

int *A, *Ai, *R;

int main(int argc, const char* argv[]){

    if (argc < 2){
        printf("Falta un parametro.\n");
    	printf("1. Dimension de la matriz: 512, 1024 y 2048\n");
        return 0;
    }

    N = atoi(argv[1]);

    A = declaration_matrix(A, N);
    Ai = declaration_matrix(Ai, N);
    R = declaration_matrix(R, N);

    init_matrix(A, R, Ai, N);

    multi_matrix(R, A, Ai, N);

    print_matrix(A, N, 0);
    print_matrix(Ai, N, 0);
    print_matrix(R, N, 0);

    free_matrix(A, R, Ai);

}
