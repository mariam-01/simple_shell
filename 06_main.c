#include <stdlib.h>
#include <unistd.h>
#include "b_check.h"
#include <stdio.h>

/**
 * Entry point of the program.
 * Reads input from the user and processes it.
 *
 * @return The exit status of the program.
 */
int main(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t characters_read;

b_puts("$ ");
while ((characters_read = _getline(&line, &bufsize, stdin)) != -1)
{
/* Process the input line */
b_puts("You entered: ");
b_puts(line);
b_puts("$ ");
}

free(line);
return (0);
}
