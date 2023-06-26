#include <stdio.h>
#include <stdlib.h>

char **environ;
/**
 * execute_env - Executes the shell's built-in "env" command.
 * Prints the current environment variables.
 */
void execute_env(void)
{
int i = 0;
while (environ[i] != NULL)
{
puts(environ[i]);
i++;
}
}
