#include "main.h"

/**
* _getline - Read STDIN
* Return: Input
*/
char *_getline()
{
int i, buffsize = BUFSIZE, rd;
char c = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	hashtag_handle(buff);
	return (buff);
}

/**
 * hashtag_handle - handle #'
 * @buff: given input
 * Return:void
 */
void hashtag_handle(char *buff)
{
	int e;

		for (e = 0; buff[e] != '\0'; e++)
		{
			if (buff[e] == '#')
			{
			buff[e] = '\0';
			break;
			}
	}
}
