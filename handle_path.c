#include "main.h"

/**
 * path_cmd -  go through $PATH for exe cmnd
 * @cmd: Input
 * Return: 1  Failure  0  Success.
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = str_tok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = str_dup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = str_tok(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * build - Build Command
 * @token: exe. cmd.
 * @value: Dir carry cmnd
 * Return: Path or null
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = str_len(value) + str_len(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = str_cat(cmd, value);
	cmd = str_cat(cmd, "/");
	cmd = str_cat(cmd, token);

	return (cmd);
}
/**
 * _getenv - get environ var.
 * @name: variable name
 * Return: value else null
 */
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = str_len(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (strn_cmp(name, environ[i], nl) == 0)
		{
			vl = str_len(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
