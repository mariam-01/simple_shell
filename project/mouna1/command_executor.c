#include "shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Execute the given command */
void runCommand(const char *command)
{
pid_t pid = fork();

if (pid < 0)
{
/*Fork failed*/
printForkFailedError();
}
else if (pid == 0)
{
/*Child process*/
execlp("sh", "sh", "-c", command, NULL);
_exit(1); /* If execlp fails, exit the child process*/
}
else
{
/*Parent process*/
int status;
waitpid(pid, &status, 0);
}
}
