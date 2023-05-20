#include "main.h"

/**
 * get_location - get the path location
 * @PATH: argument
 * Return: Always 0
 */

char *get_location(char *cmd)
{
	char *p = getenv("PATH");

	if (p)
	{
		char *p_cp = strdup(p);
		int cmd_len = strlen(cmd);
		struct stat bufr;
		char *p_tok = strtok(p_cp, ":");

		while (p_tok != NULL)
		{
			int dirlen = strlen(p_tok);
			char *file_p = malloc(cmd_len + dirlen + 2);

			strcpy(file_p, p_tok);
			strcat(file_p, "/");
			strcat(file_p, cmd);
			strcat(file_p, "\0");

			if (stat(file_p, &bufr) == 0)
			{
				free(p_cp);
				return (file_p);
			}
			else
			{
				free(file_p);
				p_tok = strtok(NULL, ":");
			}
		}
		free(p_cp);
		if (stat(cmd, &bufr) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
