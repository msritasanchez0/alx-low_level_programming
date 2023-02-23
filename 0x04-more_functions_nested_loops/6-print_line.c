#include "main.h"
/**
 * print_line -  draws a straight line in the terminal.
 * @n: The number of _ characters to be printed.
 *
 * Return: 0 (success)
 */

void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		_putchar('_');

	}
	_putchar('\n');
}
