#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
/**
 * execute_command_with_args_custom - Execute a custom
 * command with arguments
 * @command: The command to execute
 * @args: An array of arguments
 */
void execute_command_with_args_custom(const char *command, char *args[])
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (child_pid == 0)
{

if (execvp(command, args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}
else
{

wait(&status);
}
}
/**
 * execute_command_with_path_custom - Execute a custom
 * command with path and arguments
 * @command: The command to execute
 * @arguments: An array of arguments
 */
void execute_command_with_path_custom(const char *command, char *arguments[])
{
char *args[MAX_ARGS] = {NULL};
int i = 0;
int j;
args[0] = strdup(command);
if (args[0] == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}

while (arguments[i] != NULL && i < MAX_ARGS - 1)
{
args[i + 1] = strdup(arguments[i]);
if (args[i + 1] == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
i++;
}

args[i + 1] = NULL;

execute_command_with_args(command, args);

/* Free allocated memory */

for (j = 0; j < i + 1; j++)
{
free(args[j]);
}
}
