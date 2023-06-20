#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * execute_command_with_args - Execute a command with arguments
 * @command: The command to execute
 * @args: An array of arguments
 */
void execute_command_with_args(const char *command, char **args)
{
pid_t pid = fork();

if (pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(command, args) == -1)
{
perror("Command execution error");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
char error_message[] = ": Command not found\n";
write(STDOUT_FILENO, command, strlen(command));
write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
}
}
}
