#include "main.h"
/**
 * print_triangle - prints a triangle, followed by a new line.
 * @size: size of the triangle
 *
 */

void print_triangle(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 1; i <= size; i++)
		{
			for (i = size - i; j > 0; i--)
				_putchar(' ');
		for (j = 0; j < i; j++)
			_putchar('#');

		if (i == size)
			continue;

		_putchar('\n');
		}
	}
	_putchar('\n');
}
