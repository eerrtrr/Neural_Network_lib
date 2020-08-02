#include <stdio.h>
#include "neuralNetwork.h"

int main(int argc, char** argv){
	float inputDatas_arr[] = {2,9};
	float target_arr[] = {1};
	neuralNetwork* nn = initializeNeuralNetwork(2,2,1);

	train(inputDatas_arr, target_arr, nn);

	return 0;
}