#include <stdio.h>

/**
 * main -a c program that prints followed by a new line to the standard error
 *
 * Return: 0 (Success)
 */
int main(void)
{
	write(2, "and that piece of art is useful\- Dora Korpar, 2015-10-19\n", 61);
	return (1);
}
