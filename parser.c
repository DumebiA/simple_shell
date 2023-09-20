#include "main.h"

/**
 * parser - Parsed Line
 * @c:User Input
 * Return: Parsed
 */
char **parser(char *c)
{
	char **tks;
	char *tk;
	int i, buf = BUFSIZE;

	if (c == NULL)
		return (NULL);
	tks = malloc(sizeof(char *) * buf);
	if (!tks)
	{
		perror("error");
		return (NULL);
	}

	tk = str_tok(c, "\n ");
	for (i = 0; tk; i++)
	{
		tks[i] = tk;
		tk = str_tok(NULL, "\n ");
	}
	tks[i] = NULL;

	return (tks);
}
