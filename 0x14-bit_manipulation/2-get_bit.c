#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index.
 * @index: index of the bit
 * @n: The bit
 *
 * Return: value of the bit at index
 *	index or -1 if an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	if (0 == (n & (1 << index)))
		return (0);
	return (1);
}
