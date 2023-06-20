#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
* shell_getline - Read a line of input from the user.
* Returns the line of input as a string.
*/
char *shell_getline(void)
{
char *buffer = NULL;
size_t buffer_size = 0;
ssize_t chars_read;
size_t i;
char *new_buffer;

while ((chars_read = read(STDIN_FILENO, buffer +
buffer_size, BUFFER_SIZE)) > 0)
{
buffer_size += chars_read;
new_buffer = realloc(buffer, buffer_size + BUFFER_SIZE);
if (!new_buffer)
{
perror("realloc");
exit(EXIT_FAILURE);
}
buffer = new_buffer;
}

if (chars_read == -1)
{
perror("read");
exit(EXIT_FAILURE);
}

buffer[buffer_size - 1] = '\0';  /*Null-terminate the buffer*/

/*Manual copy of the contents of the new buffer to the existing buffer*/
for (i = 0; i < buffer_size; i++)
{
buffer[i] = new_buffer[i];
}

free(new_buffer); /* Free the new buffer*/

return (buffer);
}
