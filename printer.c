#include "main.h"
/**
 * prnt_num -Print Unsigned Int Putchar
 * @i: Unisigned Integer
 * Return: Void
 */
void prnt_num(unsigned int i)
{
	unsigned int n;
	n = i;

	if ((n / 10) > 0)
		prnt_num(n / 10);

	put_char(n % 10 + '0');
}

/**
 * num_int -Print Number Putchar
 * @i: Integer
 * Return: void
 */
void num_int(int i)
{
	unsigned int n = i;

	if (i < 0)
	{
		put_char('-');
		n = -n;
	}
	if ((n / 10) > 0)
		prnt_num(n / 10);

	put_char(n % 10 + '0');
}
