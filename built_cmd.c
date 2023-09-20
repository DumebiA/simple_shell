#include "main.h"
/**
 * exit_cmd - Exit Statue Shell
 * @command: Parsed Command
 * @in: User Input
 * @argv:Program Name
 * @i:Excute Count
 * Return: Void
 */
void  exit_cmd(char **command, char *in, char **argv, int i)
{
	int s, n = 0;

	if (command[1] == NULL)
	{
		free(in);
		free(command);
		exit(EXIT_SUCCESS);
	}
	while (command[1][n])
	{
		if (_alpha(command[1][n++]) != 0)
		{
			pr_err(argv, i, command);
			break;
		}
		else
		{
			s = conv_int(command[1]);
			free(in);
			free(command);
			exit(s);
		}
	}
}


/**
 * cd_cmd - Change Dirctorie
 * @command: Parsed Command
 * @r: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int cd_cmd(char **command, __attribute__((unused))int r)
{
	int i = -1;
	char c[PATH_MAX];

	if (command[1] == NULL)
		i = chdir(getenv("HOME"));
	else if (str_cmp(command[1], "-") == 0)
	{
		i = chdir(getenv("OLDPWD"));
	}
	else
		i = chdir(command[1]);

	if (i == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (i != -1)
	{
		getcwd(c, sizeof(c));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", c, 1);
	}
	return (0);
}

/**
 * _env - Display Enviroment Variable
 * @command:Parsed Command
 * @r:Statue of Last command Excuted
 * Return:Always 0
 */
int _env(__attribute__((unused)) char **command, __attribute__((unused)) int r)
{
size_t s;
	int i;

	for (s = 0; environ[s] != NULL; s++)
	{
		i = str_len(environ[s]);
		write(1, environ[s], i);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * help_cmd - Displaying Help For Builtin
 * @command:Parsed Command
 * @r: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */
int help_cmd(char **command, __attribute__((unused))int r)
{
	int f, w, i = 1;
	char c;

	f = open(command[1], O_RDONLY);
	if (f < 0)
	{
		perror("Error");
		return (0);
	}
	while (i > 0)
	{
		i = read(f, &c, 1);
		w = write(STDOUT_FILENO, &c, i);
		if (w < 0)
		{
			return (-1);
		}
	}
	put_char('\n');
	return (0);
}
/**
 * echo_cmd - Excute Echo Cases
 * @i:Statue Of Last Command Excuted
 * @command: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int echo_cmd(char **command, int i)
{
	char *p;
	unsigned int  pid = getppid();

	if (strn_cmp(command[1], "$?", 2) == 0)
	{
		num_int(i);
		PRINTER("\n");
	}
	else if (strn_cmp(command[1], "$$", 2) == 0)
	{
		prnt_num(pid);
		PRINTER("\n");

	}
	else if (strn_cmp(command[1], "$PATH", 5) == 0)
	{
		p = get_env("PATH");
		PRINTER(p);
		PRINTER("\n");
		free(p);

	}
	else
		return (showecho(command));

	return (1);
}
