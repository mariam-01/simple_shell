#include "shell.h"
#include <stdlib.h>
/**
* shell_exit - Exits the shell.
*
* This function terminates the shell and exits the program.
* It is a built-in command that does not take any arguments.
*
* Usage: exit
*/
void shell_exit(void)
{
exit(EXIT_SUCCESS);
}
