#include "main.h"
/**
 * _strcpy - copies the string pointed to by src
 * @dest: destination
 * @src: source
 *
 * Return: String
 */
char *_strcpy(char *dest, char *src)
{
	int index = 0;

	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}

	return (dest);
}
