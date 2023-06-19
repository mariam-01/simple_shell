#include "header.h"
#include <unistd.h>
#include <fcntl.h>
/**
 * close_task - Close a file.
 *
 * Demonstrates the usage of the close function to close a file descriptor.
 * Opens the file "example.txt" for reading and attempts to close the file.
 * Prints a success message if the file is closed successfully,
 * and a failure message otherwise.
 */
void close_task(void)
{
int fd = open("example.txt", O_RDONLY);
if (fd != -1)
{
int result = close(fd);
if (result == 0)
{
write(1, "Close task: File closed successfully\n", 36);
}
else
{
write(1, "Close task: Failed to close file\n", 32);
}
}
else
{
write(1, "Close task: Failed to open file\n", 31);
}
}
