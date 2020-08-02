#include "neuralNetwork.h"
#include <math.h>



//Memory allocation and desallocation
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



//Map function to apply a fct to every element of data matrix
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



//Feedforwarding algorithm
matrix* feedForward(neuralNetwork* nn, float inputDatas_arr[]){
	if(nn == NULL){
		printf("\nArguments are NULL\n");
		return NULL;
	}
	
	//Convert array input into matrix
	matrix* inputDatas = fromArray(inputDatas_arr);
	printf("Input datas are : \n");
	printMatrix(inputDatas);

	//feedforward the datas throw the network
	matrix* hidden = mulMatrix(nn->weights_ih, inputDatas, true);
	addMatrix(hidden, nn->bias_h, false);
	map(hidden, sigmoid);
	printf("Hidden datas are : \n");
	printMatrix(hidden);

	matrix* output = mulMatrix(nn->weights_ho, hidden, true);
	addMatrix(output, nn->bias_o, false);
	map(output, sigmoid);
	printf("Output datas are : \n");
	printMatrix(output);

	//Sending back to the caller
	return output;
}



//Training network algorithm
void train(float inputDatas_arr[], float target_arr[], neuralNetwork* nn){
		matrix* output = feedForward(nn, inputDatas_arr);

		//Convert into matrix
		matrix* target = fromArray(target_arr);
		printf("Target matrix is : \n");
		printMatrix(target);

		//Error = target - output
		matrix* error = subMatrix(target, output, true);
		printf("Matrix error is :  \n");
		printMatrix(error);
}




//Activation functions
float sigmoid(float nbr){
	return (float)1/(1+exp(-1*nbr));
}