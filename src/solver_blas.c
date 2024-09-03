/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"
#include "cblas.h"
#include <stdlib.h>
#include <string.h>

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
    double* C = (double*)malloc(N * N * sizeof(double));
	double* D = (double*)malloc(N * N * sizeof(double));

	memcpy(C, B, N * N * sizeof(*C));
	memcpy(D, B, N * N * sizeof(*D));
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit,
			N, N, 1.0, A, N, C, N);

	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper,CblasNoTrans, CblasNonUnit,
			N, N, 1.0, A, N, D, N);

	cblas_daxpy(N * N, 1.0, C, 1, D, 1);

	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans,N, N, N, 1.0, D, N, B, N, 0.0,C, N);

	free(D);
    return C;
}
