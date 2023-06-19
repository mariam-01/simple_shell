#include <unistd.h>
#include "header.h"
#include <stdlib.h>
/**
 * free_task - Free dynamically allocated memory.
 *
 * Demonstrates the usage of the free function to deallocate memory.
 * Frees the memory pointed to by the 'ptr' pointer. Prints a success
 * message after freeing the memory.
 */
void free_task(void)
{
int *ptr = malloc(10 * sizeof(int));
free(ptr);
write(1, "Free task: Memory freed successfully\n", 38);
}
