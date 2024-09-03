/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *A_tB = (double *)calloc(N * N, sizeof(double));
	double *BA = (double *)calloc(N * N, sizeof(double));
	double *Sum = (double *)calloc(N * N, sizeof(double));
	double *C = (double *)calloc(N * N, sizeof(double));
	double *A_t = (double *)calloc(N * N, sizeof(double));

	for (register int i = 0; i < N; i++) {
		register double *A_t_p = A_t + i;  
		register double *A_p = A + i * N;  
		for (register int j = 0; j < N; j++) {
			*A_t_p = *A_p;
			A_t_p += N;
			A_p++;
		}
	}
	// A transpose * B
	for (register int i = 0; i < N; i++) {
		register double *A_tB_p = A_tB + i * N;
		register double *A_t_p = A_t + i * N;
		for (register int j = 0; j < N; j++) {
			register double sum = 0.0;
			register double *A_line_p = A_t_p ;
			register double *B_col_p = B + j;
			for (register int k = 0; k <= i ; k++)
			{
				sum += *A_line_p * *B_col_p;
				A_line_p++;
				B_col_p += N;
			}
			*A_tB_p += sum;
			A_tB_p++;
		}
	}
	// BA = B * A
	for (register int i = 0; i < N; i++) {
		register double *BA_p = BA + i * N;
		register double *B_p = B + i * N;
		for (register int j = 0; j < N; j++) {
			register double sum = 0.0;
			register double *A_col_p = A + j;
			register double *B_line_p = B_p;
			for (register int k = 0; k <= j; k++)
			{
				sum += *A_col_p * *B_line_p;
				A_col_p += N,
				B_line_p++;
			}
			*BA_p += sum;
			BA_p++;
		}
	}
	// Sum = A_TB + BA
	for (register int i = 0; i != N; ++i) {
		register double *Sum_p = Sum + i * N;
		register double *A_tB_p = A_tB + i * N;
		register double *BA_p = BA + i * N;
		for (register int j = 0; j < N; j++)
		{
			*Sum_p = *A_tB_p + *BA_p;
			Sum_p++;
			A_tB_p++;
			BA_p++;
		}
	}
	// C = Sum * B_t
	for(register int i = 0; i < N; i++) {
		register double *C_p = C + i * N;
		register double *Sum_p = Sum + i * N;
		for(register int j = 0; j < N; j++) {
			register double sum = 0.0;
			register double *Sum_line_p = Sum_p;
			register double *B_t_line_p = B + j*N;
			for(register int k = 0; k < N; k++)
			{
				sum += *Sum_line_p * *B_t_line_p;
				Sum_line_p++;
				B_t_line_p ++;
			}
			*C_p += sum;
			C_p ++;
		}
	}
	free(A_tB);
	free(BA);
	free(Sum);
	free(A_t);
	return C;
}
