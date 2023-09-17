#ifndef MAIN_H
#define MAIN_H

/**###### environ var ######*/

extern char **environ;

/**##### MACROS ######*/

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, str_len(c)))

/**###### LIBS USED ######*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/**###### STRING FUNCTION ######*/

char *_strtok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *strn_cpy(char *dest, char *src, int o);
int str_len(char *c);
int put_char(char c);
int conv_int(char *c);
void put_str(char *c);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/**###### MEMORIE  MANGMENT ####*/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/**###### INPUT Function ######*/

void prompt(void);
void sign_han(int i);
char *_getline(void);

/** ###### Command parser and extractor ###*/

int path_func(char **command);
char *get_env(char *o);
char **parse_cmd(char *cmd);
int built_cmd(char **command, int r);
void read_func(char *fn, char **argv);
char *bld_cmd(char *c, char *val);
int check_builtin(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **command, char *in, int c, char **argv);
void treat_func(char *line, int counter, FILE *fd, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);

/**
 * BUILT INs
 */

void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int env_cmd(char **cmd, int er);
int cd_cmd(char **command, int r);
int help_cmd(char **command, int r);
int echo_cmd(char **command, int i);
void exit_cmd(char **command, char *in, char **argv, int i);
int print_echo(char **cmd);

/**
 * error handle and Printer
 */
void prnt_num(unsigned int i);
void num_int(int i);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
