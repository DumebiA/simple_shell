#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "Myshell $ ";
	char *lineptr = NULL;
	char *line_copy = NULL;
	size_t x = 0;
	ssize_t nread;
	const char *delim = " \n";
	int num_tokens = 0;
	char *toks;
	int pipe = 0;
	int n;
	int status;
	pid_t mypid;

	(void)argc;

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

		line_copy = malloc(sizeof(char) * nread);

		if (line_copy == NULL)
		{
			perror("memory allocation err");
			return (-1);
		}

		strcpy(line_copy, lineptr);

		toks = strtok(lineptr, delim);

		while (toks != NULL)
		{
			num_tokens++;
			toks = strtok(NULL, delim);
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);

		toks = strtok(line_copy, delim);

		for (n = 0; toks != NULL; n++)
		{
			argv[n] = malloc(sizeof(char) * strlen(toks));
			strcpy(argv[n], toks);

			toks = strtok(NULL, delim);
		}
		argv[n] = NULL;

		mypid = fork();

		if (mypid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (mypid == 0)
		{
			excmd(argv);
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(mypid, &status, 0);
		}

		for (n = 0; n < num_tokens - 1; n++)
		{
			free(argv[n]);
		}
	}
	free(argv);
	free(line_copy);
	free(lineptr);

	return (0);
}
