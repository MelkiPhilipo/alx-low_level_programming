#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_magic - prints the magic numbers of an ELF header
 * @e_ident: The e_ident field of an ELF header
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	write(1, "Magic:         ", 9);
	for (i = 0; i < EI_NIDENT; i++)
	{
		_putchar(e_ident[i] / 16 + '0');
		_putchar(e_ident[i] % 16 + '0');
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

/**
 * print_class - Prints the class of an ELF header
 * @e_ident: The e_ident field of an ELF header
 */
void print_class(unsigned char *e_ident)
{
	write(1, "Class:                                   ", 35);
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			write(1, "none\n", 5);
			break;
		case ELFCLASS32:
			write(1, "ELF32\n", 6);
			break;
		case ELFCLASS64:
			write(1, "ELF64\n", 6);
			break;
		default:
			write(1, "<unknown: ", 10);
		       _putchar(e_ident[EI_CLASS] / 16 + '0');
		       _putchar(e_ident[EI_CLASS] % 16 + '0');
		       write(1, ">\n", 2);
			break;
	}
}

/**
 * print_data - Prints the data encoding of an ELF header
 * @e_ident: The e_ident field of an ELF header
 */
void print_data(unsigned char *e_ident)
{
	write(1, "Data:                                  ", 34);
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			write(1, "none\n", 5);
			break;
		case ELFDATA2LSB:
			write(1, "2's complement, little endian\n", 30);
			break;
		case ELFDATA2MSB:
			write(1, "2's complement, big endian\n", 27);
			break;
		default:
			write(1, "<unknown: ", 10);
		        _putchar(e_ident[EI_CLASS] / 16 + '0');
			_putchar(e_ident[EI_CLASS] % 16 + '0');
			write(1, ">\n", 2);
			break;
	}
}

/**
 * print_version - Prints the version of an ELF header
 * @e_ident: The e_ident field of an ELF header
 */
void print_version(unsigned char *e_ident)
{
	write(1, "Version:                                   ", 35);
			_putchar(e_ident[EI_VERSION] + '0');
			if (e_ident[EI_VERSION] == EV_CURRENT)
				write(1, " (current)", 10);
			write(1, "\n", 1);
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header
 * @e_ident: The e_ident field of an ELF header
 */
void print_osabi(unsigned char *e_ident)
{
	write(1, "OS/ABI:                                   ", 35);
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			write(1, "UNIX - System V\n", 16);
			break;
		case ELFOSABI_HPUX:
			write(1, "HP-UX\n", 6);
			break;
		case ELFOSABI_NETBSD:
			write(1, "NetBSD\n", 7);
			break;
		case ELFOSABI_LINUX:
			write(1, "Linux\n", 6);
			break;
		case ELFOSABI_SOLARIS:
			write(1, "Sun Solaris\n", 12);
			break;
		case ELFOSABI_IRIX:
			write(1, "SGI Irix\n", 9);
			break;
		case ELFOSABI_FREEBSD:
			write(1, "FreeBSD\n", 8);
			break;
		default:

			break;
	}
}

/**
 * read_header - Read the ELF header from a file
 * @filename: The name of the file to read from
 * @header: Pointer to an Elf64_Ehdr structure to store the header
 *
 * Return: 0 on success, 98 on error
 */
int read_header(char *filename, Elf64_Ehdr *header)
{
	int fd;
	ssize_t bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: Cannot open file ", 24);
		write(2, filename, strlen(filename));
		write(2, "\n", 1);
		return (98);
	}

	bytes_read = read(fd, header, sizeof(*header));
	if (bytes_read != sizeof(*header))
	{
		write(2, "Error: Cannot read file ", 24);
		write(2, "\n", 1);
		close(fd);
		return (98);
	}

	close(fd);
	return (0);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int ret;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		write(2, "Usage: ", 7);
		write(2, argv[0], strlen(argv[0]));
		write(2, " elf_filename\n", 14);
		exit(98);
	}

	ret = read_header(argv[1], &header);
	if (ret != 0)
		exit(98);

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		write(2, argv[1], strlen(argv[1]));
		write(2, ": Not an ELF file\n", 18);
		exit(98);
	}

	write(1, "ELF Header:\n", 12);
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);

	write(1, "ABI Version:                                  ", 34);
	_putchar(header.e_ident[EI_ABIVERSION] + '0');
	write(1, "\n", 1);

	return (0);
}

/**
 * print_type - Prints the type of an ELF header
 * @header: Pointer to an Elf64_Ehdr structure
 */
void print_type(Elf64_Ehdr *header)
{
	write(1, "Type:                                  ", 34);
	switch (header->e_type)
	{
		case ET_NONE:
			write(1, "No file type\n", 13);
			break;
		case ET_REL:
			write(1, "Relocatable file\n", 17);
			break;
		case ET_EXEC:
			write(1, "Executable file\n", 16);
			break;
		case ET_DYN:
			write(1, "Shared object file\n", 19);
			break;
		case ET_CORE:
			write(1, "Core file\n", 10);
			break;
		default:
			write(1, "<unknown: ", 10);
			_putchar(header->e_type / 16 + '0');
			_putchar(header->e_type % 16 + '0');
			write(1, ">\n", 2);
			break;
	}
}

/**
 * print_entry - Prints the entry point address of an ELF header
 * @header: Pointer to an Elf64_Ehdr structure
 */
void print_entry(Elf64_Ehdr *header)
{
	char buf[18];
	int i;

	write(1, "Entry point address:                                  ", 34);
	sprintf(buf, "%#lx", header->e_entry);
	for (i = 0; buf[i]; i++)
		_putchar(buf[i]);
	write(1, "\n", 1);
}
