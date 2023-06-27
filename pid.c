#include "shell.h"

/**
 * run_command - executes the specified command
 * @path: path of the command
 * @args: array of arguments including the command
 *
 * Returns: None
 */
void run_command(char *path, char **args)
{
pid_t child_pid;
int status;
char **env = environ;

child_pid = fork();
if (child_pid == -1)
{
perror("Fork failed");
return;
}

if (child_pid == 0)
{
/*Child process*/
if (execve(path, args, env) == -1)
{
perror("Execution failed");
exit(EXIT_FAILURE);
}
}
else
{
/*Parent process*/
if (wait(&status) == -1)
{
perror("Wait failed");
}
}
}
