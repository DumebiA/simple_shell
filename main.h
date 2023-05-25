#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <sys/wait.h>

extern char **environ;
#define MAX_COMMAND_LENGTH 100
<<<<<<< HEAD
void input_prompt(void);
char *get_line(void);
void excmd(char *command);
int main(void);
=======
#define MAX_ARGS 10
>>>>>>> 19c0325598e42686cd97ab2d677f2bc365211832


#endif
