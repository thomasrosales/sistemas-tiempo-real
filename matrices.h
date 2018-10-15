#ifndef MATRICES_H_
#define MATRICES_H_

int N, i, j, k;

double dwalltime();
int* matrix_declaration(int *M, int N);
void init_matriz(int *A, int *R, int *Ai, int M);
void mullti_matrix(int *R, int *A, int *Ai, int N);
void print_matrix(int *M, int N, int o);
void free_matrix(int *A, int *R, int *Ai);

#endif // MATRICES_H_
