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
	{
		free(line);
		exit(0);
	}
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
 * Return: an array of built args
 */
char **build_args(char *cmd_line)
{
	int i = 0;
	int token_size = TOKENS_SIZE;
	char *p;
	char **args = malloc(sizeof(char *) * TOKENS_SIZE);

	if (args == NULL)
		return (NULL);

	for (i = 0; i < token_size; i++)
		args[i] = NULL;

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
/**
 * exec_cmd - a function that execute a simple command
 * @args : command arguments
 * @argv: list of shell arguments
 * @cmd_line: command line
 * Return: status
 */
void exec_cmd(char **args, char **argv, char *cmd_line)
{
	int rvalue, status, builtin_status;
	pid_t cpid;
	char *cmd_path = NULL;

	if (!args[0])
		return;
	builtin_status = get_built_in(args, cmd_line);
	if (builtin_status == 0)
	{
		cmd_path = search_in_path(args[0]);

		if (!cmd_path)
			perror(argv[0]); /* display shell name with error */
		else
		{
			cpid = fork();
			if (cpid == -1)
				perror(args[0]);
			if (cpid == 0)
			{
				if (*cmd_path == '.')
					rvalue = execve(args[0], args, environ);
				else
					rvalue = execve(cmd_path, args,
							environ);
				if (rvalue == -1)
					perror(args[0]);
			}
			else
			{
				do {
					waitpid(cpid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
				free(cmd_path);
			}
		}
	}
}
