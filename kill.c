#include "header.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
/**
 * kill_task - Send a signal to terminate the process.
 *
 * Demonstrates the usage of the kill function to send a signal to the current
 * process and terminate it. Sends the SIGKILL signal to the process. Prints a
 * success message if the process is terminated successfully, and a failure
 * message otherwise.
 */
void kill_task(void)
{
pid_t pid = getpid();
int result = kill(pid, SIGKILL);

if (result == 0)
{
write(1, "Kill task: Process killed successfully\n", 39);
}
else
{
write(1, "Kill task: Failed to kill process\n", 35);
}
}

