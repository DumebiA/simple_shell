#include "main.h"

/**
 * find_executable - find the excutable path
 * @command: command to be executed
 * Return: 0 on success
 */
char *find_executable(const char *command)
{
	char *path = get_path();
	
	if (path == NULL)
	return (NULL);

	char **directories = tokenise_path(path);
	free(path);

	if (directories == NULL)
	return (NULL);

	char *executable_path = NULL;
	 int i = 0;
	while (directories[i] != NULL)
	{
	char *file_path = construct_file_path(directories[i], command);
	
	if (file_path != NULL && is_executable_file(file_path))
	{
		executable_path = file_path;
		break;
	}
	free(file_path);
	i++;
	}

	free(directories);
	return (executable_path);
}
/**
 * get_path - getline function
 * Return: the path
 */
char *get_path(void)
{
	 return (getenv "PATH");
}

/**
 * tokenise_path - divides the path
 * Return: NULL
 */
char **tokenise_path(const char *path)
{
	const char *delimiter = ":";

	char *path_copy = strdup(path);
	if (path_copy == NULL)
	{
	perror;
	return (NULL);
	}
	int count = 1;
	char *token = strtok(path_copy, delimiter);
	while (token != NULL)
	{
	count++;
	token = strtok(NULL, delimiter);
	}

	char **directories = (char **)malloc(count * sizeof(char *));

	if (directories == NULL)
	{
	perror;
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

/**
 * construc_file_path - make the file path
 * @path: of file
 * Return: 0 on success
 */
char *construct_file_path(const char *directory, const char *command)
{
	size_t directory_length = strlen(directory);
	size_t command_length = strlen(command);
	size_t file_path_length = directory_length + command_length + 2;

	char *file_path = (char *)malloc(file_path_length);
	if (file_path == NULL)
	{
	perror("Error allocating memory for file path");
	return NULL;
	}

	snprintf(file_path, file_path_length, "%s/%s", directory, command);
	return (file_path);
}

/**
 * is_executable_file - identify executable file
 * @file_path: chmod file path
 * Return: file
 */
int is_executable_file(const char *file_path)
{
	FILE *file = fopen(file_path, "r");
	if (file == NULL)
	return 0;
	int is_executable = access(file_path, X_OK) == 0;

	fclose(file);
	return (is_executable);
}

/**
 * main - test function
 * Return: 0 on success
 */

int main(void)
{
	const char *command = "test";

	char *result = find_executable(command);

	if (result != NULL)
	{
	char stdout_output[100];
	int length = snprintf(stdout_output, sizeof(stdout_output), 
	"(stdout)[($)(%s) ](Length: %zu)\n", result, strlen(result));
	write(STDOUT_FILENO, stdout_output, length);
	free(result);
	}
	else
	{
	char stderr_output[] = "(stderr)[./hsh: command not found](Length: 25)\n";
	write(STDERR_FILENO, stderr_output, sizeof(stderr_output) - 1);
	}
	return (0);
}
