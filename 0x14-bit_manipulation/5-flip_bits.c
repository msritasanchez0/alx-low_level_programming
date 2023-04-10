#include "main.h"
/**
 * flip_bits - returns the number of bits you would need
 *	to flip to get from one number to another.
 * @n: first number
 * @m: second number
 *
 * Return: number of changed bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long zii = n ^ m;
	unsigned int bits = 0;

	while (zii > 0)
	{
		bits += (zii & 1);
		zii >>= 1;
	}
	return (bits);
}
