#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
* execute_command_with_path - Executes the given command with arguments using
* the PATH environment variable in a child process.
* @command: The command to execute.
* @arguments: The arguments for the command.
* Return: The full command path, or NULL if the command was not found in the
* directory.
*/
void execute_command_with_path(const char *command, char *arguments[])
{
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir = strtok(path_copy, ":");

while (dir != NULL)
{
char *command_path = create_command_path(dir, command);
if (command_path != NULL)
{
pid_t child_pid = fork();

if (child_pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
execute_child_process(command_path, arguments);
}
else
{
handle_child_process_status(child_pid, command);
}

free(command_path);
}

dir = strtok(NULL, ":");
}

free(path_copy);
}
/**
* Creates the full path for the given command in the specified directory.
* @param dir :The directory to search in.
* @param command The command to create the path for.
* @return The full command path, or NULL if the command
* was not found in the directory.
*/
char *create_command_path(const char *dir, const char *command)
{
size_t dir_len = strlen(dir);
size_t command_len = strlen(command);
size_t path_len = dir_len + command_len + 2; /* +1 for '/' +1 for '\0' */

char *path = malloc(path_len);
if (path == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}

snprintf(path, path_len, "%s/%s", dir, command);

if (access(path, X_OK) == 0)
return (path);

free(path);
return (NULL);
}
/**
* Executes the child process with the specified command path and arguments.
*
* @param command_path: The full path of the command to execute.
* @param arguments:The arguments for the command.
*/
void execute_child_process(const char *command_path, char *arguments[])
{
if (execv(command_path, arguments) == -1)
{
perror("Command execution error");
exit(EXIT_FAILURE);
}
}
/**
* Handles the status of the child process and displays
* an error message if the command was not found.
* @param child_pid: The process ID of the child process.
* @param command: The command that was executed.
*/
void handle_child_process_status(pid_t child_pid, const char *command)
{
int status;
waitpid(child_pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
char error_message[] = ": Command not found\n";
write(STDOUT_FILENO, command, strlen(command));
write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
}
}
