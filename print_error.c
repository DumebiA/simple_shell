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
void print_error(char *in, int count, char **argv)
{
	char *e;

	PRINTER(argv[0]);
	PRINTER(": ");
	e = _atoi(count);
	PRINTER(e);
	free(e);
	PRINTER(": ");
	PRINTER(in);
	PRINTER(": not found\n");
}
