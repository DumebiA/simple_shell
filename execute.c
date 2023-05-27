#include "main.h"

/**
 * handle_builtin - take built cmd
 * @cmd: given command
 * @er: last statu
 * Return: -1 Fail 0 Succes
 */

int handle_builtin(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", sho_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (str_cmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Fork, Wait, and Excute
 * @cmd: given command
 * @input: Input
 * @c: Shell Excution
 * @argv:  Name
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
		if (strn_cmp(*cmd, "./", 2) != 0 && strn_cmp(*cmd, "/", 1) != 0)
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
 * signal_to_handel - Take ^C
 * @sig: Hold signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
