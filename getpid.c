#include "header.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * getpid_task - Get the process ID of the current process.
 *
 * Demonstrates the usage of the getpid function to retrieve the process ID
 * of the current process. Prints the process ID along with a descriptive
 * message.
 */

void getpid_task(void)
{
pid_t pid = getpid();
char pid_str[16];
snprintf(pid_str, sizeof(pid_str), "%d", pid);
write(1, "Getpid task: Process ID: ", 25);
write(1, pid_str, strlen(pid_str));
write(1, "\n", 1);
}
