#include "header.h"
#include <sys/types.h>
#include <unistd.h>
/**
 * fork_task - Create a new process by forking the current process.
 *
 * Demonstrates the usage of the fork function to create a new process.
 * Prints a message indicating whether the current process is the parent
 * or the child. Prints a failure message if the fork operation fails.
 */
void fork_task(void)
{
pid_t pid = fork();

if (pid > 0)
{
write(1, "Fork task: Parent process\n", 26);
}
else if (pid == 0)
{
write(1, "Fork task: Child process\n", 25);
}
else
{
write(1, "Fork task: Failed to fork\n", 26);
}
}
