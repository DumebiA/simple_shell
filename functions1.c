#include "main.h"

/**
 * put_char - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1. On error, -1 is returned
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * strn_cpy - copy a string
 * @c:char
 *  @r:char
 * @o:int
 * Return:char
 */
char *strn_cpy(char *c, char *r, int o)
{
int i;

i = 0;
	while (i < o && *(r + i))
	{
	*(c + i) = *(r + i);
	i++;
	}
	while (i < o)
	{
	*(c + i) = '\0';
	i++;
	}
	return (c);
}

/**
 * str_len - string length
 * @c:character
 * Return: integar i
 */

int str_len(char *c)
{
	int i;

		for (i = 0; c[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * conv_int - convert to integar
 * @c:string caharcter
 * Return:integar
 */
int conv_int(char *c)
{
int i, j, n, o;

	i = n = 0;
	o = 1;
	while ((c[i] < '0' || c[i] > '9') && (c[i] != '\0'))
	{
		if (c[i] == '-')
			o *= -1;
		i++;
	}
	j = i;
	while ((c[j] >= '0') && (c[j] <= '9'))
	{
		n = (n * 10) + o * ((c[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * put_str - get a string
 * @c:pointer character
 * return:void
 */
void put_str(char *c)
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
	{
		put_char(c[i]);
	}
put_char('\n');
return;
}
