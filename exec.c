#include "main.h"
/**
 * get_input_line - get user input from stdin
 *
 * Return: the user input line
 */
char *get_input_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
		exit(EXIT_FAILURE);
	return (line);
}
