#include "main.h"
#define FOLDER_SIZE 1024

/**
 * main - a function that copies the content of a file to another file.
 * @ac: argument count
 * @arv: argument vector
 * Return: Always 0.
 */
int main(int ac, char **arv)
{
	int fi0, fi1, re0, re1;
	char *folder;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	folder = malloc(sizeof(char) * FOLDER_SIZE);
	if (!folder)
		return (0);

	fi1 = open(arv[1], O_RDONLY);
	error_98(fi1, folder, arv[1]);

	fi0 = open(arv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	error_99(fi0, folder, arv[2]);

	do {
		re0 = read(fi1, folder, FOLDER_SIZE);
		if (re0 == 0)
			break;
		error_98(re0, folder, arv[1]);
		re1 = write(fi0, folder, re0);
		error_99(re1, folder, arv[2]);
	} while (re1 >= FOLDER_SIZE);
	re0 = close(fi0);
	error_100(re0, folder);
	re0 = close(fi1);
	error_100(re0, folder);
	free(folder);
	return (0);
}

/**
 * error_98 - a function to check if file from does not exist or cann't read.
 * @fi0: the value to check
 * @folder: the folder
 * @arv: argument vector
 */
void error_98(int fi0, char *folder, char *arv)
{
	if (fi0 < 0)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", arv);
		free(folder);
		exit(98);
	}
}

/**
 * error_99 - a function to check if you can not create or write to file to.
 * @fi0: the value to check
 * @folder: the folder
 * @arv: argument vector
 */
void error_99(int fi0, char *folder, char *arv)
{
	if (fi0 < 0)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", arv);
		free(folder);
		exit(99);
	}
}

/**
 * error_100 - a function to check if you can not close a file descriptor.
 * @fi0: the value to check
 * @folder: the folder
 */
void error_100(int fi0, char *folder)
{
	if (fi0 < 0)
	{
		dprintf(STDERR_FILENO, "Error: can't close file descriptor %i\n", fi0);
		free(folder);
		exit(100);
	}
}
