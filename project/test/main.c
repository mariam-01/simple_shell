#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <stdio.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define STDOUT_FILENO 1



int main(void)
{
char *command = NULL;
size_t command_length = 0;
char *arguments[MAX_ARGUMENTS];
while (1)
{
write(STDOUT_FILENO, "$ ", 2);/*Read command from the user*/
if (getline(&command, &command_length, stdin) == -1)
/*Handle end of file (Ctrl+D)*/
{
write(STDOUT_FILENO, "\n", 1);
executeExit();
}
tokenizeCommand(command, arguments);/*Tokenize the command*/
if (_strcmp(arguments[0], "ls") == 0)/*Check for built-in commands*/
{
if (arguments[1] == NULL)
executeLs(arguments);
else if (_strcmp(arguments[1], "-l") == 0 && arguments[2] != NULL)
executeLsDetailed(arguments);
else
write(STDOUT_FILENO, "Invalid arguments for ls command\n", 32);
}
else if (_strcmp(arguments[0], "exit") == 0)
{
executeExit();
}
else if (_strcmp(arguments[0], "env") == 0)
{
printEnvironment();
}
else
{
write(STDOUT_FILENO, "Command not found: ", 19);
write(STDOUT_FILENO, arguments[0], _strlen(arguments[0]));
write(STDOUT_FILENO, "\n", 1);
}
free(command);
}
return (0);
}
