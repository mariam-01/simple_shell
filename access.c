#include "header.h"
#include <unistd.h>

/**
 * access_task - checks if a file can be accessed
 *
 * This function checks if a file specified by the path can be accessed
 * with the given mode. It uses the `access` system call to perform the check.
 * If the file can be accessed, it writes a message indicating that the file
 * can be accessed. Otherwise, it writes a message indicating that the file
 * cannot be accessed.
 */

void access_task(void)
{
const char *path = "/path/to/file";
int mode = R_OK;  /*task 0*/

int result = access(path, mode);

if (result == 0)
{
write(1, "Access task: File can be accessed\n", 32);
}
else
{
write(1, "Access task: File cannot be accessed\n", 36);
}
}
