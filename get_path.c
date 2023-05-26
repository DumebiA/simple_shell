#include "main.h"

/**
 * get_path - getline function
 * Return: the path
 */
char *get_path(void)
{

	return (getenv)("PATH");

}

/**
 * tokenise_path - divide the path
 * @path: to be found
 * Return: NULL
 */

char **tokenise_path(const char *path)
{
	const char *delimiter = ":";

	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
	perror("Error duplicating path");
	return (NULL);
	}

	count = 1;
	char *token = strtok(path_copy, delimiter);

	while (token != NULL)
	{
	count++;
	token = strtok(NULL, delimiter);
	}

	**directories = (char **)malloc(count * sizeof(char *));

	if (directories == NULL)
	{
	perror("Error allocating memory for directories");
	free(path_copy);
	return (NULL);
	}

	count = 0;
	token = strtok(path_copy, delimiter);
	while (token != NULL)
	{
	directories[count++] = strdup(token);
	token = strtok(NULL, delimiter);
	}
	directories[count] = NULL;

	free(path_copy);
	return (directories);
}
