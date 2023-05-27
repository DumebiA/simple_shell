#include "main.h"
/**
 * str_cpy - Copie Source To dest.
 * @dest: destination
 * @src: source
 * Return: copy of Char *
 */
char *str_cpy(char *dest, char *src)
{
int i;

i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
dest[i] = '\0';
return (dest);
}
/**
 * str_cat - Concatenate string
 * @dest: String 1
 * @src: String 2
 * Return: strg 1 and Strg 2
 */
char *str_cat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * str_chr - identify char in string
 * @s: string search
 * @c: char for search
 * Return: Pointer
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
 * strn_cmp - identify n char in strg
 * @s1: strg
 * @s2: strg
 * @n: numb od char
 * Return: 1 If The Strings Don't Match Otherwie 0
 */
int strn_cmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * str_dup - Duplicate A Strg
 * @str: Strg
 * Return: Failed Null
 */
char *str_dup(char *str)
{
	size_t length 0;
	char *str0;

	len = str_len(str);
	str0 = malloc(sizeof(char) * (length + 1));
	if (!str0)
	{
		return (NULL);
	}

	for (n = 0; n <= len; n++)
	{
		str0[n] = str[n];
	}

	return (str0);
}
