#include "header.h"
#include <unistd.h>
#include <string.h>
/**
 * execve_task - Execute a program.
 *
 * Demonstrates the usage of the execve system call to execute a program.
 * Prints a failure message if the execution fails.
 */
void execve_task(void)
{
char *argv[] = {"/bin/ls", "-l", NULL};
char *envp[] = {NULL};

int result = execve(argv[0], argv, envp);

if (result == -1)
{
char *error = "Execve task: Failed to execute the program\n";
write(1, error, strlen(error));
}
}
