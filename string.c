#include "main.h"
/**
 * _strlen - Entry point
 * Description:  a program that return the length of a given
 * char
 * @s: given char
 * Return: the number of characters
 */
int _strlen(char *s)
{
	int count = 0;

	while (s && s[count] != '\0')
		count++;
	return (count);
}
/**
 * prompt - a program that prompt a pattern to the stdout
 * Return: void
 */
void prompt(void)
{
	char *pattern = "$ ";

	write(1, pattern, _strlen(pattern));
}
/**
 * _strcmp - Entry point.
 * Description: a function compare two strings
 * @s1 : first char
 * @s2 : second char
 *
 * Return: the desired output.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcpy - copies the string pointed by src
 * including the termination null ('\0'), to the buffer pointed to by dest.
 *
 * @dest: pointer to destination string
 *
 * @src: pointer to source string
 *
 * Return: a pointer to the the start of string pointed by 'dest'
 */
char *_strcpy(char *dest, char *src)
{
	int i, j, ls;
	char *str = dest;

	ls = 0;
	while (src[ls] != '\0')
		ls++;

	for (i = 0, j = 0; j <= ls; i++, j++)
		dest[i] = src[j];

	return (str);
}
