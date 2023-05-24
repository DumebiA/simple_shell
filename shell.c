#include "main.h"

void display_prompt() {
    char prompt[] = "$ ";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

char* read_command() {
    ssize_t read_size;
    size_t input_size = MAX_COMMAND_LENGTH;
    char* command = (char*)malloc(input_size * sizeof(char));

    read_size = getline(&command, &input_size, stdin);

    if (read_size == -1) {
        free(command);
        command = NULL;
    } else {
        size_t length = 0;
        while (command[length] != '\n' && command[length] != '\0') {
            length++;
        }
        command[length] = '\0';
    }

    return command;
}

void execute_command(char* command) {
    pid_t pid = fork();

    if (pid < 0) {

        char error[] = "Failed to create child process\n";
        write(STDERR_FILENO, error, sizeof(error) - 1);
        return;
    }

    if (pid == 0) {

        char* args[2];
        args[0] = command;
        args[1] = NULL;
        if (execve(command, args, NULL) == -1) {
            char error[] = "Failed to execute command\n";
            write(STDERR_FILENO, error, sizeof(error) - 1);
            exit(1);
        }
    } else {

        wait(NULL);
    }
}

int main() {
           char* command;
    while (1) {
        display_prompt();

        command = read_command();

        if (!command) {

            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        execute_command(command);
        free(command);
    }

    return 0;
}

