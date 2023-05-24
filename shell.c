#include "main.h"

/**
 * input_prompt - displays prompt to be inputed
 */

void input_prompt()
{
	char prompt[] = "($) ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * get_line - reads commands basically
 */

char* get_line()
{
	size_t length = 0;
	ssize_t nreads;
	size_t input_size = MAX_COMMAND_LENGTH;
	char* cmd;

	cmd = (char*)malloc(input_size * sizeof(char));

	nreads = getline(&cmd, &input_size, stdin);

	if (nreads == -1)
	{
		free(cmd);
		cmd = NULL;
	}
	else
	{
		while (cmd[length] != '\n' && cmd[length] != '\0')
		{
			length++;
		}
		cmd[length] = '\0';
	}

	return (cmd);
}

/**
 * excmd - function executes stored prompt
 * @command: prompt command storage to be executed
 *
 * Return: the difference between final value of s and the initial value of str
 */

void excmd(char* command)
{
	pid_t pid;
	char* args[2];

	pid = fork();

	if (pid < 0)
	{
		char error[] = "child process failed\n";
		write(STDERR_FILENO, error, sizeof(error) - 1);
		return;
	}

	if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;

		if (execve(command, args, NULL) == -1)
		{
			char error[] = "./hsh: not found\n";
			write(STDERR_FILENO, error, sizeof(error) - 1);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - prints main function
 *
 * Return: 0 if successful
 */

int main()
{
	char* cmd;
	while (1)
	{
		input_prompt();

		cmd = get_line();

		if (!cmd)
		{
			write(STDOUT_FILENO, "\n", 1);
            	break;
		}

		excmd(cmd);
		free(cmd);
	}
	return 0;
}
