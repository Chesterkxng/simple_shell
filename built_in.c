#include "main.h"
/**
 * get_built_in - a function that get the right built_in to execute
 * @argv: array of arguments
 * @args: array of arguments
 * @cmd_line: command_line
 * @ncmd: ncmd
 * Return: int
 */
int get_built_in(char **argv, char **args, char *cmd_line, unsigned int ncmd)
{
	builtin_func fspec[] = {
		{"exit", exit_built_in},
		{"env", print_env},
		{NULL, NULL}
	};
	int i, exec_value = 0;

	for (i = 0; fspec[i].keyword; i++)
		if (_strcmp(fspec[i].keyword, args[0]) == 0)
			exec_value = fspec[i].f(argv, args, cmd_line, ncmd);

	return (exec_value);
}
/**
 * exit_built_in - a function that exit the shell on "exit" call
 * @argv: array of args
 * @args: array of args
 * @cmd_line: command_line
 * @ncmd: ncmd
 * Return: int exit_status
 */
int exit_built_in(char **argv, char **args, char *cmd_line, unsigned int ncmd)
{
	int exit_status, isnumber;

	if (args[1] == NULL && status != 127)
		exit_status = 0;
	if (args[1] == NULL && status == 127)
		exit_status = 2;
	if (args[1])
	{
		isnumber = _isnumber(args[1]);
		if (isnumber == 0)
		{
			exit_status = 2;
			exit_error(argv, args, ncmd);
		}
		else
			exit_status = _atoi(args[1]);
	}
	free(cmd_line);
	free(args);
	exit(exit_status);
}
/**
 * print_env - a function that print all the environment variable
 * @argv: unsued args
 * @args : unused args
 * @cmd_line: command line
 * @ncmd: ncmd
 * Return: number of characters printed
 */
int print_env(char **argv, char **args, char *cmd_line, unsigned int ncmd)
{
	int i;
	(void)argv;
	(void)args;
	(void)cmd_line;
	(void)ncmd;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
	return (1);
}
