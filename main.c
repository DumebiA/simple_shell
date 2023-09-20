#include "main.h"

/**
 * main - Simple Shell
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		read_func(argv[1], argv);
	signal(SIGINT, sign_han);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt_func();
		input = get_line();
		if (input[0] == '\0')
		{
			continue;
		}
		his_tory(input);
		cmd = parser(input);
		if (str_cmp(cmd[0], "exit") == 0)
		{
			exit_cmd(cmd, input, argv, counter);
		}
		else if (_builtin(cmd) == 0)
		{
			st = built_cmd(cmd, st);
			free_array(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, counter, argv);

		}
		free_array(cmd, input);
	}
	return (statue);
}
/**
 * _builtin - check builtin
 * @c:command
 * Return: 0 Succes -1 Fail
 */
int _builtin(char **c)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*c == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (str_cmp(c[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * create_env - Creat Enviroment Variable
 * @env: Enviroment Variable
 * Return: Void
 */
void create_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = str_dup(environ[i]);
	env[i] = NULL;
}
