#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void display_prompt()
{
	char prompt[] = "$ ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

char* read_command()
{
	char* command = NULL;
	size_t inputsize = 0;
	size_t length = 0;
	ssize_t nread;

	nread = getline(&command, &inputsize, stdin);

	if (nread == -1)
	{
		free(command);
		command = NULL;
	}
	else
	{

	while (command[length] != '\n' && command[length] != '\0')
	{
		length++;
	}

	if (command[length - 1] == '\n')
	{
		command[length - 1] = '\0';
	}
}

	return (command);
}

void execute_command(char* command)
{
	pid_t pid = fork();

	if (pid < 0)
	{

		char error[] = "Failed to create child process\n";
		write(STDERR_FILENO, error, sizeof(error) - 1);
		return;
	}

	if (pid == 0)
	{

		char* args[2];
		args[0] = command;
		args[1] = NULL;
		
		if (execve(command, args, NULL) == -1)
		{
			char error[] = "Failed to execute command\n";
			write(STDERR_FILENO, error, sizeof(error) - 1);
			exit(1);
		}
	}
	else
	{

		wait(NULL);
	}
}

int main()
{
	char* cmd;

	while (1)
	{
		display_prompt();

		cmd = read_command();

		if (!cmd)
	{

		write(STDOUT_FILENO, "\n", 1);
			break;
	}

	execute_command(cmd);
	free(cmd);
	}

	return (0);
}
