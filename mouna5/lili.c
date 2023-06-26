#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *custom_getline()
{
static char buffer[BUFFER_SIZE];
static int buffer_index;
static int bytes_read;
char *line = NULL;
int line_index = 0;
char current_char;

while (1)
{
if (buffer_index >= bytes_read)
{
bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
buffer_index = 0;

if (bytes_read == 0)
{
if (line != NULL && line_index > 0)
{
line[line_index] = '\0';
return line;
}
else
{
return NULL;
}
}
else if (bytes_read < 0)
{
return NULL;
}
}

current_char = buffer[buffer_index++];

if (current_char == '\n')
{
if (line == NULL)
{
line = (char *)malloc((line_index + 1) * sizeof(char));
}
else
{
line = (char *)realloc(line, (line_index + 1) * sizeof(char));
}

line[line_index] = '\0';
return line;
}
else
{
if (line == NULL)
{
line = (char *)malloc((line_index + 2) * sizeof(char));
}
else
{
line = (char *)realloc(line, (line_index + 2) * sizeof(char));
}

line[line_index++] = current_char;
}
}
}

