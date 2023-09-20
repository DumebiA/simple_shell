#ifndef MAIN_H
#define MAIN_H

/**
 * environment variables
 */

extern char **environ;

/**
 * MACROS
 */

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, str_len(c)))

/**
 * LIBRARY
 */

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
 */

char *str_tok(char *c, const char *del);
unsigned int _delim(char c, const char *str);
char *strn_cpy(char *dest, char *src, int o);
int str_len(char *c);
int put_char(char c);
int conv_int(char *c);
void put_str(char *c);
int str_cmp(char *s, char *c);
int _alpha(int i);
void reverse_array(char *a, int l);
int int_len(int n);
char *_intochar(unsigned int n);
char *str_cat(char *c, char *i);
char *str_cpy(char *c, char *n);
char *str_chr(char *s, char c);
int strn_cmp(const char *s, const char *l, size_t o);
char *str_dup(char *s);

/**
 * MEMORY
 */

void frenv(char **n);
void *fill_array(void *a, int w, unsigned int l);
char *mem_cpy(char *d, char *r, unsigned int n);
void *ca_alloc(unsigned int s);
void *re_alloc(void *p, unsigned int os, unsigned int ns);
void free_array(char **command, char *c);

/**
 * INPUT
 */

void prompt_func(void);
void sign_han(int i);
char *get_line(void);

/**
 * PARSER
 */

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


void hash_tag(char *buff);
int his_tory(char *in);
int display_his(char **c, int s);
int _env(char **command, int r);
int cd_cmd(char **command, int r);
int help_cmd(char **command, int r);
int echo_cmd(char **command, int i);
void exit_cmd(char **command, char *in, char **argv, int i);
int showecho(char **command);


void prnt_num(unsigned int i);
void num_int(int i);
void _error(char *in, int i, char **argv);
void pr_err(char **argv, int i, char **command);

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
