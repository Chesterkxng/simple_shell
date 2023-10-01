#include "main.h"
/**
 * _atoi - Write a function that convert a string to an integer.
 * @s : pointer to a char
 * Return: integer.
 */

int _atoi(char *s)
{
	int i, k, num, j;

	i = 0;
	k = 0;
	num = 0;
	j = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '-' && j == 0)
		{
			k++;
		}
		if (*(s + i) >= 48 &&  *(s + i) <= 57)
		{
			if (k % 2 == 0)
			{
				num = num * 10 + (*(s + i) - 48);
			}
			else
			{
				num = num * 10 - (*(s + i) - 48);
			}
			j = i;
		}
		if (j != 0 && j != i)
		{
			break;
		}
		i++;
	}
	return (num);
}
/**
 * _isnumber - check is an input is a number or not
 *
 * @c: string to check
 *
 * Return: 1 if `c` is a number, 0 otherwise
 *
 */
int _isnumber(char *c)
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
		if (c[i] < 48 || c[i] > 57)
			return (0);
	return (1);
}
