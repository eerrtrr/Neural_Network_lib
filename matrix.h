#ifndef MATRIX_H
#define MATRIX_H


#include <stdio.h>
#include <stdlib.h>


struct MATRIX{
	unsigned int row;
	unsigned int column;
	float** data;
};
typedef struct MATRIX matrix;


matrix* initializeMatrix(unsigned int row,unsigned int column);
void deleteMatrix(matrix *m); 

void randomize(matrix* m);

void printMatrix(matrix* m);

#endif