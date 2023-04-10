#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <errno.h>

/**
 * print_error - prints error message to stderr and exits with status code 98
 * @msg: error message
 *
 * Return: void
 */
void print_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(98);
}

/**
 * main - displays the information contained in the ELF header at the start
 *        of an ELF file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd, i;
	off_t offset;
	ssize_t n;
	Elf64_Ehdr elf_header;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("open");

	/* Read the magic number from the start of the file. */
	n = read(fd, e_ident, EI_NIDENT);
	if (n != EI_NIDENT || memcmp(e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "%s: not an ELF file\n", argv[1]);
		return (98);
	}

	/* Use lseek to move the file offset to the start of the ELF header. */
	offset = lseek(fd, 0, SEEK_SET);
	if (offset == -1)
		print_error("lseek");

	/* Read the ELF header into a struct. */
	n = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (n != sizeof(Elf64_Ehdr))
		print_error("read");

	/* Print the required information contained in the ELF header. */
	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");

	printf("Class:                             %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:                              %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("OS/ABI:                            %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "unknown");
	printf("ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("Type:                              %s\n", elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" : elf_header.e_type == ET_DYN ? "DYN (Shared object file)" : elf_header.e_type == ET_REL ? "REL (Relocatable file)" : "unknown");
	printf("Entry point address:               %lx\n", elf_header.e_entry);
	printf("\n");

	if (close(fd) == -1)
		print_error("close");

	return (0);
}
