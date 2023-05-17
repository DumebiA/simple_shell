#include "main.h"

int main(int arvc, char **argv)
{
	char *prompt = "Myshell $ ", *lineptr = NULL, *line_copy = NULL, *toks;
	size_t x = 0;
	ssize_t nread;
	const char *delim = " \n";
	int num_tokens = 0, n;

	(void)arvc;

	while (1)
	{
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
		xcmd(argv);
	}
	free(line_copy);
	free(lineptr);
	return (0);
}
