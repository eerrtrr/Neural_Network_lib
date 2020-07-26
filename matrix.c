#include "matrix.h"


matrix* initializeMatrix(unsigned int row,unsigned int column){
	matrix* m = malloc(sizeof(matrix));

	if(m == NULL){
		printf("Matrix memory allocation has failed\n");
		exit(EXIT_FAILURE);
	}

	m->row = row;	m->column = column;
	
	m->data = malloc(row * sizeof(float));
  	for (int i=0; i<row; i++){
   		m->data[i] = malloc(column*sizeof(float));

   		for(int k=0; k<column; k++){
			m->data[i][k] = 0.0;
		}
  	}

	return m;
}

void printMatrix(matrix* m){
	printf("Matrix %ix%i\n", m->row, m-> column);
	for(int i=0; i<m->row; i++){
		for(int k=0; k<m->column; k++){
			printf("%f ", m->data[i][k]);
		}

		printf("\n");
	}
}