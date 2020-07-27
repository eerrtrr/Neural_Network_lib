#include <stdio.h>
#include "matrix.h"


int main(int argc, char** argv){

	matrix* m = initializeMatrix(5,2);
	matrix* c = initializeMatrix(2,8);

	randomizeMatrix(m);
	printMatrix(m);
	randomizeMatrix(c);
	printMatrix(c);

	m = mulMatrix(m, c);

	printMatrix(m);

	deleteMatrix(m);
	deleteMatrix(c);

	return 0;
}