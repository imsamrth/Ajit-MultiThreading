#pragma once

#include "matrix.h"

double sigmoid(double input);
double relu (double input);
Matrix* sigmoidPrime(Matrix* m);
Matrix* softmax_from_c(Matrix* m);
Matrix* softmax(Matrix* m);