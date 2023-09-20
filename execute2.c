#include "main.h"

/**
 * read_func - Read Command From File
 * @fn:Filename
 * @argv:Program Name
 * Return: -1 or  0
 */

void read_func(char *fn, char **argv)
{
	FILE *f;
	char *c = NULL;
	size_t ln = 0;
	int counter = 0;

	f = fopen(fn, "r");
	if (f == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&c, &ln, f)) != -1)
	{
		counter++;
		treat_func(c, counter, f, argv);

	}
	if (c)
		free(c);
	fclose(f);
	exit(0);
}

/**
 * treat_func - PARSE Check Command Fork Wait Excute in Line of File
 * @c: Line From A File
 * @i:Error Counter
 * @f:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */
void treat_func(char *c, int i, FILE *f, char **argv)
{
	char **command;
	int s = 0;

	command = parser(c);

		if (strn_cmp(command[0], "exit", 4) == 0)
		{
			exit_file(command, c, f);
		}
		else if (_builtin(command) == 0)
		{
			s = built_cmd(command, s);
			free(command);
		}
		else
		{
			s = check_cmd(command, c, i, argv);
			free(command);
		}
}
/**
 * exit_file - Exit Shell Case Of File
 * @c: Line From A File
 * @command: Parsed Command
 * @d:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exit_file(char **command, char *c, FILE *d)
{
	int s, i = 0;

	if (command[1] == NULL)
	{
		free(c);
		free(command);
		fclose(d);
		exit(errno);
	}
	while (command[1][i])
	{
		if (_alpha(command[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	s = conv_int(command[1]);
	free(c);
	free(command);
	fclose(d);
	exit(s);
}
