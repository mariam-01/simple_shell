#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <stdio.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define STDOUT_FILENO 1

int main()
{
char command[MAX_COMMAND_LENGTH];
char* arguments[MAX_ARGUMENTS];

while (1)
{
write(STDOUT_FILENO, "$ ", 2);

/*Read command from the user*/
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
/*Handle end of file (Ctrl+D)*/
write(STDOUT_FILENO, "\n", 1);
executeExit();
}

/*Tokenize the command*/
tokenizeCommand(command, arguments);

/*Check for built-in commands*/
if (strcmp(arguments[0], "ls") == 0)
{
if (arguments[1] == NULL)
executeLs(arguments);
else if (strcmp(arguments[1], "-l") == 0 && arguments[2] != NULL)
executeLsDetailed(arguments);
else
write(STDOUT_FILENO, "Invalid arguments for ls command\n", 32);
}
else if (strcmp(arguments[0], "exit") == 0)
{
executeExit();
}
else if (strcmp(arguments[0], "env") == 0)
{
printEnvironment();
}
else
{
write(STDOUT_FILENO, "Command not found: ", 19);
write(STDOUT_FILENO, arguments[0], strlen(arguments[0]));
write(STDOUT_FILENO, "\n", 1);
}
}

return (0);
