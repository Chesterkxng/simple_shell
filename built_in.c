#include "main.h"
/**
 * get_built_in - a function that get the right built_in to execute
 * @args: array of arguments
 * Return: void
 */
void get_built_in(char **args)
{
	builtin_func fspec[] = {
		{"exit", exit_built_in},
		{NULL, NULL}
	};
	int i;

	for (i = 0; fspec[i].keyword; i++)
	{
		if (_strcmp(fspec[i].keyword, args[0]) == 0)
			fspec[i].f(args);
	}
}
/**
 * exit_built_in - a function that exit the shell on "exit" call
 * @args: array of args
 * Return: void
 */
void exit_built_in(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
		exit_status = _atoi(args[1]);
	free(args);
	exit(exit_status);
}
