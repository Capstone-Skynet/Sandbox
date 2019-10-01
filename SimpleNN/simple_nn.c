/*
 * Simple implementation of a shallow neural network in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nn.h"

int main(void)
{
	float** empty_mat = makeEmptyMatrix(5, 5);

	if (empty_mat == NULL)
	{
		printf("Error... exiting\n");
		return -1;
	}

	randomizeMatrix(empty_mat, 5, 5);
	printMatrix("%5.2f ", empty_mat, 5, 5);
	return 0;
}
