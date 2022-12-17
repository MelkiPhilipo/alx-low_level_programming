#include "main.h"
#include "stdio.h"
/**
 * main - shows the output
 * @n: Value of the output
 * Return: Always 0
 */
int main(void)
{
	int i;

	i = 10;
	while (i < 20)
	{
	printf("%d", i % 2);
	i++;
	}
	printf("\n");
	return (0);
}
