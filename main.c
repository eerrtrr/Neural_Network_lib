
#include <stdio.h>
#include "matrix.h"


int main(int argc, char** argv){

	matrix* m = initializeMatrix(5,1);
	printMatrix(m);
	randomizeMatrix(m);
	printMatrix(m);
	deleteMatrix(m);

	return 0;
}