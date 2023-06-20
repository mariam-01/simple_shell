#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
/* Execute the given command */
void executeCommand(const char *command)
{
int pid = fork();
if (pid < 0)
{
perror("Fork failed");
exitFailure();
}
else if (pid == 0)
{
execlp(command, command, NULL);
printCommandNotFoundError(command);
exitFailure();
}
else
{

int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
{
printCommandExecutionError(command);
}
}
}
