#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
* main - copies content of a file to another
* @argc: number argument
* @argv: string
*
* Return: 0
*/

int main(int argc, char *argv[])
{
	int fd_from, fd_to, ret, errno_saved;
	char buffer[BUFFER_SIZE];
	struct stat st;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	ret = fstat(fd_from, &st);
	if (ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't get stats for file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & 0666);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}

	while ((ret = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_to, buffer, ret) != ret)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			exit(99);
		}
	}
	if (ret == -1)
	{
		errno_saved = errno;
		close(fd_from);
		close(fd_to);
		errno = errno_saved;
		perror("read");
		exit(98);
	}

	ret = close(fd_from);
	if (ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	ret = close(fd_to);
	if (ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
