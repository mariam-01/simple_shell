/*
 * File: main.c
 * Auth: Mouna Menouer
 *       Meriem
 */

#include "shell.h"



/**
* main - Entry point for the shell program
*
* Return: Always 0
*/
int main(void)
{
char buffer[BUFFER_SIZE];

while (1)
{
display_prompt();

if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
write(STDOUT_FILENO, "\n", 1);
break; /* End of file (Ctrl+D) was encountered */
}

remove_newline(buffer);

execute_command(buffer);
}

return (0);
}
