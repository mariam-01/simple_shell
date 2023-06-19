#include "header.h"
#include <unistd.h>
#include <string.h>
/**
 * chdir_task - Change current working directory
 *
 * Demonstrates the usage of the chdir system call to change the current
 * working directory to a specified path. Prints a success message if the
 * directory change is successful, and a failure message otherwise.
 */
void chdir_task(void)
{
const char *path = "/path/to/directory";

int result = chdir(path);

if (result == 0)
{
write(1, "Chdir task: Directory changed successfully\n", 43);
}
else
{
write(1, "Chdir task: Failed to change directory\n", 39);
}
}
