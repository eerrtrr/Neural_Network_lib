#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "matrix.h"


struct NEURAL_NETWORK{
	unsigned short int input_nodes;
	unsigned short int hidden_nodes;
	unsigned short int output_nodes;
	matrix* weights_ih;
	matrix* weights_ho;

	matrix* bias_h;
	matrix* bias_o;
};
typedef struct NEURAL_NETWORK neuralNetwork;


neuralNetwork* initializeNeuralNetwork(unsigned short int input_nodes,unsigned short int hidden_nodes, unsigned short int output_nodes);
void deleteNeuralNetwork(neuralNetwork* nn);


void feedForward(neuralNetwork* nn, float inputDatas_arr[]);
void map(matrix* m, float (*f)(float));

void printOutput(neuralNetwork* nn);

//Activation functions
float sigmoid(float nbr);

#endif
