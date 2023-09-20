#include "main.h"
/**
 * str_cmp - Compare Strings
 * @s:String
 * @c:String
 * Return: x for comparism
 */
int str_cmp(char *s, char *c)
{
	int x = 0, i, l1, l2;

	l1 = str_len(s);
	l2 = str_len(c);

	if (s == NULL || c == NULL)
		return (1);
	if (l1 != l2)
		return (1);
	for (i = 0; s[i]; i++)
	{
		if (s[i] != c[i])
		{
			x = s[i] - c[i];
			break;
		}
		else
			continue;
	}
	return (x);
}

/**
 * _alpha - Check if Alphabtic
 *@i: Character
 * Return: 1 If True 0 If Not
 */
int _alpha(int i)
{
	if (((i >= 97) && (i <= 122)) || ((i >= 65) && (i <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _intochar - Convert Integer To Char
 * @n: Integar
 * Return: Char Pointer
 */
char *_intochar(unsigned int n)
{
	int l = 0, x = 0;
	char *c;

	l = int_len(n);
	c = malloc(l + 1);
	if (!c)
		return (NULL);
	*c = '\0';
	while (n / 10)
	{
		c[x] = (n % 10) + '0';
		n /= 10;
		x++;
	}
	c[x] = (n % 10) + '0';
	reverse_array(c, l);
	c[x + 1] = '\0';
	return (c);
}

/**
 * reverse_array - Reverse Array
 * @a:Array To Reverse
 * @l:Length Of Array
 * Return: Void(Reverse Array)
 */
void reverse_array(char *a, int l)
{
	int i;
	char t;

	for (i = 0; i < (l / 2); i++)
	{
		t = a[i];
		a[i] = a[(l - 1) - i];
		a[(l - 1) - i] = t;
	}
}
/**
 * int_len - Determine Length
 * @n: Number
 * Return: Length
 */
int int_len(int n)
{
	int l = 0;

	while (n != 0)
	{
		l++;
		n /= 10;
	}
	return (l);
}
