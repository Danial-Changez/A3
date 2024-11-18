#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "a3q2_header.h"

// The main function parses the f.dat file, stores information in arrays, and applies the downHeap algorithm.
int main(void)
{
	int array[20][10];
	int key[20];
	int i = 0, j = 0, count = 0;

	// Open the file
	FILE *fp = fopen("f.dat", "r");
	if (!fp)
	{
		printf("Error: Unable to open file 'f.dat'. Ensure the file exists and is accessible.\n");
		return 1;
	}

	// Read the file into a 2D array
	for (i = 0; i < 20; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			fscanf(fp, "%d", &(array[i][j]));
			if (array[i][j] > 99)
			{
				printf("Error: File 'f.dat' contains invalid data. Only two-digit integers are allowed.\n");
				fclose(fp);
				return 1;
			}
			count++;
		}
	}

	// Evaluate keys for the heap
	for (i = 0; i < 20; ++i)
	{
		key[i] = array[i][0] + array[i][1] + array[i][2];
	}

	// Apply the downHeap algorithm to construct the max-heap
	for (i = 19; i >= 0; --i)
	{
		downHeap(key, i, array);
	}

	// Print the resulting heap as a 20x10 array
	for (i = 0; i < 20; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			if (array[i][j] < 10)
			{
				printf("0%d ", array[i][j]); // Pad single-digit numbers with a leading zero
			}
			else
			{
				printf("%d ", array[i][j]);
			}
		}
		printf("\n");
	}

	fclose(fp); // Close the file after usage
	return 0;
}
