#include "neuralNetwork.h"
#include <math.h>

neuralNetwork* initializeNeuralNetwork(unsigned short int input_nodes,unsigned short int hidden_nodes, unsigned short int output_nodes){
	neuralNetwork* nn = malloc(sizeof(neuralNetwork));
	if(nn == NULL){
		printf("Matrix memory allocation has failed\n");
		return NULL;
	}

	nn->input_nodes = input_nodes;
	nn->hidden_nodes = hidden_nodes;
	nn->output_nodes = output_nodes;

	nn->weights_ih = initializeMatrix(hidden_nodes, input_nodes);
	randomizeMatrix(nn->weights_ih);
	nn->weights_ho = initializeMatrix(output_nodes, hidden_nodes);
	randomizeMatrix(nn->weights_ho);

	nn->bias_h = initializeMatrix(hidden_nodes, 1);
	randomizeMatrix(nn->bias_h);
	nn->bias_o = initializeMatrix(output_nodes, 1);
	randomizeMatrix(nn->bias_o);

	return nn;
}

void deleteNeuralNetwork(neuralNetwork* nn){
	if(nn == NULL){
		printf("\nArgument is NULL\n");
		return;
	}

	deleteMatrix(nn->weights_ih);
	deleteMatrix(nn->weights_ho);
	deleteMatrix(nn->bias_h);
	deleteMatrix(nn->bias_o);
	free(nn);
	nn = NULL;
}

void map(matrix* m, float (*f)(float)){
	if(m == NULL){
		printf("Argument are NULL");
		return;
	}

	for(int i=0; i<m->row; i++){
		for(int k=0; k<m->column; k++){
			m->data[i][k] = f(m->data[i][k]);
		}
	}
}


void feedForward(neuralNetwork* nn, float inputDatas_arr[]){
	if(nn == NULL){
		printf("\nArguments are NULL\n");
		return;
	}

	matrix* inputDatas = fromArray(inputDatas_arr);
	printMatrix(inputDatas);

	matrix* hidden = mulMatrix(nn->weights_ih, inputDatas, true);
	printMatrix(hidden);
	addMatrix(hidden, nn->bias_h, false);
	printMatrix(hidden);
	map(hidden, sigmoid);
	printMatrix(hidden);

	matrix* output = mulMatrix(nn->weights_ho, hidden, true);
	printMatrix(output);
	addMatrix(output, nn->bias_o, false);
	printMatrix(output);
	map(output, sigmoid);
	printMatrix(output);
}


void printOutput(neuralNetwork* nn){
	for(int i=0; i<nn->output_nodes; i++){

	}
}

float sigmoid(float nbr){
	return (float)1/(1+exp(-1*nbr));
}