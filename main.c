#include "shell.h"
/**
* main - carries out the read, execute, then print output loop
* @argc: total number of command-line arguments
* @argv: array of command-line arguments
* @env: array of environment variables
* Return: 0
*/
int main(int argc, char **argv, char *env[])
{
char *line = NULL;
char *resolved_path = NULL;
char *path = NULL;
size_t bufsize = 0;
ssize_t linesize = 0;
char **command = NULL;
char **paths = NULL;
(void)env, (void)argv;
if (argc < 1)
return (-1);
signal(SIGINT, handle_interactive_signal);
while (1)
{
deallocate_buffers(command);
deallocate_buffers(paths);
free(resolved_path);
display_shell_prompt();
linesize = getline(&line, &bufsize, stdin);
if (linesize < 0)
break;
info.ln_count++;
if (line[linesize - 1] == '\n')
line[linesize - 1] = '\0';
command = tokenize_input(line);
if (command == NULL || *command == NULL || **command == '\0')
continue;
if (check_and_execute(command, line))
continue;
path = get_path_from_env();
paths = tokenize_input(path);
resolved_path = search_valid_path(paths, command[0]);
if (!resolved_path)
perror(argv[0]);
else
run_command(resolved_path, command);
}
if (linesize < 0 && flags.interactive)
write(STDERR_FILENO, "\n", 1);
free(line);
return (0);
}
