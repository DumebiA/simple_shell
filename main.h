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

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void excmd(char **args);
<<<<<<< HEAD
=======
char *find_executable(const char *command);
char *construct_file_path(const char *directory, const char *command);
char **tokenise_path(const char *path);
char *get_path(void);
int is_executable_file(const char *file_path);
>>>>>>> 962a98fb9947d6e403403e73d67fffccceb56f7e

#endif
