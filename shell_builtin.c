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
if (is_builtin_command(*command))
{
if (strcmp(*command, "env") == 0)
{
print_env();
return (1);
}
else if (strcmp(*command, "exit") == 0)
{
exit_cmd(command, input_line);
return (1);
}
}

return (0);
}
