#include "main.h"
/**
 * get_built_in - a function that get the right built_in to execute
 * @args: array of arguments
 * Return: int
 */
int get_built_in(char **args)
{
	builtin_func fspec[] = {
		{"exit", exit_built_in},
		{"env", print_env},
		{NULL, NULL}
	};
	int i, exec_value = 0;

	for (i = 0; fspec[i].keyword; i++)
	{
		if (_strcmp(fspec[i].keyword, args[0]) == 0)
			exec_value = fspec[i].f(args);
	}
	return (exec_value);
}
/**
 * exit_built_in - a function that exit the shell on "exit" call
 * @args: array of args
 * Return: int exit_status
 */
int exit_built_in(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
		exit_status = _atoi(args[1]);
	free(args);
	exit(exit_status);
}
/**
 * print_env - a function that print all the environment variable
 * @args : unused args
 * Return: number of characters printed
 */
int print_env(char **args)
{
	int i, nprint = 0;
	(void)args;

	for (i = 0; environ[i] != NULL; i++)
	{
		nprint += write(1, environ[i], _strlen(environ[i]));
		nprint += _putchar('\n');
	}
	return (nprint);
}
