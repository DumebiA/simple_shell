#include "main.h"

void p_error(char **argv, int n, char **cmd)
{
	char *r = ao_ti(n);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Error number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");

	free(r);
}
