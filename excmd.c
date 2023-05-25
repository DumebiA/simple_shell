#include "main.h"

/**
 * excmd - function executes stored prompt
 * @args: command and arguments to be executed
 *
 * Return: None
 */

void excmd(char **args)
{
	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		char error[] = "child process failed\n";
		write(STDERR_FILENO, error, sizeof(error) - 1);
		return;
	}

	if (pid == 0)
	{
		char *envp[] = {NULL};
		if (execve(args[0], args, envp) == -1)
		{
			char error[] = "./hsh: command not found\n";
			write(STDERR_FILENO, error, sizeof(error) - 1);
			exit(1);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
			{
				char error[] = "command failed\n";
				write(STDERR_FILENO, error, sizeof(error) - 1);
			}
		}
	}
}
