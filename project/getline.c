#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int buffer_position = 0;

char* customGetline(void)
{
int length = 0;
char c;
char* line = malloc((length + 1) * sizeof(char));
while (1)
{
if (buffer_position == 0)
{
/*Read a chunk of characters into the buffer*/
int bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytes_read <= 0)
{
if (length == 0)
{
return (NULL);  /*End of file*/
}
else
{
break;  /*End of line*/
}
}
}

c = buffer[buffer_position++];
if (c == '\n' || c == '\r')
{
break;  /*End of line*/
}

/*Store character in buffer*/
buffer[length++] = c;

/*Check buffer length*/
if (length >= BUFFER_SIZE - 1)
{
break;
}
}

/*Null-terminate the buffer*/
buffer[length] = '\0';

/*Allocate memory for the line*/
strncpy(line, buffer, length + 1);

return (line);
}
