#include "main.h"
/**
 * exit_bul - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @c:Excute Count
 * Return: Void (Exit Statue)
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
		if (_isalpha(command[1][n++]) != 0)
		{
			_prerror(argv, i, command);
			break;
		}
		else
		{
			s = _atoi(command[1]);
			free(in);
			free(command);
			exit(s);
		}
	}
}


/**
 * change_dir - Change Dirctorie
 * @cmd: Parsed Command
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int cd_cmd(char **command, __attribute__((unused))int r)
{
	int i = -1;
	char c[PATH_MAX];

	if (command[1] == NULL)
		i = chdir(getenv("HOME"));
	else if (_strcmp(command[1], "-") == 0)
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
 * dis_env - Display Enviroment Variable
 * @cmd:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */
int env_cmd(__attribute__((unused)) char **command, __attribute__((unused)) int r)
{
size_t s;
	int i;

	for (s = 0; environ[s] != NULL; s++)
	{
		i = _strlen(environ[s]);
		write(1, environ[s], i);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * display_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
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
	_putchar('\n');
	return (0);
}
/**
 * echo_bul - Excute Echo Cases
 * @st:Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1);
}
