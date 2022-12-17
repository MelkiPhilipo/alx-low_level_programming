#include "main.h"

/**
 * convert_day - converts day of month to day of year, without accounting
 * for leap year
 * @month: month in number format
 * @day: day of month
 * Return: day of year
 */

int convert_day(int month, int day)
{
	switch (month)
	{
		case 2:
			day = 29 + day;
			break;
		case 3:
			day = 31 + day;
			break;
		case 4:
			day = 30 + day;
			break;
		case 5:
			day = 31 + day;
			break;
		case 6:
			day = 30 + day;
			break;
		case 7:
			day = 31 + day;
			break;
		case 8:
			day = 31 + day;
			break;
		case 9:
			day = 30 + day;
			break;
		case 10:
			day = 31 + day;
			break;
		case 11:
			day = 30 + day;
			break;
		case 12:
			day = 31 + day;
			break;
		default:
			break;
	}
	return (day);
}
