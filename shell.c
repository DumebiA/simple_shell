#include "main.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

void parseInput(char *lineptr, char ***argv)
{
	const char *delim = " \n";
	int num_tokens = 0;
	char *line_copy = NULL;
	char *toks;
	int n;

	toks = strtok(lineptr, delim);

	while (toks != NULL)
	{
		num_tokens++;
		toks = strtok(NULL, delim);
	}
	num_tokens++;

	*argv = malloc(sizeof(char *) * num_tokens);

	line_copy = malloc(sizeof(char) * strlen(lineptr));
	strcpy(line_copy, lineptr);

	toks = strtok(line_copy, delim);

	for (n = 0; toks != NULL; n++)
	{
		(*argv)[n] = malloc(sizeof(char) * strlen(toks));
		strcpy((*argv)[n], toks);

		toks = strtok(NULL, delim);
	}
	(*argv)[n] = NULL;

	free(line_copy);
}

void excmd(char **argv)
{
	char *cmd = NULL, *a_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		a_cmd = get_location(cmd);

		if (execve(a_cmd, argv, NULL) == -1)
		{
			perror("err");
		}
	}
}

int main(int argc, char **argv)
{
	char *prompt = "Myshell $ ";
	char *lineptr = NULL;
	char **args = NULL;
	size_t x = 0;
	ssize_t nread;
	int pipe = 0;

	(void)argc;
	(void)argv;

	while (1 && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = 1;
		write(STDOUT_FILENO, prompt, strlen(prompt));
		nread = getline(&lineptr, &x, stdin);

		if (nread == -1)
		{
			write(STDOUT_FILENO, "exit\n", strlen("exit\n"));
			return (-1);
		}

		parseInput(lineptr, &args);

		excmd(args);
	}

	free(args);
	free(lineptr);

	return (0);
}
