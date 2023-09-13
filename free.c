#include "main.h"
/**
 * free_args - a function that free the memory allocated
 * for the args array
 * @args: array of args
 * Return: void
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
