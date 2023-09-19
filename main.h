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





/**
 * STRING FUNCTION
 *
 * */

char *str_tok(char *str, const char *tok);
unsigned int _delim(char c, const char *str);
char *strn_cpy(char *dest, char *src, int o);
int str_len(char *c);
int put_char(char c);
int conv_int(char *c);
void put_str(char *c);
int str_cmp(char *s1, char *s2);
int _alpha(int c);
void reverse_array(char *arr, int len);
int int_len(int num);
char *_intochar(unsigned int n);
char *str_cat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
char *str_chr(char *s, char c);
int strn_cmp(const char *s1, const char *s2, size_t n);
char *str_dup(char *str);

/**###### MEMORIE  MANGMENT ####*/

void frenv(char **env);
void *fill_array(void *a, int el, unsigned int len);
char *mem_cpy(char *dest, char *src, unsigned int n);
void *ca_alloc(unsigned int size);
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_array(char **input, char *line);

/**###### INPUT Function ######*/

void prompt_func(void);
void sign_han(int i);
char *get_line(void);

/** ###### Command parser and extractor ###*/

int path_func(char **command);
char *get_env(char *o);
char **parser(char *cmd);
int built_cmd(char **command, int r);
void read_func(char *fn, char **argv);
char *bld_cmd(char *c, char *val);
int _builtin(char **cmd);
void create_env(char **envi);
int check_cmd(char **command, char *in, int c, char **argv);
void treat_func(char *line, int counter, FILE *fd, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);

/**
 * BUILT INs
 */

void hash_tag(char *buff);
int his_tory(char *input);
int display_his(char **cmd, int er);
int env_cmd(char **cmd, int er);
int cd_cmd(char **command, int r);
int help_cmd(char **command, int r);
int echo_cmd(char **command, int i);
void exit_cmd(char **command, char *in, char **argv, int i);
int showecho(char **cmd);

/**
 * error handle and Printer
 */
void prnt_num(unsigned int i);
void num_int(int i);
void _error(char *line, int c, char **argv);
void pr_err(char **argv, int c, char **cmd);


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
