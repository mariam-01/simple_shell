#include "shell.h"
#include <stdlib.h>
#include <string.h>

/* Check if the given command exists in the PATH */
int isCommandInPath(const char *command)
{
char *path;
char *token;
path = getenv("PATH");
if (path == NULL)
{
return 0; /* PATH is not set, command not found */
}

token = strtok(path, ":");
while (token != NULL)
{
char fullCommand[MAX_INPUT_LENGTH];
size_t commandLength = 0;
size_t i;

for (i = 0; token[i] != '\0'; i++)
{
fullCommand[commandLength++] = token[i];
}

fullCommand[commandLength++] = '/';

for (i = 0; command[i] != '\0'; i++)
{
fullCommand[commandLength++] = command[i];
}

fullCommand[commandLength] = '\0';

if (access(fullCommand, X_OK) == 0)
{
return 1; /* Command found in PATH */
}

token = strtok(NULL, ":");
}

return 0; /* Command not found in PATH */
}

/* Execute the given command with PATH handling */
void executeCommandWithPath(const char *command)
{
if (isCommandInPath(command))
{
executeCommand(command);
}
else
{
printCommandNotFoundError(command);
}
}
