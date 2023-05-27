#include "main.h"

/**
 * prompt - output my shell prompt
 */

void prompt(void)
{
	PRINTER("$ ");
}
/**
 * print_error - output error base on cmnd
 * @input: given input
 * @counter: loop count
 * @argv: name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
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
