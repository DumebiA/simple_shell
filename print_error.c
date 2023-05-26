#include "main.h"

void prompt(void)
{
	PRINTER("$ ");
}

void err_print(char *in, int count, char **argv)
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
