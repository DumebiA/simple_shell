#include "main.h"

/**
 * find_executable - find the executable path
 * @command: command to be executed
 * Return: 0 on success
 */

char *find_executable(const char *command)
{
	char *path = get_path();

	if (path == NULL)
	return (NULL);

	**directories = tokenise_path(path);

	free(path);

	if (directories == NULL)
	return (NULL);

	*executable_path = NULL;
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
