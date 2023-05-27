#include "main.h"

/**
 * put_char - writes char to stdout
 * @c: char to print
 * Return: 1 on  success
 * On error, -1 is returned
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * strn_cpy - copy strg
 * @dest: character
 *  @src: character
 * @n:int
 * Return: char
 */

char *strn_cpy(char *dest, char *src, int n)
{
int i;

i = 0;
	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * str_len - lenght of string
 * @s:char
 * Return:int
 */

int str_len(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * _atoi - change to int
 * @s: strg
 * Return: int
 */
int _atoi(char *s)
{
int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * _puts - output string
 * @str: pointer charaxter
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		put_char(str[i]);
	}
put_char('\n');
return;
}
