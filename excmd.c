#include "main.h"

/**
 * excmd - function executes stored prompt
<<<<<<< HEAD
 * @command: prompt command to be executed
 * @args: array of string
 * @argv: command array
 * Return: the difference between final value of s and the initial value of str
 */

void excmd(char **args, **argv)
=======
 * @args: prompt command storage to be executed
 *
 * Return: the difference between final value of s and the initial value of str
 */

void excmd(char **args)
>>>>>>> 2a1629d13aa2879d73218cd71517aa1fdc7ca5f1
{
	char *command = NULL, *actual_command = NULL;

	pid_t pid;
	int status;

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
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		else
		{
			status = 1;
		}
	}
}
