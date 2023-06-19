#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * getline_task - Read a line from standard input.
 *
 * Demonstrates the usage of the getline function to read a line from
 * the standard input. If successful, it prints the entered line.
 * Otherwise, it prints a failure message.
 */
void getline_task(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

write(1, "Enter a line: ", 14);
read = getline(&line, &len, stdin);
if (read != -1)
{
write(1, "Getline task: Line entered: ", 28);
write(1, line, strlen(line));
}
else
{
write(1, "Getline task: Failed to read line\n", 34);
}

free(line);
}
