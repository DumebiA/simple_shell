<<<<<<< HEAD
#include "main.h"
/**
 * print_number -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void print_number(unsigned int n)
=======
#include "shell.h"

void print_n(unsigned int n)
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
{
	unsigned int o = n;

	if ((o / 10) > 0)
		print_number(o/ 10);

	put_char(o % 10 + '0');
}

void print_num_in(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		put_char('-');
		i = -i;
	}
	if ((i / 10) > 0)
		print_number(i / 10);

	put_char(i % 10 + '0');
}
