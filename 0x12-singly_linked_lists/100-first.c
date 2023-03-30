#include <stdio.h>

void firstfunc(void) __attribute__ ((constructor));

/**
 * first - prints a sentence before the main
 *	function is executed
 */
void first(void)
{
	char *m;

	m = "You're beat! and yet, you must allow,\nI bore my house upon my back!\n";
	printf("%s", m);
}
