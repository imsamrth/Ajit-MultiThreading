#pragma once

#include "matrix.h"
#include "img.h"

typedef struct {
	int input;
	int hidden;
	int output;
	double learning_rate;
	Matrix* hidden_weights;
	Matrix* output_weights;
	Matrix* bias_1 ;
	Matrix* bias_2 ;
} NeuralNetwork;

NeuralNetwork* network_create(int input, int hidden, int output, double lr);
Matrix* network_predict_img(NeuralNetwork* net, Img* img);
double network_predict_imgs(NeuralNetwork* net, Img** imgs, int n);
Matrix* network_predict(NeuralNetwork* net, Matrix* input_data);
NeuralNetwork* network_load_from_C();
void network_print(NeuralNetwork* net);
void network_free(NeuralNetwork* net);