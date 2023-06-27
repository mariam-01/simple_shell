#include "shell.h"

/**
* handle_interactive_signal - handles signals in interactive mode
* @signal_num: the signal number
*
* Return: None
*/
void handle_interactive_signal(int signal_num)
{
if (signal_num == SIGINT)
{
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "$ ", 2);
}
}
