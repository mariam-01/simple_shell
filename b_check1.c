#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "b_check.h"
#define BUFFER_SIZE 1024
#define MAX_ARGS 64

/* Task 1: Command Line Interpreter */
/* Function to execute the command line */
/**
 * execute_command_line - Execute the command line
 * @command: The command line string to execute
 * This function takes a command line string as input and executes
 * it using the system() function.
 * It simply passes the command to the underlying shell for execution.
 */
void execute_command_line(char *command)
{
int status = system(command);
if (status == -1)
{
perror("Execution failed");
/*Handle error condition*/
}
}

/* Task 2: Handle Command Lines with Arguments */

/* Function to tokenize the command line into arguments */
/**
 * tokenize_arguments - Tokenize the command line into arguments
 * @command: The command line string to tokenize
 * @args: The array to store the tokenized arguments
 * This function takes a command line string as input and tokenizes
 * it into individual arguments.
 * It uses the strtok() function to split the string based on spaces
 * as delimiters.
 * The resulting arguments are stored in the 'args' array.
 */
void tokenize_arguments(char *command, char *args[])
{
char *token = strtok(command, " ");
int i = 0;
while (token != NULL && i < MAX_ARGS)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
}

/* Task 3: Handle the PATH */
/**
 * find_command_path - Search for the command in the directories
 * specified by PATH
 * @command: The command name to search for
 * @envp: The array of environment variables
 * This function takes a command name and the environment variables as input.
 * It searches for the command in the directories specified by the
 * PATH environment variable.
 * It uses the strtok() function to iterate over the directories,
 * and checks if the command file exists
 * in each directory using the access() function.
 * If the command is found, it returns the full path to the command file.
 * Return: A pointer to a string containing the full path to the
 * command if found,
 * or NULL if the command is not found in any directory.
 */
char *find_command_path(char *command)
{
char *path_env = getenv("PATH");
char *dir = strtok(path_env, ":");
char *command_path = NULL;

while (dir != NULL)
{
command_path = (char *)malloc(strlen(dir) + strlen(command) + 2);
sprintf(command_path, "%s/%s", dir, command);

if (access(command_path, F_OK) == 0)
{
return (command_path);
}

free(command_path);
dir = strtok(NULL, ":");
}

return (NULL);
}

/* Task 4: Implement the exit Built-in */
/**
 * exit_shell - Handle the exit built-in command
 * This function is called when the user enters the "exit" command.
 * It simply calls the exit() function to terminate the shell.
 */
void exit_shell(void)
{
exit(EXIT_SUCCESS);
}

/* Task 5: Implement the env Built-in */
/**
 * print_environment - Handle the env built-in command
 * @envp: The array of environment variables
 * This function is called when the user enters the "env" command.
 * It prints the current environment by iterating over the 'envp'
 * array and printing each variable.
 */
void print_environment(char *envp[])
{
int i = 0;
while (envp[i] != NULL)
{
printf("%s\n", envp[i]);
i++;
}
}
