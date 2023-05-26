#include "main.h"

void excmd(char **args)
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
        if (execve(args[0], args, NULL) == -1)
        {
            char error[] = "./hsh: command not found\n";
            write(STDERR_FILENO, error, sizeof(error) - 1);
            exit(1);
        }
    }
    else
    {
        wait(NULL);
    }
}
