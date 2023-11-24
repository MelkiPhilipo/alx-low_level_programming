#include <stdio.h>

/**
 * print_shape - function to print a shape
 */
void print_shape(int num1, int num2) 
{
	int idx1, idx2;
	for (idx1 = 0; idx1 < num1; idx1++)
	{
		for (idx2 = 0; idx2 < num2; idx2++)
		{
			printf('#');
		}
		printf('\n');
	}
}

/** 
 * main - calls print_shape()
 *
 * Return: Always 0.
 **/

int main(void)
{
	print_shape(4, 3);
	return (0);
}
