#include "matrix.h"


matrix* initializeMatrix(unsigned int row,unsigned int column){
	matrix* m = malloc(sizeof(matrix));

	if(m == NULL){
		printf("Matrix memory allocation has failed\n");
		exit(EXIT_FAILURE);
	}

	m->row = row;	m->column = column;
	
	m->data = (float **)malloc(row * sizeof(float *));
  	for(int i=0; i<row; i++){
   		m->data[i] = (float *)malloc(column*sizeof(float));
  	}

	return m;
}


void deleteMatrix(matrix *m){
	if(m == NULL){
		printf("The matrix is NULL\n");
		exit(EXIT_FAILURE);
	}

	for(int i=0; i<m->row; i++){
		free(m->data[i]);
		m->data[i] = NULL;
	}

	free(m->data);
	free(m);

	m = NULL;
}



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


bool sameNumOfRow(matrix* a, matrix* b){
	return (a->row == b->row);
}

bool sameNumOfColumn(matrix* a, matrix* b){
	return(a->column == b->column);
}

bool mulCompatibility(matrix* a, matrix* b){
	return(a->column == b->row);	
}


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