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
int status;

/*********** structures ***************/
/**
 * struct built_in_func - a structure that store the built in functions
 * @keyword: the cmd key
 * @f: pointer to function
 */
typedef struct built_in_func
{
	char *keyword;
	int (*f)(char **argv, char **args, char *cmd_line, unsigned int ncmd);
} builtin_func;

/*********** string.c *************/

int _strlen(char *s);
void prompt(void);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_strcpy(char *dest, char *src);

/************ memory.c ****************/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*********** int.c ********************/

int _atoi(char *s);
int _isnumber(char *c);

/*********** exec.c ******************/

char *get_input_line(int status);
void insertArgument(char **dest, char *arg);
char **build_args(char *cmd_line);
int exec_cmd(char **args, char **argv, char *cmd_line, unsigned int ncmd);

/*********** built_in.c **************/

int get_built_in(char **argv, char **args, char *cmd_line, unsigned int ncmd);
int exit_built_in(char **argv, char **args, char *cmd_line, unsigned int ncmd);
int print_env(char **argv, char **args, char *cmd_line, unsigned int ncmd);

/*********** path.c ******************/
char *_strstr(char *haystack, char *needle);
char *_strdup(char *str);
char *_getenv(char *keyword);
char *search_in_path(char *cmd);

/*********** utilities.c **************/
char *_strcat(char *dest, char *src);
char *itoa(unsigned int, char *buffer);
int startwith(char *str, char *substr);

/*********** free.c *****************/

void free_args(char **args);


/*********** error.c ***************/
void print_error(char *shell, char *cmd, unsigned int ncmd);
void exit_error(char **argv, char **args, unsigned int ncmd);

#endif /*MAIN_H*/
