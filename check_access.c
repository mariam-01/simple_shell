#include "shell.h"

/**
* search_valid_path - searches for a valid path containing the given command
* @path_tokens: tokenized path
* @command: user entered command
*
* Return: the path appended with the command on success, NULL on failure
*/
char *search_valid_path(char **path_tokens, char *command)
{
int index = 0;
char *result;

while (path_tokens[index])
{
result = combine_path_command(path_tokens[index], command);
if (check_access(result, F_OK | X_OK) == 0)
return (result);
free(result);
index++;
}

return (NULL);
}
