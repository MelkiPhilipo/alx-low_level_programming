#include "main.h"

/**
 * binary_to_uint- function that converts a binary number to an unsigned int.
 * @b: is pointing to a string of 0 and 1 chars.
 * Return: the converted number, or 0.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ure;
	size_t ordh = 0;
	size_t j = 0;
	size_t jumla = 0;
	size_t pwr = 1;
	int base = 2;

	if (b == NULL)
		return (0);
	for (ure = 0; b[ure] != '\0'; ure++)
		;
	if (ure == 1 && (b[0] == '0' || b[0] == '1'))
		return (b[0] - 48);
	for (ordh = 0; b[ordh] != '\0'; ordh++)
	{
		if (b[ordh] != '0' && b[ordh] != '1')
		return (0);
		for (j = ure - 1; j > 0; j--)
		pwr = pwr * base;
		jumla = jumla + (pwr * (b[ordh] - 48));
		ure--;
		pwr = 1;
	}
	return (jumla);
}
