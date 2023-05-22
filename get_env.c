#include "main.h"

void write_string(int fd, const char *str)
{
	size_t len = write(fd, str, string_length(str));
	(void)len;
}

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
