#include "header.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
/**
 * closedir_task - Close a directory.
 *
 * Demonstrates the usage of the closedir function to close a directory stream.
 * Opens a directory specified by "/path/to/directory"and attempts to close it.
 * Prints a success message if the directory is closed successfully,
 * and a failure message otherwise.
 */
void closedir_task(void)
{
DIR *directory = opendir("/path/to/directory");

if (directory != NULL)
{
int result = closedir(directory);

if (result == 0)
{
write(1, "Closedir task: Directory closed successfully\n", 46);
}
else
{
write(1, "Closedir task: Failed to close directory\n", 42);
}
}
else
{
write(1, "Closedir task: Failed to open directory\n", 40);
}
}
