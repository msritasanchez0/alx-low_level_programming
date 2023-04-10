#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
/**
 * create_file - creates a file
 * @filename: pointerto file being created
 * @text_content: content file
 *
 * Return: 1 (success), -1 (fail)
 */
int create_file(const char *filename, char *text_content)
{
	int fd, ret, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	len = strlen(text_content);
	ret = write(fd, text_content, len);
	if (ret == -1 || ret < len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
