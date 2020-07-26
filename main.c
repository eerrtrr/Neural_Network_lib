
#include <stdio.h>
#include "matrix.h"


int main(int argc, char** argv){

	matrix* m = initializeMatrix(5,1);
	matrix* c = initializeMatrix(5,8);
	matrix* u = initializeMatrix(5,8);
	printMatrix(m);
	randomizeMatrix(m);
	printMatrix(m);
	printMatrix(c);
	randomizeMatrix(c);
	printMatrix(c);
	addMatrix(m, c, u);
	deleteMatrix(m);
	deleteMatrix(c);
	return 0;
}