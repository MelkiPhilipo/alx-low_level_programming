#include "function_pointers.h"

/**
 * int_index - search for an integer
 * @array: pointer to an array
 * @size: number fo elements in the array
 * @cmp: pointer to a function to be used to compare values
 *
 * Return: successful (0)
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i, r;

	if (size > 0 && array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			r = cmp(array[i]);
			if (r)
				break;
		}
		if (i < size)
			return (i);
	}
	return (-1);
}
