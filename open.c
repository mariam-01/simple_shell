#include "header.h"
#include <fcntl.h>
#include <unistd.h>
/**
 * open_task - Open a file.
 *
 * Demonstrates the usage of the open function to open a file. If the file
 * "example.txt" is successfully opened for reading, it prints a success
 * message. Otherwise, it prints a failure message.
 */
void open_task(void)
{
int fd = open("example.txt", O_RDONLY);
if (fd != -1)
{
write(1, "Open task: File opened successfully\n", 36);
close(fd);
}
else
{
write(1, "Open task: Failed to open file\n", 31);
}
}
