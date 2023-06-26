#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];
    const char prompt[] = ":) ";

    while (1) {
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

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

        /* Check if the user entered "exit" and exit the loop */
        if (strcmp(command, "exit") == 0) {
            break;
        }

        /* Check if the command is "/bin/ls" */
        if (strcmp(command, "/bin/ls") == 0 || strcmp(command, "ls") == 0) {
            system("/bin/ls");
            continue;
        }

        /* Check if the command is "ls -l /tmp" */
        if (strcmp(command, "ls -l /tmp") == 0) {
            system("ls -l /tmp");
            continue;
        }

        /* Check if the command exists as an executable file */
        if (access(command, X_OK) != -1) {
            pid_t pid = fork();
            if (pid == 0) {
                /* Child process */
                execlp(command, command, NULL);
                exit(0);
            } else if (pid > 0) {
                /* Parent process */
                wait(NULL);
            } else {
                /* Fork failed */
                write(STDOUT_FILENO, "Fork failed\n", 12);
            }
        } else {
            write(STDOUT_FILENO, "./shell: No such command or file\n", 32);
        }
    }

    return 0;
}
