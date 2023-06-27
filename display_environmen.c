#include "shell.h"

/**
* output_environment - outputs the environment variables to stdout
*
* Return: None
*/
void output_environment(void)
{
char **env = environ;
int i;
for (i = 0; env[i] != NULL; i++)
{
char *current_env = env[i];
int len = custom_strlen(current_env);

write(STDOUT_FILENO, current_env, len);
write(STDOUT_FILENO, "\n", 1);
}
}
