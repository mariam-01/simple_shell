#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <stdio.h>

void executeCd(char** arguments)
{
char cwd[1024];
if (arguments[1] == NULL)
{
/*No argument provided, change to the home directory*/

char* homeDir = getenv("HOME");
if (homeDir == NULL)
{
write(STDOUT_FILENO, "cd: No $HOME variable set\n", 26);
return;
}

if (chdir(homeDir) != 0)
{
perror("cd");
}
}
else if (strcmp(arguments[1], "-") == 0)
{
/*Change to the previous directory*/
char* prevDir = getenv("OLDPWD");
if (prevDir == NULL)
{
write(STDOUT_FILENO, "cd: No previous directory\n", 26);
return;
}

if (chdir(prevDir) != 0)
{
perror("cd");
}
}
else
{
/*Change to the specified directory*/
if (chdir(arguments[1]) != 0)
{
perror("cd");
}
}

/* Update the PWD environment variable*/

if (getcwd(cwd, sizeof(cwd)) != NULL)
{
setenv("PWD", cwd, 1);
}
else
{
perror("cd");
}
}

