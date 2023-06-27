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
result = concatenate_path(path_tokens[index], command);
if (result != NULL && check_access(result, F_OK | X_OK) == 0)
return (result);
free(result);
index++;
}

return (NULL);
}
/**
 * check_access - checks if a file or directory exists and has the specified mode of access
 * @path: path to the file or directory
 * @mode: mode of access to be checked (e.g., F_OK for existence, R_OK for read access, etc.)
 *
 * Return: 0 if the access check succeeds, -1 if it fails
 */
int check_access(const char *path, int mode)
{
return (access(path, mode));
}
