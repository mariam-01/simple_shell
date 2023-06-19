#include "header.h"
#include <unistd.h>

/**
 * isatty_task - Check if a file descriptor refers to a terminal.
 *
 * Demonstrates the usage of the isatty function to determine whether a file
 * descriptor refers to a terminal or not. Prints a message indicating whether
 * the file descriptor is a terminal or not.
 */
void isatty_task(void)
{
int fd = STDOUT_FILENO;
if (isatty(fd))
{
write(1, "Isatty task: File descriptor refers to a terminal\n", 48);
}
else
{
write(1, "Isatty task: File descriptor does not refer to a terminal\n", 57);
}
}
