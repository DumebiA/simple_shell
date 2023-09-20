#include "main.h"
/**
 * his_tory - Fill File By User Input
 * @in: User Input
 * Return: -1 Fail 0 Succes
 */
int his_tory(char *in)
{
	char *fn = ".simple_shell_history";
	ssize_t f, w;
	int length = 0;

	if (!fn)
		return (-1);
	f = open(fn, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (f < 0)
		return (-1);
	if (in)
	{
		while (in[length])
			length++;
		w = write(f, in, length);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * frenv - Free Env
 * @n:  Environment variables.
 * Return: Void
 */
void frenv(char **n)
{
	int i;

	for (i = 0; n[i]; i++)
	{
		free(n[i]);
	}
}
