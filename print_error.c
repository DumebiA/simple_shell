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
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
