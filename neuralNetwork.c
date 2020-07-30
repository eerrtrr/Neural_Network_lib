#include "neuralNetwork.h"

neuralNetwork* initializeNeuralNetwork(unsigned short int input_nodes,unsigned short int hidden_nodes, unsigned short int output_nodes){
	neuralNetwork* nn = malloc(sizeof(neuralNetwork));

	nn->input_nodes = input_nodes;
	nn->hidden_nodes = hidden_nodes;
	nn->output_nodes = output_nodes;

	nn->weights_ih = initializeMatrix(hidden_nodes, input_nodes);
	randomizeMatrix(nn->weights_ih);
	nn->weights_ho = initializeMatrix(output_nodes, hidden_nodes);
	randomizeMatrix(nn->weights_ho);

	return nn;
}