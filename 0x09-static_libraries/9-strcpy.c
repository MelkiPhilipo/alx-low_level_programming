#include "main.h"

/**
 * _strcpy - a function that copies the string pointed to by src
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * @dest: A point to destination of string
 * @src: A pointer to source string to copy from
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}
