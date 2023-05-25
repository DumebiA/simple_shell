/**
 * excmd - function executes stored prompt
 * @command: prompt command storage to be executed
 *
 * Return: the difference between final value of s and the initial value of str
 */


void excmd(char** args)
{
	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		char error[] = "child process failed\n";
		write(STDERR_FILENO, error, sizeof(error) - 1);
		return;
	}

	if (pid == 0)
	{
		char* path = getenv("PATH");
		char* command_path = NULL;

		
		char* directory = strtok(path, ":");
		while (directory != NULL)
		{
			char* temp_path = malloc(strlen(directory) + strlen(args[0]) + 2);
			sprintf(temp_path, "%s/%s", directory, args[0]);

			if (access(temp_path, X_OK) == 0)
			{
				command_path = temp_path;
				break;
			}

			free(temp_path);
			directory = strtok(NULL, ":");
		}

		if (command_path == NULL)
		{
			char error[] = "./hsh: command not found\n";
			write(STDERR_FILENO, error, sizeof(error) - 1);
			exit(1);
		}

		if (execve(command_path, args, NULL) == -1)
		{
			char error[] = "execve failed\n";
			write(STDERR_FILENO, error, sizeof(error) - 1);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}

