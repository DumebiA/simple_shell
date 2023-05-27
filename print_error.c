#include "main.h"

<<<<<<< HEAD
/**
 * prompt - output my shell prompt
 */
=======
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
void prompt(void)
{
	PRINTER("$ ");
}
<<<<<<< HEAD
/**
 * print_error - output error base on cmnd
 * @input: given input
 * @counter: loop count
 * @argv: name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
=======

void err_print(char *in, int count, char **argv)
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
{
	char *e;

	PRINTER(argv[0]);
	PRINTER(": ");
	e = ao_ti(count);
	PRINTER(er);
	free(e);
	PRINTER(": ");
	PRINTER(in);
	PRINTER(": not found\n");
}
