#include <stdio.h>
#include <stdlib.h>
#include "b_check.h"
/**
 * main - Entry point of the simple shell program
 *
 * This is the main function that serves as the entry point
 * of the simple shell program. It reads commands from the user
 * using a custom getline function, tokenizes them, and executes
 * them accordingly. The shell program continues to run until
 * the user enters the "exit" command or terminates it.
 * Return: The exit status of the program.
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

while (1)
{
printf("$ ");
read = _getline(&line, &len, stdin);

if (read == -1)
{
printf("\n");
break;
}

printf("Input: %s", line);
}

free(line);
return (0);
}
