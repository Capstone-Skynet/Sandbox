#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix
{
	float** data;
	unsigned char width;
	unsigned char depth;
} Matrix_t;

Matrix_t* makeEmptyMatrix(unsigned char width, unsigned char depth);
int randomizeMatrix(Matrix_t* matrix);


/* Helper functions for debugging and visualizing purposes */
void printMatrix(char* format, Matrix_t* matrix);