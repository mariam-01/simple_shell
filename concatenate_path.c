#include "shell.h"
/**
* concatenate_path - concatenates path and command
* @path: path of command
* @command: user entered command
*
* Return: buffer containing command with path on success, NULL on failure
*/
char *concatenate_path(char *path, char *command)
{
size_t path_len = custom_strlen(path);
size_t command_len = custom_strlen(command);
size_t total_len = path_len + command_len + 2;
char *buf = malloc(sizeof(char) * total_len);
char *p = buf;
if (command == NULL)
command = "";

if (path == NULL)
path = "";
if (buf == NULL)
return (NULL);


while (*path)
*p++ = *path++;

if (path[path_len - 1] != '/')
*p++ = '/';

while (*command)
*p++ = *command++;

*p = '\0';

return (buf);
}
