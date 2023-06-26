#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/*
* Custom getline: reads a line from stdin.
* Returns a dynamically allocated string containing the line.
* Returns: NULL if there is an error or end of input is reached.
*/
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
{/* End of input */
if (line != NULL && line_index > 0)
{
line[line_index] = '\0';
return (line);
}
else
{
return (NULL);
}}
else if (bytes_read < 0)
{/* Error reading input */
return (NULL);
}}
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
return (line);
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
}}}
/*
* Function to handle the "exit" command.
* Takes a string argument containing the exit status.
* Exits the program with the provided status.
*/
void handle_exit(char *arg)
{
int status = atoi(arg);
exit(status);
}
/*
* Function to tokenize a command line into arguments.
* Takes a string containing the command line and an array of strings to store the arguments.
* Returns the number of arguments found.
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
/*
* Main function of the program.
* Reads a command from the user, tokenizes it, and performs
* the necessary actions.
* Returns 0 upon successful execution.
*/
int main(void)
{
char command[100];
char *args[10];
int arg_count;
while (1)
{
write(STDOUT_FILENO, "$ ", 2);
fgets(command, sizeof(command), stdin);
/* Tokenize the command into arguments */
arg_count = tokenize_command(command, args);
/* Handle the "exit" command */
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
} /* Add your code to handle other commands here */
/* If the command is not recognized */
write(STDOUT_FILENO, "Command not found.\n", 19);
}
return (0);
}
