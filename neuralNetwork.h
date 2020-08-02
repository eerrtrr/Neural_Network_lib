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


//Memory allocation and desallocation
neuralNetwork* initializeNeuralNetwork(unsigned short int input_nodes,unsigned short int hidden_nodes, unsigned short int output_nodes);
void deleteNeuralNetwork(neuralNetwork* nn);


//Feedforwarding algorithm
matrix* feedForward(neuralNetwork* nn, float inputDatas_arr[]);


//Train the network
void train(float inputDatas_arr[], float target_arr[], neuralNetwork* nn);

//Map function to apply a fct to every element of data matrix
void map(matrix* m, float (*f)(float));


//Activation functions
float sigmoid(float nbr);

#endif
