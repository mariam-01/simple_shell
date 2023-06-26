#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"



/**
* execute_custom_command - Executes a custom command with arguments.
* @command: The command to execute.
* @args: An array of arguments for the command.
*
* This function executes a custom command with the provided arguments.
*/
void execute_custom_command(const char *command, char *args[])
{
write_command_info(command);
print_arguments(args);
free_arguments(args);
}

/**
* write_command_info - Writes command execution information to stdout.
* @command: The command being executed.
*/
void write_command_info(const char *command)
{
write(1, "Executing custom command: ", 26);
write(1, command, my_strlen(command));
write(1, "\n", 1);
}

/**
* print_arguments - Prints the command arguments to stdout.
* @args: An array of arguments for the command.
*/
void print_arguments(char *args[])
{
int i = 0;
write(1, "Arguments:\n", 11);

while (args[i] != NULL)
{
write(1, args[i], my_strlen(args[i]));
write(1, "\n", 1);
i++;
}
}

/**
* free_arguments - Frees the memory allocated for command arguments.
* @args: An array of arguments for the command.
*/
void free_arguments(char *args[])
{
int i = 0;
while (args[i] != NULL)
{
free(args[i]);
i++;
}
}
