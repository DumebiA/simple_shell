#include "main.h"

/**
 * string_length - common implementation of the string length calculation.
 * @str: string
 *
 * Return: the difference between final value of s and the initial value of str
 */

size_t string_length(const char *str)
{
	const char *s = str;

	while (*s)
	{
		s++;
	}
	return (s - str);
}

/**
 * string_compare - implementation of string comparison of two strings
 * @str1: string one
 * @str2: string two
 * @length: number of characters to compare
 *
 * Return: the difference between final value of s and the initial value of str
 */

int string_compare(const char *str1, const char *str2, size_t length)
{
	if (length == 0)
	{
		return (0);
	}

	if (*str1 != *str2)
	{
		return (*str1 - *str2);
	}

	return (string_compare(++str1, ++str2, length - 1));
}

/**
 * getenv_custom - a custom implementation of the getenv function in C.
 * @name: name of env variable to be retrieved.
 *
 * Return: It loops, if not return NULL
 */

char *getenv_custom(const char *name)
{
	size_t name_len = string_length(name);

	char **env = environ;

	while (*env)
	{
		if (string_compare(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
		env++;
	}

	return (NULL);
}

/**
 * get_location - gets location of command
 * @cmd: command
 *
 * Return: the difference between final value of s and the initial value of str
 */

char *get_location(char *cmd)
{
	char *p = getenv_custom("PATH");

	if (p)
	{
		char *p_cp = strdup(p);
		struct stat bufr;
		int cmd_len = string_length(cmd);

		char *p_tok = strtok(p_cp, ":");

		while (p_tok != NULL)
		{
			int dirlen = string_length(p_tok);
			char *file_p = malloc(cmd_len + dirlen + 2);

			strcpy(file_p, p_tok);
			strcat(file_p, "/");
			strcat(file_p, cmd);
			strcat(file_p, "\0");

			if (stat(file_p, &bufr) == 0)
			{
				free(p_cp);
				return (file_p);
			}
			else
			{
				free(file_p);
				p_tok = strtok(NULL, ":");
			}
		}
		free(p_cp);

		if (stat(cmd, &bufr) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
