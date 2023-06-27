#include "shell.h"

/**
* display_shell_prompt - displays the shell prompt to indicate user input
*
* Return: void
*/
void display_shell_prompt(void)
{
if (is_shell_interactive())
{
write(STDERR_FILENO, "$ ", 2);
}
}

/**
* is_shell_interactive - checks if the shell is in interactive mode
*
* Return: 1 if the shell is interactive, 0 otherwise
*/
int is_shell_interactive(void)
{
return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO));
}
