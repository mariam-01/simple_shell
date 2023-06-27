#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "shell.h"
#define BUFFER_SIZE 1024

/**
* main - Entry point of the simple shell program
*
* Return: Always returns 0.
*/
int main(void)
{
char *buffer = NULL;

while (1)
{
display_prompt();
buffer = read_command();

if (strcmp(buffer, "exit") == 0)
{
break; /* Handle exit command */
}

execute_command(buffer);
cleanup(buffer);
}

return (EXIT_SUCCESS);
}

