#include "main.h"
<<<<<<< HEAD
/**
 *  _prerror - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void _prerror(char **argv, int c, char **cmd)
=======

void p_error(char **argv, int n, char **cmd)
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
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
