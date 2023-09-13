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
/**
 * insertArgument - a function that fill the informations in the struct
 * @dest: array
 * @arg: array of args
 * Return: void
 */
void insertArgument(char **dest, char *arg)
{
	int i = 0;

	while (*(dest + i) != NULL)
		i++;
	*(dest + i) = arg;
}
/**
 * **build_args - a function that return args
 * @cmd_line: command line caught by the getline cmd
 * Return: an array of buit args
 */
char **build_args(char *cmd_line)
{
	int i = 0;
	int token_size = TOKENS_SIZE;
	char *p;
	char **args = malloc(sizeof(args) * TOKENS_SIZE);

	if (args == NULL)
		return (NULL);
	p = strtok(cmd_line, DELIMITER);

	while (p != NULL)
	{
		insertArgument(args, p);
		p = strtok(NULL, DELIMITER);
		i++;
		if (i > token_size)
		{
			args = _realloc(args, token_size,  token_size * 2);
			if (args == NULL)
				return (NULL);
			token_size *= 2;
		}
	}
	return (args);
}
