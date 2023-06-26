#include "shell.h"
#include <unistd.h>

/**
* exitShell - exits the shell
* @shellData: Structure containing shell data and arguments.
* Return: Exits with a given exit status
* (0) if (*shellData).argv[0] != "exit"
*/
int exitShell(shellData_t *shellData)
{
int exitStatus = -2;
int exitcheck;

if ((*shellData).argv[1] != NULL)
{
exitcheck = _erratoi((*shellData).argv[1]);
if (exitcheck == -1)
{
(*shellData).status = 2;
write(STDOUT_FILENO, "Illegal number: ", 16);
write(STDOUT_FILENO, (*shellData).argv[1], _strlen((*shellData).argv[1]));
write(STDOUT_FILENO, "\n", 1);
return 1;
}
(*shellData).err_num = exitcheck;
return exitStatus;
}

(*shellData).err_num = -1;
return exitStatus;
}
/**
* printHelpMessage - prints help message
* @shellData: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int printHelpMessage(info_t *shellData)
{
char **arg_array;
char *helpMessage = "help call works. Function not yet implemented \n";
int helpMessageLength = _strlen(helpMessage);

arg_array = (*shellData).argv;
write(STDOUT_FILENO, helpMessage, helpMessageLength);
if (0)
write(STDOUT_FILENO, *arg_array, _strlen(*arg_array)); /* temp att_unused workaround */
return (0);
}

