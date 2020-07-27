#ifndef MATRIX_H
#define MATRIX_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>



struct MATRIX{
	unsigned int row;
	unsigned int column;
	float** data;
};
typedef struct MATRIX matrix;


matrix* initializeMatrix(unsigned int row,unsigned int column);
void deleteMatrix(matrix *m); 

void randomizeMatrix(matrix* m);

void addMatrix(matrix* a, matrix* b, matrix* res);
matrix* mulMatrix(matrix* a, matrix* b);

void printMatrix(matrix* m);

bool sameNumOfRow(matrix* a, matrix* b);
bool sameNumOfColumn(matrix* a, matrix* b);
bool mulCompatibility(matrix* a, matrix* b);

#endif