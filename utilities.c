/**
 * _strcat - concatenates two strings
 *
 * @dest: destination string
 *
 * @src: source string
 *
 * Return: a pointer to the start of the destination string
 */
char *_strcat(char *dest, char *src)
{
	char *str = dest;
	int i, j, ls, ld;

	ls = 0;
	while (str[ls] != '\0')
		ls++;

	ld = 0;
	while (str[ld] != '\0')
		ld++;


	for (i = ld, j = 0; i <= ld + ls; i++, j++)
		dest[i] = src[j];

	return (str);
}

/**
 * itoa - converts an integer to a string
 *
 * @n: number to convert
 *
 * @buffer: buffer to store the converted number
 *
 * Return: the converted number is string
 */
char *itoa(unsigned int n, char *buffer)
{
	if (n / 10 != 0)
		buffer = itoa(n / 10, buffer);

	*buffer = n % 10 + '0';
	buffer++;

	return (buffer);
}

/**
 * startwith - checks if a string starts with a given substring
 *
 * @str: string in which to search for a given substring
 *
 * @substr: substring to search in the string
 *
 * Return: 1 if the substring is found at the start of the string
 * otherwise return 0
 *
 * if `str` or `substr` is NULL or  empty, return 0
 */
int startwith(char *str, char *substr)
{
	int i = 0, j = 0;

	if (!str || !substr || !*str || !*substr)
		return (0);

	while (substr[j] != '\0')
		j++;

	while (str[i] == substr[i] && substr[i] != '\0')
		i++;

	if (j != i)
		return (0);

	return (1);
}
