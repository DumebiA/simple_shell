#include "main.h"

/**
 * construct_file_path - make the file path
 * @directory: to be check
 * @command: path to check
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
		return (NULL);
	}

	snprintf(file_path, file_path_length, "%s/%s", directory, command);
	return (file_path);
}

/**
 * is_executable - identify executable file
 * @file_path: chmod path
 * Return: path
 */
int is_executable(const char *file_path)
{
	FILE *file = fopen(file_path, "r");

	if (file == NULL)
	return (0);

	is_executable = access(file_path, X_OK) == 0;

	fclose(file);
	return (is_executable);
}
