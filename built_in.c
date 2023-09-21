#include "main.h"
/**
 * get_built_in - a function that get the right built_in to execute
 * @args: array of arguments
 * @cmd_line: command_line
 * Return: int
 */
int get_built_in(char **args, char *cmd_line)
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
			exec_value = fspec[i].f(args, cmd_line);
	}
	return (exec_value);
}
/**
 * exit_built_in - a function that exit the shell on "exit" call
 * @args: array of args
 * @cmd_line: command_line
 * Return: int exit_status
 */
int exit_built_in(char **args, char *cmd_line)
{
	char *error = "too many arguments\n";
	int exit_status;

	if (args[1] == NULL)
		exit_status = 0;
	else if (args[2] != NULL)
	{
		write(1, error, _strlen(error));
		exit_status = 1;
	}
	else
		exit_status = _atoi(args[1]);
	free(cmd_line);
	free(args);
	exit(exit_status);
}
/**
 * print_env - a function that print all the environment variable
 * @args : unused args
 * @cmd_line: command line
 * Return: number of characters printed
 */
int print_env(char **args, char *cmd_line)
{
	int i;
	(void)args;
	(void)cmd_line;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
	return (1);
}
