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
	(void) argc;

	do {
		/* display the prompt only in interactive mode */
		if (isatty(0))
			prompt();

		line = get_input_line();
		args = build_args(line);
		exec_cmd(args, argv);
		free(line);
		free(args);

	} while (1);

	return (0);
}
