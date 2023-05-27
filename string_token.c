#include "main.h"

/**
 * check_delim - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */

unsigned int delim(char i, const char *str)
{
	unsigned int n;

	for (n = 0; str[n] != '\0'; n++)
	{
		if (i == str[n])
			return (1);
	}
	return (0);
}


char *str_tok(char *s, const char *d)
{
	static char *t;
	static char *n;
	unsigned int i;

	if (s != NULL)
		n = s;
	t = n;
	if (t == NULL)
		return (NULL);
	for (i = 0; t[i] != '\0'; i++)
	{
		if (delim(t[i], d) == 0)
			break;
	}
	if (n[i] == '\0' || n[i] == '#')
	{
		n = NULL;
		return (NULL);
	}
	t = n + i;
	n = t;
	for (i = 0; n[i] != '\0'; i++)
	{
		if (delim(n[i], d) == 1)
			break;
	}
	if (n[i] == '\0')
		n = NULL;
	else
	{
		n[i] = '\0';
		n = n + i + 1;
		if (*n == '\0')
			n = NULL;
	}
	return (t);
}
