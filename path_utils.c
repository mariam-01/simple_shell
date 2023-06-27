#include "shell.h"

/**
* get_path_from_env - finds the path from the global environment
* Return: NULL if path is not found, or path if path is found
*/
char *get_path_from_env(void)
{
char **env = environ;
char *path = NULL;

while (*env != NULL)
{
if (_strncmp(*env, "PATH=", 5) == 0)
{
path = *env + 5;
break;
}
env++;
}

return (path);
}
