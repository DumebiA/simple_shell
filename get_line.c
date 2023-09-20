#include "main.h"

/**
* get_line - Read The Input By User From Stdin
* Return: Input
*/
char *get_line()
{
int i, bs = BUFSIZE, rd;
char c = 0;
char *b = malloc(bs);

	if (b == NULL)
	{
		free(b);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(b);
			exit(EXIT_SUCCESS);
		}
		b[i] = c;
		if (b[0] == '\n')
		{
			free(b);
			return ("\0");
		}
		if (i >= bs)
		{
			b = re_alloc(b, bs, bs + 1);
			if (b == NULL)
			{
				return (NULL);
			}
		}
	}
	b[i] = '\0';
	hash_tag(b);
	return (b);
}

/**
 * hash_tag - remove everything after #
 * @buf: input;
 * Return:void
 */
void hash_tag(char *buf)
{
	int i;

		for (i = 0; buf[i] != '\0'; i++)
		{
			if (buf[i] == '#')
			{
			buf[i] = '\0';
			break;
			}
	}
}
