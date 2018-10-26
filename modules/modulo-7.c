#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../matrices.h"
#define N 512

int *A, *Ai, *R;

int main(int argc, const char* argv[]){

    A = declaration_matrix(A, N);
    Ai = declaration_matrix(Ai, N);
    R = declaration_matrix(R, N);

    init_matrix(A, R, Ai, N);

    multi_matrix(R, A, Ai, N);

    print_matrix(R, N, 0);

    free_matrix(A, R, Ai);

}
