#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * read_textfile - reads a text file and prints to standard output POSIX
 * @filename:text  file
 * @letters: number of letters
 *
 * Return: actual number of letters, 0 if filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, let, w;
	char *text;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	text = malloc(sizeof(char) * letters);
	let = read(file, text, letters);
	w = write(STDOUT_FILENO, text, let);

	free(text);
	close(file);

	return (w);
}
