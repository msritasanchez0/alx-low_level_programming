#include <stdio.h>
/**
 * main - a program that finds and prints the first 98 Fibonacci numbers,
 *	starting with 1 and 2, followed by a new line.
 *
 * Return: 0 (success)
 */
int main(void)
{
	int a = 1, b = 2, c;
	int i;

	printf("%d, %d", a, b);

	for (i = 3; i <= 98; i++)
	{
		c = a + b;

	printf(", %d", c);

	a = b;
	b = c;
	}

	printf("\n");
	return (0);
}
