#include "main.h"

int main(int argc, char **argv)
{
	char prompt[] = "Myshell $ ";
	char *lineptr = NULL;
	char msg2[] = "exit\n";
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

		write(STDOUT_FILENO, lineptr, nread);
	}

	free(lineptr);
	return 0;
}
