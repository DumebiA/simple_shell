#include "main.h"

int main(int argc, char **argv)
{
	char prompt[] = "Myshell $ ";
	char *lineptr = NULL;
	char *lineptr_copy;
	char msg2[] = "exit\n";
	const char *delim = " \n";
	char *token;
	char **exec_args;
	int num_tokens = 0;
	int i;
	ssize_t nread;
	size_t n = 0;

	(void)argc;
	(void)argv;

	while (1)
	{

		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		nread = getline(&lineptr, &n, stdin);

	if (nread == -1)
	{
		write(STDOUT_FILENO, msg2, sizeof(msg2) - 1);
		free(lineptr);
		return -1;
	}

	lineptr_copy = malloc(sizeof(char) * nread);
	if (lineptr_copy == NULL)
	{
		perror("error");
		return -1;
	}
	strcpy(lineptr_copy, lineptr);

	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	exec_args = malloc(sizeof(char *) * num_tokens);
	if (exec_args == NULL)
	{
		perror("error");
		return -1;
	}

	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		exec_args[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(exec_args[i], token);

		token = strtok(NULL, delim);
	}
	exec_args[i] = NULL;

	execve(exec_args[0], exec_args, NULL);
	perror("error");

	for (i = 0; i < num_tokens; i++)
	{
		free(exec_args[i]);
	}
	free(exec_args);

	write(STDOUT_FILENO, lineptr, nread);
	}
	
	free(lineptr);
	return 0;
}
