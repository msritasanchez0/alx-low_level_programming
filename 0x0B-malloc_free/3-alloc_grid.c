#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width to input
 * @height: height to input
 *
 * Return: pointer to 2 dimensional array
 */
int **alloc_grid(int width, int height)
{
	int **matrix;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	matrix = malloc(sizeof(int *) * height);

	if (matrix == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
	{
		matrix[x] = malloc(sizeof(int) * width);
		if (matrix[x] == NULL)
		{
			for (; x >= 0; x--)
			free(matrix[x]);

		free(matrix);
		return (NULL);
		}
	}
	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			matrix[x][y] = 0;
	}
	return (matrix);
}
