#include "header.h"
#include <unistd.h>
#include <string.h>
/**
 * getcwd_task - Get the current working directory.
 *
 * Demonstrates the usage of the getcwd function to obtain the current
 * working directory path. Prints the current working directory path if
 * successful, or a failure message if the operation fails.
 */
void getcwd_task(void)
{
char path[1024];

if (getcwd(path, sizeof(path)) != NULL)
{
write(1, "Getcwd task: Current working directory: ", 40);
write(1, path, strlen(path));
write(1, "\n", 1);
}
else
{
write(1, "Getcwd task: Failed to get current working directory\n", 52);
}
}
