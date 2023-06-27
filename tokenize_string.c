#include "shell.h"

/**
* main - carries out the read, execute, then print output loop
* @argc: total number of command-line arguments
* @argv: array of command-line arguments
* @env: array of environment variables
*
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

(void)env;
(void)argv;

if (argc < 1)
return (-1);

signal(SIGINT, handle_signal);

while (1)
{
free_buffers(command);
free_buffers(paths);
free(resolved_path);

prompt_user();

linesize = getline(&line, &bufsize, stdin);

if (linesize < 0)
break;

info.ln_count++;

if (line[linesize - 1] == '\n')
line[linesize - 1] = '\0';

command = tokenizer(line);

if (command == NULL || *command == NULL || **command == '\0')
continue;

if (checker(command, line))
continue;

path = find_path();
paths = tokenizer(path);
resolved_path = test_path(paths, command[0]);

if (!resolved_path)
perror(argv[0]);
else
execution(resolved_path, command);
}

if (linesize < 0 && flags.interactive)
write(STDERR_FILENO, "\n", 1);

free(line);
return (0);
}
