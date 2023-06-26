#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

extern char **environ;

#define MAX_COMMAND_LENGTH 100

void task2() {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    const char prompt[] = "#cisfun$ ";
    const size_t prompt_length = sizeof(prompt) - 1;

    while (1) {
        write(STDOUT_FILENO, prompt, prompt_length);

        /* Read the command from the input */
        if (fgets(command, sizeof(command), stdin) == NULL) {
            /* End of file (Ctrl+D) encountered */
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        /* Remove the newline character at the end of the command */
        command[strcspn(command, "\n")] = '\0';

        /* Skip empty commands */
        if (strlen(command) == 0) {
            continue;
        }

        /* Create a child process to execute the command */
        pid = fork();

        if (pid < 0) {
            write(STDERR_FILENO, "Failed to create a child process.\n", 33);
            exit(1);
        }

        if (pid == 0) {
            /* Child process */

            /* Tokenize the command and its arguments */
            char *args[MAX_COMMAND_LENGTH];
            char *token = strtok(command, " ");
            int i = 0;

            while (token != NULL) {
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }

            args[i] = NULL;

            /* Execute the command */
            execve(args[0], args, environ);

            /* If execve returns, it means the executable was not found */
            write(STDERR_FILENO, "./shell: No such file or directory\n", 36);
            exit(1);
        } else {
            /* Parent process */

            /* Wait for the child process to finish */
            int status;
            waitpid(pid, &status, 0);

            /* Check if the child process exited normally */
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status != 0) {
                    /*Only display the message if the exit status is not 1*/
                    if (exit_status != 1) {
                        char exit_message[50];
                        int length = snprintf(exit_message, sizeof(exit_message),
                                              "Child process exited with status %d.\n", exit_status);
                        write(STDERR_FILENO, exit_message, length);
                    }
                }
            } else if (WIFSIGNALED(status)) {
                int signal_number = WTERMSIG(status);
                char signal_message[50];
                int length = snprintf(signal_message, sizeof(signal_message),
                                      "Child process terminated with signal %d.\n", signal_number);
                write(STDERR_FILENO, signal_message, length);
            }
        }
        
        /* Check if the user entered "exit" and continue the loop */
        if (strcmp(command, "exit") == 0) {
            continue;
        }
    }
}
