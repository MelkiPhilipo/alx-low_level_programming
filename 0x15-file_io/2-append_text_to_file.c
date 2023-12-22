#include "main.h"

/**
 * append_text_to_file - a function that append text to the file.
 * @filename: a file to be created and print
 * @text_content: a text to append
 * Return: on success will be 1, but on failure will be -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int filedes, _andika;
	size_t i = 0;

	if (!filename)
		return (-1);

	filedes = open(filename, O_WRONLY | O_APPEND);
	if (filedes == -1)
		return (-1);

	if (!text_content)
	{
		close(filedes);
		return (1);
	}

	_andika = write(filedes, text_content, strlen(text_content));
	if (_andika == -1)
	{
		close(filedes);
		return (-1);
	}
	_andika = i;
	if (i != strlen(text_content))
	{
		close(filedes);
		return (-1);
	}

	close(filedes);
	return (1);
}
