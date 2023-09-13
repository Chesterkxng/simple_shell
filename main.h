#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*********** utilities.c *************/

int _strlen(char *s);
void prompt(void);
int space_needed(char *cmd_line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*********** exec.c ******************/

char *get_input_line(void);
void insertArgument(char **dest, char *arg);

#endif /*MAIN_H*/
