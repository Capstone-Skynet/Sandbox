#include "nn.h"

Matrix_t* makeEmptyMatrix(unsigned char width, unsigned char depth)
{
	if (width <= 0 || depth <= 0)
	{
		printf("cannot use 0 width or 0 depth when creating empty kernal\n");
		return NULL;
	}

	Matrix_t* new_matrix = malloc(sizeof(Matrix_t));
	if (new_matrix == NULL)
	{
		printf("Error making matrix struct\n");
		return NULL;
	}

	// Create the matrix using
	new_matrix->data = malloc(sizeof(float*) * depth);
	new_matrix->width = width;
	new_matrix->depth = depth;

	// Null check matrix
	if (new_matrix->data == NULL)
	{
		printf("error while allocating memory for the matrix\n");
		return NULL;
	}
	
	// Create array inside the array
	for (unsigned char i = 0; i < depth; i++)
	{
		if ((new_matrix->data[i] = malloc(sizeof(float) * width)) == NULL)
		{
			printf("error while allocating memory for the matrix\n");
			return NULL;
		}
	}

	// Initialize all values to 0
	for (unsigned char i = 0; i < depth; i++)
	{
		for (unsigned char j = 0; j < width; j++)
		{
			new_matrix->data[i][j] = (float) 0.0;
		}
	}

	return new_matrix;
}

int randomizeMatrix(Matrix_t* matrix)
{
	for (unsigned char i = 0; i < matrix->depth; i++)
	{
		for (unsigned char j = 0; j < matrix->width; j++)
		{
			matrix->data[i][j] = rand() / (double) RAND_MAX;
		}
	}

	return 0;
}

void printMatrix(char* format, Matrix_t* matrix)
{
	for (unsigned char i = 0; i < matrix->depth; i++)
	{
		for (unsigned char j = 0; j < matrix->width; j++)
		{
			printf(format, matrix->data[i][j]);
		}
		printf("\n");
	}
}