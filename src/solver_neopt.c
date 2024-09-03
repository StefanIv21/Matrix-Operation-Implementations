/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *A_tB = (double *)calloc(N * N, sizeof(double));
	double *BA = (double *)calloc(N * N, sizeof(double));
	double *Sum = (double *)calloc(N * N, sizeof(double));
	double *C = (double *)calloc(N * N, sizeof(double));

	// A transpose * B
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k <= i; k++)
				A_tB[i * N + j] += A[k * N + i] * B[k * N + j];

	// BA = B * A
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k <= j; k++)
				BA[i * N + j] += B[i * N + k] * A[k * N + j];

	// Sum = A_TB + BA
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Sum[i * N + j] = A_tB[i * N + j] + BA[i * N + j];
	
	// C = Sum * B_t
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				C[i * N + j] += Sum[i * N + k] * B[j * N + k];
	

	free(A_tB);
	free(BA);
	free(Sum);
	return C;
}
