#include "main.h"

/**
 * excmd - function executes stored prompt
 * @argv: prompt command storage to be executed
 *
 * Return: the difference between final value of s and the initial value of str
 */

void excmd(char **argv)
{
	char *cmd = NULL;
	char *a_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		a_cmd = get_location(cmd);

		if (execve(a_cmd, argv, NULL) == -1)
		{
			perror("error message");
		}
	}
}
