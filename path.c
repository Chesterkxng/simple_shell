#include "main.h"

/**
 * _strdup - return a copy of the string given as parameter
 *
 * @str : string to duplicate
 *
 * Return: a pointer to dynamically allocated memory containing a copy
 * of a string given as parameter
 *
 * if string is NULL or malloc fails returns NULL
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i, j;

	if (!str)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	ptr = malloc(sizeof(char) * ++i);

	if (!ptr)
		return (NULL);

	for (j = 0; j < i; j++)
		ptr[j] = str[j];

	return (ptr);
}

/**
 * _strstr - locate a substring in a string
 *
 * @haystack: pointer to the string to be scanned for a substring
 *
 * @needle: pointer to the substring to search
 *
 * Return: a pointer to the first occurence of the substring in the string,
 * else NULL
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j, pos;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		pos = i;
		j = 0;

		while (needle[j] != '\0')
		{
			if (needle[j] == haystack[i])
				i++;
			else
				break;

			j++;
		}

		if (needle[j] == '\0')
			return (haystack + pos);
	}

	return (NULL);
}

/**
 * _getenv - get the value of a environment variable
 *
 * @keyword: environment variable to search
 *
 * Return: the value of the environment variable or
 * NULL if it doesn't exist
 */
char *_getenv(char *keyword)
{
	char *value = NULL;
	int i, lkey;

	lkey = _strlen(keyword);
	if (!keyword)
		return (NULL);

	i = 0;
	while (environ[i])
	{
		value = _strstr(environ[i], keyword);

		if (value && *(value + lkey) == '=')
		{
			value = value + lkey + 1;
			break;
		}

		i++;
	}

	return (value);
}

/**
 * search_in_path - return the full path of an existing command
 *
 * @cmd: command to seach for
 *
 * Return: the full path of the command
 *
 * If the command exists in the current directory return "."
 * If the full path of the command is given and exists return "."
 * If the command cannot be found return NULL
 */
char *search_in_path(char *cmd)
{
	int len;
	struct stat st;
	char *value, *path, cmd_fullpath[4096];

	if (stat(cmd, &st) == 0)
		return (".");

	if (_getenv("PATH"))
		value = _strdup(_getenv("PATH"));

	path = strtok(value, ":");

	while (path)
	{
		_strcpy(cmd_fullpath, path);
		len = _strlen(cmd_fullpath);
		_strcpy(cmd_fullpath + len, "/");
		_strcpy(cmd_fullpath + len + 1, cmd);

		if (stat(cmd_fullpath, &st) == 0)
		{
			path = cmd_fullpath;
			break;
		}

		path = strtok(NULL, ":");
	}

	free(value);
	return (path);
}
