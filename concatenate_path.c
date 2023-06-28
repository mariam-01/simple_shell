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

/**
* handle_exit_command - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Returns: None
*/
void handle_exit_command(char **command, char *line)
{
free(line);
deallocate_buffers(command);
exit(0);
}

/**
* handle_interactive_signal - handles signals in interactive mode
* @signal_num: the signal number
*
* Return: None
*/
void handle_interactive_signal(int signal_num)
{
if (signal_num == SIGINT)
{
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "$ ", 2);
}
}




