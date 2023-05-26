#include "main.h"

/**
 * excmd - function executes stored prompt
 * @command: prompt command to be executed
 * @args: array of string
 * @argv: command array
 * Return: the difference between final value of s and the initial value of str
 */

void excmd(char **args, **argv)
{
	char *command = NULL, *actual_command = NULL;

	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		char error[] = "child process failed\n";

		write(STDERR_FILENO, error, sizeof(error) - 1);
		return;
	}

	actual_commad = environ(command);

	if (pid == 0)
	{
		if (execve(actual_command, args, NULL) == -1)
		{
			char error[] = "./hsh: command not found\n";

			write(STDERR_FILENO, error, sizeof(error) - 1);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
