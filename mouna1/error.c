#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
/* Terminate the program with a failure status code */
void exitFailure(void)
{
_exit(EXIT_FAILURE);
}

/* Print an error message indicating that the command was not found */
void printCommandNotFoundError(const char *command) {

const char *msg = command;
while (*msg != '\0')
{
msg++;
}

write(STDERR_FILENO, command, msg - command);
write(STDERR_FILENO, ": Command not found\n", sizeof(": Command not found\n") - 1);

}

/* Print an error message indicating an error occurred during command execution */
void printCommandExecutionError(const char *command)
{

const char *msg = "Error executing command: ";
const char *cmd = command;
while (*msg != '\0')
{
write(STDERR_FILENO, msg, 1);
msg++;
}
while (*cmd != '\0')
{
write(STDERR_FILENO, cmd, 1);
cmd++;
}
write(STDERR_FILENO, "\n", sizeof("\n") - 1);


}
