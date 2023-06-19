#include "header.h"
#include <unistd.h>
/**
 * _exit_task - Terminate the program immediately.
 *
 * Demonstrates the usage of the _exit function to terminate the program
 * immediately without performing any further cleanup or flushing buffers.
 * It exits with a successful status code (0).
 */
void _exit_task(void)
{
_exit(0);
}
