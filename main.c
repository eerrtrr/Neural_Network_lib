#include <stdio.h>
#include "neuralNetwork.h"

int main(int argc, char** argv){
	float inputDatas_arr[] = {2,9};
	neuralNetwork* nn = initializeNeuralNetwork(2,2,1);
	printMatrix(nn->weights_ih);
	printMatrix(nn->bias_h);
	printMatrix(nn->weights_ho);
	printMatrix(nn->bias_o);

	feedForward(nn, inputDatas_arr);

	deleteNeuralNetwork(nn);

	return 0;
}