#include "main.h"
/**
 * str_cpy - Source To Destination Char
 * @c:Destination
 * @n:Source
 * Return: Copie Of Char
 */
char *str_cpy(char *c, char *n)
{
int i;

i = 0;
	while (n[i])
	{
		c[i] = n[i];
		i++;
	}
c[i] = '\0';
return (c);
}

/**
 * str_cat - Two String
 * @c:First String
 * @i:Second String
 * Return:First String + Second String Char
 */
char *str_cat(char *c, char *i)
{
	char *n = c;

	while (*c != '\0')
	{
		c++;
	}

	while (*i != '\0')
	{
		*c = *i;
		c++;
		i++;
	}
	*c = '\0';
	return (n);
}

/**
 * str_chr - Locate Charactere In String
 * @s:String Search In
 * @c:Char To Search For
 * Return: Pointer To Char*
 */
char *str_chr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);
	return (s);
}

/**
 * strn_cmp - Compare Amount Strings
 * @s: String
 * @l: String
 * @o: Amount Of Characters
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int strn_cmp(const char *s, const char *l, size_t o)
{
	size_t i;

	if (s == NULL)
		return (-1);
	for (i = 0; i < o && l[i]; i++)
	{
		if (s[i] != l[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * str_dup - Duplicate A String
 * @s:String
 * Return: Null
 */
char *str_dup(char *s)
{
	size_t l, n;
	char *c;

	l = str_len(s);
	c = malloc(sizeof(char) * (l + 1));
	if (!c)
	{
		return (NULL);
	}

	for (n = 0; n <= l; n++)
	{
		c[n] = s[n];
	}

	return (c);
}
