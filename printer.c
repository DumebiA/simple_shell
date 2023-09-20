#include "main.h"
/**
 * prnt_num -Print Unsigned Int Putchar
 * @i: Unisigned Integer
 * Return: Void
 */
void prnt_num(unsigned int i)
{
	unsigned int o;

	o = i;

	if ((o / 10) > 0)
		prnt_num(o / 10);

	put_char(o % 10 + '0');
}

/**
 * num_int -Print Number Putchar
 * @i: Integer
 * Return: void
 */
void num_int(int i)
{
	unsigned int o = i;

	if (i < 0)
	{
		put_char('-');
		o = -o;
	}
	if ((o / 10) > 0)
		prnt_num(o / 10);

	put_char(o % 10 + '0');
}
