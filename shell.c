#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define BUFFER_SIZE 1024

char **parse_command(char *command)
{
char **args = malloc(BUFFER_SIZE * sizeof(char *));
char *token;
int i = 0;

if (args == NULL)
{
perror("malloc failed");
exit(EXIT_FAILURE);
}

token = strtok(command, " \n");
while (token != NULL)
{
args[i] = token;
i++;
token = strtok(NULL, " \n");
}
args[i] = NULL;

return (args);
}

int execute_command(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
{
perror("Error executing command");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
else if (pid < 0)
{
/* Forking error */
perror("Fork failed");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}

void shell_loop(void)
{
char *line;
char **args;
int status;

do {
write(STDOUT_FILENO, "($) ", 4);
line = malloc(BUFFER_SIZE * sizeof(char));
if (line == NULL)
{
perror("malloc failed");
exit(EXIT_FAILURE);
}

if (fgets(line, BUFFER_SIZE, stdin) == NULL)
{
if (feof(stdin))
{
write(STDOUT_FILENO, "\n", 1);
exit(EXIT_SUCCESS);
}
else
{
perror("fgets failed");
exit(EXIT_FAILURE);
}
}

args = parse_command(line);
status = execute_command(args);

free(line);
free(args);
} while (status);
}

