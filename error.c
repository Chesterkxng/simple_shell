#include "main.h"
/**
 * print_error - print error when shell cannot be executed
 *
 * @shell: first argument of the shell interpreter
 *
 * @cmd: command to execute
 *
 * @ncmd: number of the command to execute
 */
void print_error(char *shell, char *cmd, unsigned int ncmd)
{
	char msg[1024];
	char *istr, numstr[15];

	istr = itoa(ncmd, numstr);
	*istr = '\0';

	_strcpy(msg, shell);
	_strcat(msg, ": ");
	_strcat(msg, numstr);
	_strcat(msg, ": ");
	_strcat(msg, cmd);
	_strcat(msg, ": ");
	_strcat(msg, "not found\n");

	write(2, msg, _strlen(msg));
}
/**
 * exit_error - print error when shell cannot be executed
 *
 * @argv: args
 *
 * @args: args
 *
 * @ncmd: number of the command to execute
 */
void exit_error(char **argv, char **args, unsigned int ncmd)
{
	char msg[1024];
	char *istr, numstr[15];

	istr = itoa(ncmd, numstr);
	*istr = '\0';

	_strcpy(msg, argv[0]);
	_strcat(msg, ": ");
	_strcat(msg, numstr);
	_strcat(msg, ": ");
	_strcat(msg, args[0]);
	_strcat(msg, ": ");
	_strcat(msg, "Illegal number: ");
	_strcat(msg, args[1]);
	_strcat(msg, "\n");

	write(2, msg, _strlen(msg));
}
