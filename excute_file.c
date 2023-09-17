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
		treat_file(c, counter, f, argv);

	}
	if (c)
		free(c);
	fclose(f);
	exit(0);
}
/**
 * treat_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */
void treat_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_bul_for_file(cmd, line, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = built_cmd(cmd, st);
			free(cmd);
		}
		else
		{
			st = check_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}
/**
 * exit_bul_for_file - Exit Shell Case Of File
 * @line: Line From A File
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = conv_int(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);



}
