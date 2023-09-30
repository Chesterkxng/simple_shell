#include "main.h"
/**
 * main - unix command interpreter
 * @argc: number of arguments
 * @argv: list of shell arguments
 * Description: unix command interpreter
 * Return: 0 always success
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status = 0;
	unsigned int ncmd = 1;
	(void) argc;

	do {
		/* display the prompt only in interactive mode */
		if (isatty(0))
			prompt();

		line = get_input_line(status);
		args = build_args(line);
		status = exec_cmd(args, argv, line, ncmd);
		ncmd++;
		free(line);
		free(args);

	} while (status);

	if (status == 1)
		return (EXIT_SUCCESS);

	return (status);
}
