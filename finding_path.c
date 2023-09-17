#include "main.h"

/**
 * path_cmd -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int path_func(char **command)
{
	char *c, *v, *_path;
	struct stat buf;

	c = get_env("PATH");
	v = _strtok(c, ":");
	while (v != NULL)
	{
		_path = bld_cmd(*command, v);
		if (stat(_path, &buf) == 0)
		{
			*command = _strdup(_path);
			free(_path);
			free(c);
			return (0);
		}
		free(_path);
		v = _strtok(NULL, ":");
	}
	free(c);

	return (1);
}
/**
 * bld_cmd - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
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

	command = _strcat(command, val);
	command = _strcat(command, "/");
	command = _strcat(command, c);

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
		if (_strncmp(o, environ[i], n) == 0)
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
