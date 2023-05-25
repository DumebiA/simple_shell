#include "main.h"

/**
 * string_compare - function executes stored prompt
 * @cmd1: command 1
 * @cmd2: command 2
 *
 * Return: return comparism between commands
 */

int string_compare(const char* cmd1, const char* cmd2)
{
	while (*cmd1 != '\0' && *cmd2 != '\0')
	{
		if (*cmd1 != *cmd2)
		{
			return 0;
		}
		cmd1++;
		cmd2++;
	}
	return (*cmd1 == '\0' && *cmd2 == '\0');
}

/**
 * input_prompt - displays prompt to be inputed
 */

void input_prompt()
{
	char prompt[] = "($) ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * parse - parsing and tokenization
 * @command: input command to parse
 * @num_args: pointer to store the number of arguments
 *
 * Return: array of arguments
 */

char **parse(char *command, int *num_args)
{
	char **args = (char **)malloc((MAX_ARGS + 1) * sizeof(char *));
	char *tok;
	int index = 0;

	tok = strtok(command, " \t\n");
	while (tok != NULL)
	{
		args[index] = tok;
		index++;
		tok = strtok(NULL, " \t\n");
	}

	args[index] = NULL;
	*num_args = index;

	return args;
}

/**
 * main - prints main function
 *
 * Return: 0 if successful
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	ssize_t nreads;
	int num_args;
	char **args;

	while (1)
	{
		input_prompt();

		nreads = read(STDIN_FILENO, command, sizeof(command));

		if (nreads <= 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		command[nreads - 1] = '\0';

		if (string_compare(command, "exit"))
		{
			break;
		}

		args = parse(command, &num_args);

		if (num_args > 0)
		{
			excmd(args);
		}
		free(args);
	}
	return 0;
}
