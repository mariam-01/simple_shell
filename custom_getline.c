#include "shell.h"

/**
* custom_getline - reads a line from stdin
* @line: pointer to store the line
* @bufsize: pointer to the buffer size
*
* Return: number of characters read
*/
ssize_t custom_getline(char **line, size_t *bufsize)
{
ssize_t linesize = getline(line, bufsize, stdin);

if (linesize < 0)
{
if (feof(stdin))
return (-1);  /*End of input reached*/
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}

return (linesize);
}
