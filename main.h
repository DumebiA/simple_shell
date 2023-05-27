#ifndef _MAIN_H_
#define _MAIN_H_


extern char **environ;


#define PRINTER(c) (write(STDOUT_FILENO, c, str_len(c)))
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>




char *str_dup(char *str)
int put_char(char c);
char _atoi(char *s);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *str_cat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
char *str_chr(char *s, char c);
int strn_cmp(const char *s1, const char *s2, size_t n);
char *str_tok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *strn_cpy(char *dest, char *src, int n);
int str_len(char *s);
void _puts(char *str);
int str_cmp(char *s1, char *s2);
int _isalpha(int c);



void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
void free_env(char **env);
void *fill_array(void *a, int el, unsigned int len);
char *mem_cpy(char *dest, char *src, unsigned int n);

void signal_to_handel(int sig);
char *_getline(void);
void prompt(void);



int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void start_env(char **env);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);


int history_dis(char **cmd, int er);
int sho_env(char **cmd, int er);
int echo_bul(char **cmd, int er);
void  exit_built(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);
void hashtag_handle(char *buff);
int history(char *input);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);


void print_number(unsigned int n);
void _prerror(char **argv, int c, char **cmd);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);


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
