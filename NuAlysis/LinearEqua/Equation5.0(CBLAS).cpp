/*************************************************************************************/
/*************************************** 2018.3.28 ***********************************/
/*****************************          Jerry Zheng           ************************/
/**************************** Beijing Insititute of Technology ***********************/
/*************************************************************************************/

/*Gaussian of a linear equation with cblas*/

#include <stdlib.h>
#include <stdio.h>
#include "lapacke.h"

extern void print_matrix(char* desc, lapack_int m, lapack_int n, double* a, lapack_int lda);
extern void print_int_vector(char* desc, lapack_int n, lapack_int* a);

#define N 5
#define NRHS 3
#define LDA N
#define LDB NRHS

int main()
{
	lapack_int n = N, nrhs = NRHS, lda = LDA, ldb = LDB, info;
	lapack_int ipiv[N];
	double a[LDA*N] = {
		6.80, -6.05, -0.45,  8.32, -9.67,
		-2.11, -3.30,  2.58,  2.71, -5.14,
		5.66, 5.36, -2.70,  4.35, -7.26,
		5.97, -4.44,  0.27, -7.17, 6.08,
		8.23, 1.08,  9.04,  2.14, -6.87
	};
	double b[LDB*N] = {
		4.02, -1.56, 9.81,
		6.19,  4.00, -4.09,
		-8.22, -8.67, -4.57,
		-7.57,  1.75, -8.61,
		-3.03,  2.86, 8.99
	};
	print_matrix("Entry Matrix A", n, n, a, lda);
	print_matrix("Right Rand Side", n, nrhs, b, ldb);
	info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, a, lda, ipiv,
		b, ldb);
	if (info > 0) {
		printf("The diagonal element of the triangular factor of A,\n");
		printf("U(%i,%i) is zero, so that A is singular;\n", info, info);
		printf("the solution could not be computed.\n");
		exit(1);
	}
	print_matrix("Solution", n, nrhs, b, ldb);
} 

void print_matrix(char* desc, lapack_int m, lapack_int n, double* a, lapack_int lda) {
	lapack_int i, j;
	printf("\n %s\n", desc);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) printf(" %6.2f", a[i*lda + j]);
		printf("\n");
	}
}

void print_int_vector(char* desc, lapack_int n, lapack_int* a) {
	lapack_int j;
	printf("\n %s\n", desc);
	for (j = 0; j < n; j++) printf(" %6i", a[j]);
	printf("\n");
}
