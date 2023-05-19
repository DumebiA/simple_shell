#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void excmd(char **argv);
void parseInput(char *lineptr, char ***argv);
char *get_location(char *cmd);

#endif
