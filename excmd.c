#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * excmd - function executes stored prompt
 * @command: prompt command storage to be executed
 *
 * Return: the difference between final value of s and the initial value of str
 */

void excmd(char** args)
{
    pid_t pid;
    int status;

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
        wait(&status);
        if (WIFEXITED(status))
        {
            status = WEXITSTATUS(status);
        }
        else
        {
            status = 1;
        }
    }
}
