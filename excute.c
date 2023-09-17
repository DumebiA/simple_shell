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
		{"env", env_cmd},
		{"help", help_cmd},
		{"echo", echo_cmd},
		{"history", history_dis},
		{NULL, NULL}
	};
	int n = 0;

	while ((bi + n)->command)
	{
		if (_strcmp(command[0], (bi + n)->command) == 0)
		{
			return ((bi + n)->fun(command, r));
		}
		n++;
	}
	return (-1);
}
/**
 * check_cmd - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
