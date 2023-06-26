#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

/**
* print_prompt - Prints the shell prompt.
*/
void print_prompt(void)
{
char prompt[] = "#cisfun$ ";
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
* read_input - Reads user input from stdin.
* @buffer: The buffer to store the input.
* @size: The maximum size of the input buffer.
*
* Return: The number of bytes read.
*/
ssize_t read_input(char *buffer, size_t size)
{
ssize_t bytes_read = read(STDIN_FILENO, buffer, size);
if (bytes_read > 0 && buffer[bytes_read - 1] == '\n')
buffer[bytes_read - 1] = '\0';
return (bytes_read);
}

/**
* execute_command - Executes the given command in a child process.
* @command: The command to execute.
*/
void execute_command(const char *command)
{
pid_t pid = fork();

if (pid < 0)
{
perror("Fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char *cmd[2];
cmd[0] = (char *)command;
cmd[1] = NULL;
if (execvp(cmd[0], cmd) == -1)
{
perror("Command execution error");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
char error_message[] = ": Command not found\n";
write(STDOUT_FILENO, command, strlen(command));
write(STDOUT_FILENO, error_message, sizeof(error_message) - 1);
}
}
}

/**
* run_shell - Runs the simple shell.
* Continuously reads user input and executes commands.
* Exits when an EOF (Ctrl+D) is encountered.
*/
void run_shell(void)
{
ssize_t bytesRead;
char input[100];
char *command;

while (1)
{
print_prompt();
bytesRead = read_input(input, sizeof(input));
if (bytesRead == 0)
break;

command = strtok(input, " ");
while (command != NULL)
{
execute_command(command);
command = strtok(NULL, " ");
}
}
}
