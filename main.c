#include "main.h"


/**
 * Function to compare two strings
 */
int string_compare(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

/**
 * Function to print the current environment
 */
void print_env()
{
    extern char **environ;
    int i = 0;
    while (environ[i] != NULL)
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}

/**
 * Function to display the input prompt
 */
void input_prompt()
{
    char prompt[] = "($) ";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * Function to parse the command and tokenize it
 */
char **parse(char *command, int *num_args)
{
    char **args = (char **)malloc((MAX_ARGS + 1) * sizeof(char *));
    char *tok;
    int index = 0;

    tok = strtok(command, " \t\n");
    while (tok != NULL)
    {
        args[index] = tok;
        index++;
        tok = strtok(NULL, " \t\n");
    }
    args[index] = NULL;
    *num_args = index;

    return args;
}

/**
 * Main function
 */
int main()
{
    char command[MAX_COMMAND_LENGTH];
    ssize_t nreads;
    int num_args;
    char **args;

    while (1)
    {
        input_prompt();

        nreads = read(STDIN_FILENO, command, sizeof(command));

        if (nreads <= 0)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        command[nreads - 1] = '\0';

        if (string_compare(command, "exit"))
        {
            break;
        }
        else if (string_compare(command, "env"))
        {
            print_env();
            continue;
        }

        args = parse(command, &num_args);

        if (num_args > 0)
        {
            excmd(args);
        }
        free(args);
    }

    return 0;
}
