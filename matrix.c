#include "matrix.h"


//A simple fct to allocate memory of the matrix and return a pointer 
matrix* initializeMatrix(unsigned int row,unsigned int column){
	matrix* m = malloc(sizeof(matrix));

	if(m == NULL){
		printf("Matrix memory allocation has failed\n");
		return NULL;
	}

	m->row = row;	m->column = column;
	
	m->data = (float **)malloc(row * sizeof(float *));
  	for(int i=0; i<row; i++){
   		m->data[i] = (float *)malloc(column*sizeof(float));
  	}

	return m;
}

//Desallocate matrix element by ekement
void deleteMatrix(matrix *m){
	if(m == NULL){
		printf("The matrix is NULL\n");
		return;
	}

	for(int i=0; i<m->row; i++){
		free(m->data[i]);
		m->data[i] = NULL;
	}

	free(m->data);
	free(m);

	m = NULL;
}


//Randomize matrix data between -1 & 1
void randomizeMatrix(matrix* m){
	time_t t;
   	srand((unsigned) time(&t));

   	for(int i=0; i<m->row; i++){
   		for(int k=0; k<m->column; k++){
    		m->data[i][k] = (float)(rand()%101)/50 -1;
   		}
   	}

   	sleep(1);
}

//Properly print a matrix on the console
void printMatrix(matrix* m){
	if(m == NULL){
		printf("The matrix is NULL\n");
		return;
	}

	printf("Matrix %p %ix%i\n", m, m->row, m-> column);
	for(int i=0; i<m->row; i++){
		for(int k=0; k<m->column; k++){
			printf("%f ", m->data[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}


//Bool fct, return true if matrixes have the same number of row
bool sameNumOfRow(matrix* a, matrix* b){
	return (a->row == b->row);
}

//Bool fct, return true if matrixes have the same number of column
bool sameNumOfColumn(matrix* a, matrix* b){
	return(a->column == b->column);
}

//Bool fct, return true if matrixes can be multiply
bool mulCompatibility(matrix* a, matrix* b){
	return(a->column == b->row);	
}

d
//Add 2 matrixes
matrix* addMatrix(matrix* a, matrix* b, bool res){
	if(a == NULL || b == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}
	if(sameNumOfColumn(a, b) && sameNumOfRow(a, b)){
		if(!res){
			if(sameNumOfColumn(a, b) && sameNumOfRow(a, b)){
				for(int i=0; i<a->row; i++){
	   				for(int k=0; k<a->column; k++){
	    				a->data[i][k] = a->data[i][k] + b->data[i][k];
	   				}
	  		 	}
			}

			return NULL;
		}

		else{
			matrix* res = initializeMatrix(a->row, a->column);

			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	    			res->data[i][k] = a->data[i][k] + b->data[i][k];
	   			}
	  		}

			return res;
		}
	}

	else{
		printf("Number of rows and columns must match\n");
		return NULL;
	}
}

//Substract 2 matrixes
matrix* subMatrix(matrix* a, matrix* b, bool res){
	if(a == NULL || b == NULL){
		printf("\n\nArgument()s is/are NULL\n\n");
		return NULL;
	}
	if(sameNumOfColumn(a, b) && sameNumOfRow(a, b)){
		if(!res){
			mulMatScalar(b, -1.0, false);
			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	    			a->data[i][k] = a->data[i][k] + b->data[i][k];
	   			}
	  		 }

			return NULL;
		}

		else{
			matrix* res = initializeMatrix(a->row, a->column);
			mulMatScalar(b, -1.0, false);
			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	    			res->data[i][k] = a->data[i][k] + b->data[i][k];
	   			}
	  		}

			return res;
		}
	}

	else{
		printf("\n\nNumber of rows and columns must match\n\n");
		return NULL;
	}
}

//Multiply 2 matrixes
matrix* mulMatrix(matrix* a, matrix* b, bool res){
	if(a == NULL && b == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}
	if(mulCompatibility(a, b)){
		if(res){
			matrix* res = initializeMatrix(a->row, b->column);
			for(int i=0; i<a->row; i++){
	   			for(int k=0; k<b->column; k++){
	   				float sum = 0;
	   				for(int u=0; u<a->column; u++){
	    				sum += a->data[i][u]*b->data[u][k];
	    			}
	    			res->data[i][k] = sum;
	    		}   			
	  		}

	  		return res;
	  	}

	  	else{
	  		matrix* res = initializeMatrix(a->row, b->column);
	  		for(int i=0; i<a->row; i++){
	   			for(int k=0; k<b->column; k++){
	   				float sum = 0;
	   				for(int u=0; u<a->column; u++){
	    				sum += a->data[i][u]*b->data[u][k];
	    			}
	    			res->data[i][k] = sum;
	    		}   			
	  		}

	  		for(int i=0; i<a->row; i++){
	   			for(int k=0; k<a->column; k++){
	   				a->data[i][k] = res->data[i][k];
	    		}   			
	  		}
	  		deleteMatrix(res);
	  		return a;
	  	}
	}

	else{
		printf("Number of rows and columns must match\n");
		return NULL;
	}
}

//Multiply a matrix by a scalar
matrix* mulMatScalar(matrix* a, float scalar, bool res){
	if(a == NULL){
		printf("Argument()s is/are NULL\n");
		return NULL;
	}

	if(!res){
		for(int i=0; i<a->row; i++){
			for(int k=0; k<a->column; k++){
				a->data[i][k] *= scalar; 
			}
		}

		return NULL;
	}

	else{
		matrix* res = initializeMatrix(a->row, a->column);
		for(int i=0; i<a->row; i++){
			for(int k=0; k<a->column; k++){
				res->data[i][k] = res->data[i][k]*scalar; 
			}
		}

		return res;
	}
}