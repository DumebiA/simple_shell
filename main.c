#include "main.h"
#include <stdio.h>

/**
 * main - ./hsh bourn shell
 * @argv: argv vector
 * @argc: arg count
 * Return: status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, counter);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, counter, argv);

		}
		free_all(cmd, input);
	}
	return (statue);
}
/**
 * start_env - display the environ
 * @env: array of eeniron
 * Return: Void
 */
void start_env(char **env)
{
	int a;

	for (a = 0; environ[a]; a++)
		env[a] = _strdup(environ[a]);
	env[a] = NULL;
}
/**
 * check_builtin -locate builtIn functionz
 * @cmd: commands given
 * Return: negative 1 fail 0 on success
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
