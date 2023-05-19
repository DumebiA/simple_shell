#include "main.h"

char *get_location(char *cmd)
{
	char *p, *p_cp, *p_tok, *file_p;
	int cmd_len, dirlen;
	struct stat bufr;

	p = getenv("PATH");

	if (p)
	{
		p_cp = strdup(p);
		cmd_len = strlen(cmd);
		p_tok = strtok(p_cp, ":");
		while (p_tok != NULL)
		{
			dirlen = strlen(p_tok);
			file_p = malloc(cmd_len + dirlen + 2);
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
