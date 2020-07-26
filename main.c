
#include <stdio.h>
#include "matrix.h"


int main(int argc, char** argv){

	matrix* m = initializeMatrix(5,1);
	printMatrix(m);

	return 0;
}