#include "../include/activations.h"
#include <math.h>
#include "../include/ops.h"

double sigmoid(double input) {
	return 1.0 / (1 + exp(-1 * input));
}

double relu(double input){
	if (input > 0.0 ) return input ;

	return 0.0 ;
}

Matrix* sigmoidPrime(Matrix* m) {
	Matrix* ones = matrix_create(m->rows, m->cols);
	matrix_fill(ones, 1);
	Matrix* subtracted = subtract(ones, m);
	Matrix* multiplied = multiply(m, subtracted);
	matrix_free(ones);
	matrix_free(subtracted);
	return multiplied;
}

Matrix* softmax_from_c(Matrix* m) {
	double total = 0;
	int i , j;
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			total += exp(m->entries[i][j]);
		}
	}
	Matrix* mat = matrix_create(m->rows, m->cols);
	for (i = 0; i < mat->rows; i++) {
		for ( j = 0; j < mat->cols; j++) {
			mat->entries[i][j] = exp(m->entries[i][j]) / total;
		}
	}
	return mat;
}

Matrix* softmax(Matrix* m) {
	double total = 0;
	int i , j;
	for ( i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			total += exp(m->entries[i][j]);
		}
	}
	Matrix* mat = matrix_create(m->rows, m->cols);
	for (i = 0; i < mat->rows; i++) {
		for ( j = 0; j < mat->cols; j++) {
			mat->entries[i][j] = exp(m->entries[i][j]) / total;
		}
	}
	return mat;
}