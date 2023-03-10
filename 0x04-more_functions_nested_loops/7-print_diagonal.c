#include "main.h"
/**
 * print_diagonal -  draws a diagonal line in the terminal.
 * @n: The number of _ characters to be printed.
 *
 * Return: 0 (success)
 */

void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
		for (j = 0; j < i; j++)
			_putchar(' ');
		_putchar('\\');

		if (i == n - 1)
			continue;

		_putchar('\n');
		}
	}

	_putchar('\n');
}
