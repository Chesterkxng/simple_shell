#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*********** Global variables *********/
#define TOKENS_SIZE 64
#define DELIMITER " \n"

extern char **environ;

/*********** structures ***************/
/**
 * struct built_in_func - a structure that store the built in functions
 * @keyword: the cmd key
 * @f: pointer to function
 */
typedef struct built_in_func
{
	char *keyword;
	int (*f)(char **args, char *cmd_line);
} builtin_func;

/*********** string.c *************/

int _strlen(char *s);
void prompt(void);
int _strcmp(char *s1, char *s2);
int _putchar(char c);

/************ memory.c ****************/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*********** int.c ********************/

int _atoi(char *s);

/*********** exec.c ******************/

char *get_input_line(void);
void insertArgument(char **dest, char *arg);
char **build_args(char *cmd_line);
void exec_cmd(char **args, char **argv, char *cmd_line);

/*********** built_in.c **************/

int get_built_in(char **args, char *cmd_line);
int exit_built_in(char **args, char *cmd_line);
int print_env(char **args, char *cmd_line);

/*********** free.c *****************/

void free_args(char **args);

#endif /*MAIN_H*/
