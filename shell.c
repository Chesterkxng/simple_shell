#include "main.h"
/**
 * main - unix command interpreter
 * Description: unix command interpreter
 * Return: 0 always success
 */
int main(void)
{
	char *line;
	int n = 0;
	char *args[] = {NULL, NULL};

	do {
		prompt();
		line = get_input_line();
		n = _strlen(line);
		line[n - 1] = '\0';
		args[0] = line;
		exec_cmd(args);
		free(line);
	} while (1);
	return (0);
}
