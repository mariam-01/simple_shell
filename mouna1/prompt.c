#include "shell.h"
#include <stdio.h>
#include <unistd.h>


/* Display the shell prompt */
void displayPrompt()
{
write(STDOUT_FILENO, "$ ", 2);
fflush(stdout);

}

/* Get user input from the command line */
int getUserInput(char *input)
{
if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
{
return (0);
}
input[strcspn(input, "\n")] = '\0';
return (1);
}
