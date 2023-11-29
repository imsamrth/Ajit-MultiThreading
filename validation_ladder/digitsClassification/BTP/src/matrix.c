#include "../include/matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 100

Matrix* matrix_create(int row, int col) {
	Matrix *matrix = cortos_bget(sizeof(Matrix));
	matrix->rows = row;
	matrix->cols = col;
	matrix->entries = cortos_bget(row * sizeof(double*));
	int i;
	for ( i = 0; i < row; i++) {
		matrix->entries[i] = cortos_bget(col * sizeof(double));
	}
	return matrix;
}

void matrix_fill(Matrix *m, int n) {
		int i, j;
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			m->entries[i][j] = n;
		}
	}
}

void matrix_free(Matrix *m) {
		int i ;
	for ( i = 0; i < m->rows; i++) {
		cortos_brel(m->entries[i]);
	}
	cortos_brel(m->entries);
	cortos_brel(m);
	//m = NULL;
}

void matrix_print(Matrix* m) {
	cortos_printf("Rows: %d Columns: %d\n", m->rows, m->cols);
	int i, j;
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			cortos_printf("%f ", m->entries[i][j]);
		}
		cortos_printf("\n");
	}
}

Matrix* matrix_copy(Matrix* m) {
	Matrix* mat = matrix_create(m->rows, m->cols);
		int i, j;
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			mat->entries[i][j] = m->entries[i][j];
		}
	}
	return mat;
}

Matrix* matrix_load_from_C(int rows, int cols, double * weights) {
	//cortos_printf("matrix of size loaded %d * %d\n" , rows , cols);	
	Matrix* m = matrix_create(rows, cols);
	int i, j;
	//if(rows == 48) cortos_printf("%d\n" , 10);	
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			m->entries[i][j] = weights[i*cols + j];
			//if(rows == 48) cortos_printf("%d\n" , j);
		}
	}
	return m;
}

double uniform_distribution(double low, double high) {
	double difference = high - low; // The difference between the two
	int scale = 10000;
	int scaled_difference = (int)(difference * scale);
	//return low + (1.0 * (rand() % scaled_difference) / scale);
	return low ;
}

void matrix_randomize(Matrix* m, int n) {
	// Pulling from a random distribution of 
	// Min: -1 / sqrt(n)
	// Max: 1 / sqrt(n)
		int i, j;
	double min = -1.0 / sqrt(n);
	double max = 1.0 / sqrt(n);
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			m->entries[i][j] = uniform_distribution(min, max);
		}
	}
}

int matrix_argmax(Matrix* m) {
	// Expects a Mx1 matrix
	double max_score = 0;
	int max_idx = 0;
		int i, j;
	for ( i = 0; i < m->rows; i++) {
		if (m->entries[i][0] > max_score) {
			max_score = m->entries[i][0];
			max_idx = i;
		}
		//cortos_printf(" p for %d is = %f \n", i , m->entries[i][0]);
	}
	return max_idx;
}

Matrix* matrix_flatten(Matrix* m, int axis) {
	// Axis = 0 -> Column Vector, Axis = 1 -> Row Vector
	Matrix* mat;
	int i, j;
	if (axis == 0) {
		mat = matrix_create(m->rows * m->cols, 1);
	} else if (axis == 1) {
		mat = matrix_create(1, m->rows * m->cols);
	} else {
		cortos_printf("Argument to matrix_flatten must be 0 or 1");
		cortos_exit(10);
	}
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			if (axis == 0) mat->entries[i * m->cols + j][0] = m->entries[i][j];
			else if (axis == 1) mat->entries[0][i * m->cols + j] = m->entries[i][j];
		}
	}
	return mat;
}