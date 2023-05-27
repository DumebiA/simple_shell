#include "main.h"
/**
 *  _prerror - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void _prerror(char **argv, int n, char **cmd)
{
	char *r = _atoi(n);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(r);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Error number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");

	free(r);
}
