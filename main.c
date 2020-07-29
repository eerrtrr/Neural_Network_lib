#include <stdio.h>
#include "matrix.h"


int main(int argc, char** argv){

	matrix* m = initializeMatrix(5,2);
	matrix* c = initializeMatrix(5,2);

	randomizeMatrix(m);
	printMatrix(m);
	randomizeMatrix(c);
	printMatrix(c);

	subMatrix(m,c,false);

	printMatrix(m);

	deleteMatrix(m);
	deleteMatrix(c);

	return 0;
}