#include "shell.h"

/* sig_handler - Prints a new prompt upon a signal.
* @sig: The signal.
*/
void sig_handler(int sig)
{
char *new_prompt = "\n$ ";

(void)sig;
signal(SIGINT, sig_handler);
write(STDIN_FILENO, new_prompt, 3);
}

/* execute - Executes a command in a child process.
* @args: An array of arguments.
* @front: A double pointer to the beginning of args.
*
* Return: If an error occurs - a corresponding error code.
*         O/w - The exit value of the last executed command.
*/
int execute(char **args, char **front)
{
pid_t child_pid;
int status, flag = 0, ret = 0;
char *command = args[0];

/* Check if the command is a relative path or in the current directory */
if (command[0] != '/' && command[0] != '.')
{
flag = 1;
command = get_location(command);
}

/* Check if the command exists and has necessary permissions */
if (!command || (access(command, F_OK) == -1))
{
ret = (create_error(args, (errno == EACCES) ? 126 : 127));
}
else
{
/* Fork a child process to execute the command */
child_pid = fork();
if (child_pid == -1)
{
if (flag)
free(command);
perror("Error child:");
return (1);
}
if (child_pid == 0)
{
/* Execute the command in the child process */
execve(command, args, environ);
if (errno == EACCES)
ret = (create_error(args, 126));

/* Free allocated resources before exiting the child process */
free_env();
free_args(args, front);
free_alias_list(aliases);
_exit(ret);
}
else
{
/* Wait for the child process to complete */
wait(&status);
ret = WEXITSTATUS(status);
}
}
if (flag)
free(command);
return (ret);
}

int main(int argc, char *argv[])
{
int ret = 0, retn;
int *exe_ret = &retn;
char *prompt = "$ ", *new_line = "\n";

/* Set the name of the program */
name = argv[0];
hist = 1;
aliases = NULL;
signal(SIGINT, sig_handler);

*exe_ret = 0;
/* Copy the environment variables */
environ = _copyenv();
if (!environ)
exit(-100);

if (argc != 1)
{
/* Process commands from a file */
ret = proc_file_commands(argv[1], exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}

if (!isatty(STDIN_FILENO))
{
/* Non-interactive mode: read commands from standard input */
while (ret != END_OF_FILE && ret != EXIT)
ret = handle_args(exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}

while (1)
{
/* Interactive mode: read commands from user input */
write(STDOUT_FILENO, prompt, 2);
ret = handle_args(exe_ret);
if (ret == END_OF_FILE || ret == EXIT)
{
if (ret == END_OF_FILE)
write(STDOUT_FILENO, new_line, 1);

/* Free allocated resources before exiting the shell */
free_env();
free_alias_list(aliases);
exit(*exe_ret);
}
}

free_env();
free_alias_list(aliases);
return (*exe_ret);
}
