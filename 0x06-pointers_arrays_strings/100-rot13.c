#include "main.h"
/**
 * rot13 - rotate characters 13 places in the alphabet
 * @hi: string
 * Return: string converted to rot13
 */

char *rot13(char *hi)
{
	int index, count;

	char minus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char mayus[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (index = 0; hi[index] != '\0'; ++index)
	{
		for (count = 0; minus[count] != '\0' ; count++)
		{
			if (hi[index] == minus[count])
			{
				hi[index] = mayus[count];
				break;
			}
		}
	}
	hi[index] = '\0';
	return (hi);
}
