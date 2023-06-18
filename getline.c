#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "b_check.h"

/**
 * Custom implementation of the getline function.
 * Reads a line from the specified stream and stores it
 * in the provided buffer.
 * @param lineptr Pointer to the buffer where the line will be stored.
 * @param n Pointer to the size of the buffer.
 * @param stream The stream to read from.
 * @return The number of characters read, or -1 on error or end-of-file.
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
static char buffer[1024];
static size_t buffer_index = 0;
static ssize_t characters_in_buffer = 0;
ssize_t characters_read = 0;
char *new_line = NULL; /*Declaration of new_line*/
if (buffer_index >= (size_t)characters_in_buffer)
{
/* Buffer is empty, read from stream */
characters_read = read(fileno(stream), buffer, sizeof(buffer));
if (characters_read == -1)
return (-1);
if (characters_read == 0)
return (-1); /* EOF reached */

buffer_index = 0;
characters_in_buffer = characters_read;
}

if ((size_t)characters_in_buffer > 0)
{
size_t line_index = 0;
char *line = *lineptr;

if (line == NULL || *n == 0)
{
*n = 128;
line = malloc(*n * sizeof(char));
if (line == NULL)
return (-1); /* Memory allocation error */
*lineptr = line;
}

while (buffer_index < (size_t)characters_in_buffer)
{
char current_char = buffer[buffer_index++];
line[line_index++] = current_char;

if (current_char == '\n')
break;

if (line_index == *n - 1)
{
*n *= 2;
new_line = realloc(line, *n * sizeof(char));
if (new_line == NULL)
{
free(line);
return (-1); /* Memory allocation error */
}
line = new_line;
*lineptr = line;
}
}

line[line_index] = '\0';
}

return (characters_read);
}
