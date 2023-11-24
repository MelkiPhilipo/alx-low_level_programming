#include "main.h"
/**
 * _strlen_recursion - a function that returns the length of a string
 * @s: a string to be returned
 * Return: int
 */
int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s)
	{
		i++;
		i += _strlen_recursion(s + 1);
	}
	return (i);
}
