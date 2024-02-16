#include "main.h"

/**
 * create_file - a function that creates a file with given text content
 * @filename: The name of the file to be created.
 * @text_content: A NULL-terminated string to be written to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int faili, result = 1, hesnamba = 0;

	if (!filename)
		return (-1);
	faili = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (faili == -1)
		return (-1);
	if (text_content)
	{
		while (text_content[hesnamba])
			hesnamba++;
		result = write(faili, text_content, hesnamba);
	}
	if (result == -1)
		return (-1);
	close(faili);
	return (1);
}

