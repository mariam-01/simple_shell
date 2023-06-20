#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
#include <stdlib.h>
void tokenizeCommand(char* command, char** arguments)
{
char *token ;
int i = 0;
token = strtok(command, " \t\n");
while (token != NULL)
{
arguments[i] = token;
i++;
token = strtok(NULL, " \t\n");
}
arguments[i] = NULL;
}

void executeLs(char** arguments)
{
pid_t pid = fork();
if (pid < 0)
{
perror("fork() failed");
return;
}
else if (pid == 0)
{
/*Child process*/
execve("/bin/ls", arguments, NULL);
perror("execve() failed");
_exit(EXIT_FAILURE);
}
else
{
/*Parent process*/
wait(NULL);
}
}

void executeLsDetailed(char** arguments)
{
pid_t pid = fork();
if (pid < 0)
{
perror("fork() failed");
return;
}
else if (pid == 0)
{
/*Child process*/
execve("/bin/ls", arguments, NULL);
perror("execve() failed");
_exit(EXIT_FAILURE);
}
else
{
/*Parent process*/
wait(NULL);
}
}

void executeExit()
{
exit(EXIT_SUCCESS);
}

void printEnvironment(void)
{
extern char** environ;
char** env = environ;
while (*env)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
}
