#include "main.h"

/**
 * prompt_func - Display Shell Prompt
 */
void prompt_func(void)
{
	PRINTER("$ ");
}
/**
 * _error - Display Error
 * @in:Input
 * @i:Count Loop
 * @argv:Program
 * Return: Void
 */
void _error(char *in, int i, char **argv)
{
	char *c;

	PRINTER(argv[0]);
	PRINTER(": ");
	c = _intochar(i);
	PRINTER(c);
	free(c);
	PRINTER(": ");
	PRINTER(in);
	PRINTER(": missing\n");
}
