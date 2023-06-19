#include "header.h"
#include <stdio.h>
#include <unistd.h>
/**
 * fflush_task - Flush the standard output stream.
 *
 * Demonstrates the usage of the fflush function to flush the standard output
 * stream. Prints a message indicating that the standard output has been
 * flushed.
 */
void fflush_task(void)
{
fflush(stdout);
write(1, "Fflush task: Standard output flushed\n", 36);
}
