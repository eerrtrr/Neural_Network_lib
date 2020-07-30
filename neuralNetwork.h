#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "matrix.h"


struct NEURAL_NETWORK{
	unsigned short int input_nodes;
	unsigned short int hidden_nodes;
	unsigned short int output_nodes;
	matrix* weights_ih;
	matrix* weights_ho;
};
typedef struct NEURAL_NETWORK neuralNetwork;


neuralNetwork* initializeNeuralNetwork(unsigned short int input_nodes,unsigned short int hidden_nodes, unsigned short int output_nodes);


#include "matrix.h"

#endif
