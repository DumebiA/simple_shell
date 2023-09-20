#include "main.h"

/**
 * display_his - Display History Of User Input
 * @c:Parsed Command
 * @s:Statue Of Last Excute
 * Return: 0 Succes -1 Fail
 */
int display_his(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *fn = ".simple_shell_history";
	FILE *f;
	char *line = NULL;
	size_t n = 0;
	int i = 0;
	char *r;

	f = fopen(fn, "r");
	if (f == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &n, f)) != -1)
	{
		i++;
		r = _intochar(i);
		PRINTER(r);
		free(r);
		PRINTER(" ");
		PRINTER(line);

	}
	if (line)
		free(line);
	fclose(f);
	return (0);
}
/**
 * showecho - Excute Normal Echo
 * @command: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int showecho(char **command)
{
	pid_t p;
	int i;

	p = fork();
	if (p == 0)
	{
		if (execve("/bin/echo", command, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (p < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(p, &i, WUNTRACED);
		} while (!WIFEXITED(i) && !WIFSIGNALED(i));
	}
	return (1);
}
