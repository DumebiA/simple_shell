#include "main.h"

/**
 * path_func -  Search In $PATH For Excutable Command
 * @command: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int path_func(char **command)
{
	char *c, *v, *_path;
	struct stat buf;

	c = get_env("PATH");
	v = str_tok(c, ":");
	while (v != NULL)
	{
		_path = bld_cmd(*command, v);
		if (stat(_path, &buf) == 0)
		{
			*command = str_dup(_path);
			free(_path);
			free(c);
			return (0);
		}
		free(_path);
		v = str_tok(NULL, ":");
	}
	free(c);

	return (1);
}
/**
 * bld_cmd - Build Command
 * @c: Excutable Command
 * @val: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *bld_cmd(char *c, char *val)
{
	char *command;
	size_t len;

	len = str_len(val) + str_len(c) + 2;
	command = malloc(sizeof(char) * len);
	if (command == NULL)
	{
		return (NULL);
	}

	memset(command, 0, len);

	command = str_cat(command, val);
	command = str_cat(command, "/");
	command = str_cat(command, c);

	return (command);
}
/**
 * get_env - Gets The Value Of Enviroment Variable By Name
 * @o: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */
char *get_env(char *o)
{
	size_t n, v;
	char *c;
	int i, t, x;

	n = str_len(o);
	for (i = 0 ; environ[i]; i++)
	{
		if (strn_cmp(o, environ[i], n) == 0)
		{
			v = str_len(environ[i]) - n;
			c = malloc(sizeof(char) * v);
			if (!c)
			{
				free(c);
			perror("unable to alloc");
				return (NULL);
			}

			x = 0;
			for (t = n + 1; environ[i][t]; t++, x++)
			{
				c[x] = environ[i][t];
			}
			c[x] = '\0';

			return (c);
		}
	}

	return (NULL);
}
