#include "main.h"

/**
 * built_cmd - Handle Builtin Command
 * @command: Parsed Command
 * @r:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int built_cmd(char **command, int r)
{
	 bul_t bi[] = {
		{"cd", cd_cmd},
		{"env", _env},
		{"help", help_cmd},
		{"echo", echo_cmd},
		{"history", display_his},
		{NULL, NULL}
	};
	int n = 0;

	while ((bi + n)->command)
	{
		if (str_cmp(command[0], (bi + n)->command) == 0)
		{
			return ((bi + n)->fun(command, r));
		}
		n++;
	}
	return (-1);
}
/**
 * check_cmd - Excute Simple Shell Command (Fork,Wait,Excute)
 * @command:Parsed Command
 * @in: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmd(char **command, char *in, int c, char **argv)
{
	int s;
	pid_t p;

	if (*command == NULL)
	{
		return (-1);
	}

	p = fork();
	if (p == -1)
	{
		perror("Error");
		return (-1);
	}

	if (p == 0)
	{
		if (strn_cmp(*command, "./", 2) != 0 && strn_cmp(*command, "/", 1) != 0)
		{
			path_func(command);
		}

		if (execve(*command, command, environ) == -1)
		{
			_error(command[0], c, argv);
			free(in);
			free(command);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&s);
	return (0);
}
/**
 * sign_han - Handle
 * @i:Captured Signal
 * Return: Void
 */
void sign_han(int i)
{
	if (i == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
