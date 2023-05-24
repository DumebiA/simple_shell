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

void promptLoop(void);

char *readInput(void);
void executeCommand(char **args);
void freeTokens(char **tokens);

void excmd(char **argv);
char *get_location(char *cmd);
void write_string(int fd, const char *str);
size_t string_length(const char *str);
size_t string_length(const char *str);
int string_compare(const char *str1, const char *str2, size_t length);
char *getenv_custom(const char *name);

#endif
