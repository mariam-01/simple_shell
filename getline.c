#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "b_check.h"
#define BUFFER_SIZE 1024
/**
 * _getline - Read a line of input from a file stream
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: The file stream to read from (e.g., stdin)
 *
 * This function reads a line of input from the given file stream.
 * It dynamically allocates memory for the line buffer as needed.
 * The buffer will automatically expand to accommodate longer lines.
 * The function returns the number of characters read,
 * excluding the newline,
 * or -1 if the end of the file is reached or an error occurs.
 * Return: The number of characters read, excluding the newline,
 * or -1 if the end of the file is reached or an error occurs.
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
if (*lineptr == NULL) {
*n = BUFFER_SIZE;
*lineptr = malloc(*n);
if (*lineptr == NULL) {
perror("malloc");
exit(EXIT_FAILURE);
}
}

size_t pos = 0;
int c;

while ((c = fgetc(stream)) != EOF)
 {
(*lineptr)[pos++] = c;

if (pos >= *n) {
*n += BUFFER_SIZE;
*lineptr = realloc(*lineptr, *n);
if (*lineptr == NULL)
 {
perror("realloc");
exit(EXIT_FAILURE);
}
}

if (c == '\n')
break;
}

if (pos == 0 && c == EOF)
return (-1);

(*lineptr)[pos] = '\0';
return (pos);
}
