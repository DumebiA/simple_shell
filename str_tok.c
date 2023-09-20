#include "main.h"
/**
 * _delim - Checks there is another char* match
 * @c: Character
 * @chk: Checker
 * Return: 1 Succes, 0 Failed
 */
unsigned int _delim(char c, const char *chk)
{
	unsigned int n;

	for (n = 0; chk[n] != '\0'; n++)
	{
		if (c == chk[n])
			return (1);
	}
	return (0);
}

/**
 * str_tok - My own strtrok
 * @c: String Character
 * @del: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *str_tok(char *c, const char *del)
{
	static char *s;
	static char *n;
	unsigned int i;

	if (c != NULL)
		n = c;
	s = n;
	if (s == NULL)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (_delim(s[i], del) == 0)
			break;
	}
	if (n[i] == '\0' || n[i] == '#')
	{
		n = NULL;
		return (NULL);
	}
	s = n + i;
	n = s;
	for (i = 0; n[i] != '\0'; i++)
	{
		if (_delim(n[i], del) == 1)
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
	return (s);
}
