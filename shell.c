#include "main.h"
/**
 * main - unix command interpreter
 * Description: unix command interpreter
 * Return: 0 always success
 */
int main(void)
{
	char *line;
	char **args;

	do {
		prompt();
		line = get_input_line();
		args = build_args(line);
		exec_cmd(args);
		free(line);
	} while (1);
	return (0);
}
