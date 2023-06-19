#include "header.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * malloc_task - Allocate memory dynamically using malloc.
 *
 * Demonstrates the usage of the malloc function to allocate
 * memory dynamically.
 * Prints a success message if the memory allocation is
 * successful, and a failure
 * message otherwise.
 */
void malloc_task(void)
{
int *ptr = malloc(10 * sizeof(int));
if (ptr != NULL)
{
write(1, "Malloc task: Memory allocated successfully\n", 42);
free(ptr);
}
else
{
write(1, "Malloc task: Failed to allocate memory\n", 38);
}
}
