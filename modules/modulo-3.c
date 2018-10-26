#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matrices.h"
#define N 512

int *A, *Ai, *R;

int main(int argc, const char* argv[]){

    N = atoi(argv[1]);

    A = declaration_matrix(A, N);
    Ai = declaration_matrix(Ai, N);
    R = declaration_matrix(R, N);

}
