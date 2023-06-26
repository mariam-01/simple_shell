#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
* Reads the input into a buffer.
*
* Returns:
*   - A pointer to the buffer containing the next available character.
*   - NULL if there is no more input.
*/
char *read_buffer()
{
static char buffer[BUFFER_SIZE];
static int buffer_index = 0;
static int bytes_read = 0;
if (buffer_index >= bytes_read)
{
bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
buffer_index = 0;
if (bytes_read <= 0)
{
return (NULL);
}
}
return (&buffer[buffer_index++]);
}
/**
* Custom getline- reads a line from stdin.
*
* Returns:
*   - A dynamically allocated string containing the line.
*   - NULL if there is an error or end of input is reached.
*/
char *custom_getline()
{
char *line = NULL;
int line_index = 0;
char *buffer;

while (1)
{
buffer = read_buffer();

if (buffer == NULL)
{
if (line != NULL && line_index > 0)
{
line[line_index] = '\0';
return (line);
}
else
{
return (NULL);
}
}
while (*buffer != '\n')
{
if (line == NULL)
{
line = (char *)malloc((line_index + 2) * sizeof(char));
}
else
{
line = (char *)realloc(line, (line_index + 2) * sizeof(char));
}
line[line_index++] = *buffer++;
}

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
}
/**
* handle_exit - Function to handle the "exit" command.
*
* @arg: A string argument containing the exit status.
* Exits the program with the provided status.
*/
void handle_exit(char *arg)
{
exit(atoi(arg));
}
/**
* tokenize_command-function to tokenize a command line into arguments.
* @line: A string containing the command line.
* @args: An array of strings to store the arguments.
*
* Returns: The number of arguments found.
*/
int tokenize_command(char *line, char **args)
{
int arg_count = 0;
int line_length = strlen(line);
int arg_start = 0;
int arg_end = 0;
while (arg_end <= line_length)
{
if (line[arg_end] == ' ' || line[arg_end] == '\t' || line[arg_end] == '\0')
{
if (arg_start != arg_end)
{
line[arg_end] = '\0';
args[arg_count++] = &line[arg_start];
}
arg_start = arg_end + 1;
}
arg_end++;
}
return (arg_count);
}
int main(void)
{
char command[100];
char *args[10];
int arg_count;
while (1)
{
write(STDOUT_FILENO, "$ ", 2);
fgets(command, sizeof(command), stdin);
arg_count = tokenize_command(command, args);
if (arg_count > 0 && strcmp(args[0], "exit") == 0)
{
if (arg_count == 2)
{
handle_exit(args[1]);
}
else
{
write(STDOUT_FILENO, "Usage: exit status\n", 19);
}
continue;
}
write(STDOUT_FILENO, "Command not found.\n", 19);
}

return (0);
} 
