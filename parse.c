#include "main.h"

char **parse(char *cmd)
{
	char **tok;
	char *t;
	int n, buff = BUFSIZE;

	if (cmd == NULL)
		return (NULL);
	tok = malloc(sizeof(char *) * buff);
	if (!tok)
	{
		perror("hsh");
		return (NULL);
	}

	t = str_tok(cmd, "\n ");
	for (n = 0; t; n++)
	{
		tok[n] = t;
		t = str_tok(NULL, "\n ");
	}
	tok[n] = NULL;

	return (tok);
}
