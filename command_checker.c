#include "shell.h"

/**
* check_and_execute - checks whether it's a built-in
* function or executes a command
* @cmd: tokenized user input
* @buf: line derived from getline function
*
* Return: 1 if cmd executed, 0 if cmd is not executed
*/
int check_and_execute(char **cmd, char *buf)
{
if (execute_builtin_command(cmd, buf))
return (1);

if (cmd[0][0] == '/')
{
run_command(cmd[0], cmd);
return (1);
}

return (0);
}
