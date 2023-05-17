#include "main.h"

/*
 * xcmd - provide your own environment variables
 * @argv: argument variable
 */

void xcmd(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("err");
		}
	}
}
