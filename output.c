#include "main.h"
/**
 * pr_err - Print Custome Error
 * @argv:Program
 * @i:Count
 * @command:Command
 * Return: Void
 */
void pr_err(char **argv, int i, char **command)
{
	char *c = _intochar(i);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(c);
	PRINTER(": ");
	PRINTER(command[0]);
	PRINTER(": Illegal number: ");
	PRINTER(command[1]);
	PRINTER("\n");
	free(c);
}
