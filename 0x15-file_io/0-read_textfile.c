#include "main.h"

/**
 * read_textfile - unction that reads a text file and prints it to the POSIX
 * standard output.
 * @filename: the file to be opened or read.
 * @letters: is the number of letters to be read and print.
 * Return: Always 0.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filedes;
	ssize_t _soma, _andika;
	char *buffer;

	if (!filename)
	{
		return (0);
	}
	filedes = open(filename, O_RDONLY);
	if (filedes == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	_soma = read(filedes, buffer, letters);
	if (_soma == -1)
	{
		free(buffer);
		close(filedes);
		return (0);
	}
	_andika = write(STDOUT_FILENO, buffer, _soma);
	if (_andika == -1)
	{
		free(buffer);
		close(filedes);
		return (0);
	}
	close(filedes);
	return (_soma);
}
