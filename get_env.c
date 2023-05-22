#include "main.h"

/**
 * write_string - returns true if shell is interactive mode
 * @fd: file descriptor
 * @str: string
 *
 */

void write_string(int fd, const char *str)
{
	size_t len = write(fd, str, string_length(str));
	(void)len;
}

/**
 * main_cmd - main command
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int main_cmd(void)
{
	char *command;
	char *location;

	command = "test";
	location = get_location(command);
	if (location)
	{
		write_string(STDOUT_FILENO, "Command location: ");
		write_string(STDOUT_FILENO, location);
		write_string(STDOUT_FILENO, "\n");
		free(location);
	}
	else
	{
		write_string(STDOUT_FILENO, "Command not found.\n");
	}
	return (0);
}
