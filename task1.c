#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "shell.h"
#include <stdio.h>

/**
 * Displays the prompt.
 */
void display_prompt(void)
{
write(STDOUT_FILENO, "#cisfun$ ", 9);
}
/**
 * read_command - Reads the command entered by the user.
 * Returns: the dynamically allocated buffer containing the command.
 */
char *read_command(void)
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters_read;

characters_read = getline(&buffer, &bufsize, stdin);

if (characters_read == -1)
{
if (feof(stdin))
{
write(STDOUT_FILENO, "\n", 1); /* Handle end of file (Ctrl+D) */
}
else
{
perror("getline");
}

exit(EXIT_FAILURE);
}

buffer[characters_read - 1] = '\0'; /* Remove newline character */

return (buffer);
}
/**
 * Executes the given command.
 * @param command The command to execute.
 */
void execute_command(char *command)
{
pid_t child_pid;
int status;

child_pid = fork(); /* Create a child process */

if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
/* Child process */
char **args = malloc(2 * sizeof(char *));
args[0] = command;
args[1] = NULL;
execve(command, args, NULL); /* Execute the command */

/* execve returns only if an error occurs */
perror("execve");
free(args);
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
waitpid(child_pid, &status, 0); /* Wait for the child process to finish */
}
}
/**
 * Cleans up the dynamically allocated memory.
 * @param buffer The buffer to free.
 */
void cleanup(char *buffer)
{
free(buffer);
}
