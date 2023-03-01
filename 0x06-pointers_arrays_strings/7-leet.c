#include "main.h"
/**
 * leet - encode a string into 1337
 * @s: string
 * Return: encoded string `s`
 */

char *leet(char *s)
{
	int i;
	char c;

	for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];
		if (c == 'a' || c == 'A')
		{
			s[i] = '4';
		}
		else if (c == 'e' || c == 'E')
		{
			s[i] = '3';
		}
		else if (c == 'o' || c == 'O')
		{
			s[i] = '0';
		}
		else if (c == 't' || c == 'T')
		{
			s[i] = '7';
		}
		else if (c == 'l' || c == 'L')
		{
			s[i] = '1';
		}
		else
	}
	return (s);
	
}
