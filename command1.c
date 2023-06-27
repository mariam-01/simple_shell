/*
 * File: command1.c
 * Auth: Mouna Menouer
 *       Meriem
 */

#include "shell.h"
#include <sys/wait.h>
/**
* find_command_path - Finds the full path of a command.
* @command: The command to find the path for.
* @path: The PATH environment variable.
* @command_path: Buffer to store the command path.
* Return: 1 if the command path is found, 0 otherwise.
*/
int find_command_path(char *command, char *path, char *command_path)
{
char *token;

token = strtok(path, ":");

while (token != NULL)
{
snprintf(command_path, BUFFER_SIZE, "%s/%s", token, command);

if (access(command_path, X_OK) == 0)
return (1);

token = strtok(NULL, ":");
}

return (0);
}

/**
* execute_command - Executes a command.
* @command: The command to execute.
*/
void execute_command(char *command)
{
char *path = getenv("PATH");
char command_path[BUFFER_SIZE];

if (path == NULL)
{
write(STDERR_FILENO, "Error: PATH environment variable not found\n", 42);
return;
}

if (!find_command_path(command, path, command_path))
{
write(STDERR_FILENO, "Error: Command not found\n", 25);
return;
}

run_executable(command, command_path);
}

/**
* run_executable - Executes the command using execve.
* @command: The command to execute.
* @command_path: The full path of the command.
*/
void run_executable(char *command, char *command_path)
{
pid_t pid = fork();
char **argv = malloc(sizeof(char *) * 2);

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
argv[0] = strdup(command);
argv[1] = NULL;
execve(command_path, argv, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
 wait(NULL);
}
free(command_path);
}
