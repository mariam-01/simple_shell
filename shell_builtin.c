#include "shell.h"

/**
* execute_builtin_command - executes built-in commands
* @command: tokenized commands
* @input_line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int execute_builtin_command(char **command, char *input_line)
{
if (strcmp(command[0], "env") == 0)
{
output_environment();
return (1);
}
else if (strcmp(command[0], "exit") == 0)
{
handle_exit_command(command, input_line);
return (1);
}

return (0);
}
