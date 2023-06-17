#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "b_check.h"
#define BUFFER_SIZE 1024
#define MAX_ARGS 64


void print_environment(char *envp[]);
/**
 * main - Entry point of the shell program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command
 * -line arguments
 * @envp: An array of strings containing the environment variables
 * This is the main function that serves as the entry point
 * of the shell program.
 * It takes command-line arguments, such as the program name
 * and any additional arguments,
 * and an array of environment variables.
 * The function reads commands from the user, tokenizes them,
 * and executes them accordingly.
 * It also handles built-in commands like "exit" and "env" and
 * executes external commands
 * by searching for their paths in the directories specified by
 * the PATH environment variable.
 * The shell program continues to run until the user enters the
 * "exit" command or terminates it.
 * The return value indicates the exit status of the program.
 * Return: The exit status of the program, typically 0 for successful
 * execution.
 */
int main(int argc, char *argv[], char *envp[])
{
char buffer[BUFFER_SIZE];
char *args[MAX_ARGS];
ssize_t read_bytes;
pid_t child_pid;
(void)argc;
(void)argv; 
while (1)
{
printf("$ ");
read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);

if (read_bytes == -1)
{
perror("read");
exit(EXIT_FAILURE);
}
else if (read_bytes == 0)
{
printf("\n");
break;
}

buffer[read_bytes - 1] = '\0'; /* Remove newline character */

/* Task 2: Tokenize the command line */
tokenize_arguments(buffer, args);

if (strcmp(args[0], "exit") == 0)
{
/* Task 4: Handle the exit built-in command */
exit_shell();
break;
}
else if (strcmp(args[0], "env") == 0)
{
/* Task 5: Handle the env built-in command */
print_environment(envp);
}
else
{
/* Task 3: Search for the command in PATH */
char *command_path = find_command_path(args[0]);

if (command_path != NULL)
{
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
/* Child process */
execve(command_path, args, envp);
perror(args[0]); /* If execve fails, print error message */
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
wait(NULL);
}

free(command_path);
}
else
{
printf("%s: command not found\n", args[0]);
}
}
}

return (EXIT_SUCCESS);
}
