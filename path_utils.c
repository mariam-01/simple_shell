#include "shell.h"

/**
* get_path_from_env - finds the path from the global environment
* Return: NULL if path is not found, or path if path is found
*/
char *get_path_from_env(void)
{
char **env = environ;
char *path = NULL;

while (*env != NULL)
{
if (custom_strncmp(*env, "PATH=", 5) == 0)
{
path = *env + 5;
break;
}
env++;
}

return (path);
}

/**
 * run_command - executes the specified command
 * @path: path of the command
 * @args: array of arguments including the command
 *
 * Returns: None
 */
void run_command(char *path, char **args)
{
pid_t child_pid;
int status;
char **env = environ;

child_pid = fork();
if (child_pid == -1)
{
perror("Fork failed");
return;
}

if (child_pid == 0)
{
/*Child process*/
if (execve(path, args, env) == -1)
{
perror("Execution failed");
exit(EXIT_FAILURE);
}
}
else
{
/*Parent process*/
if (wait(&status) == -1)
{
perror("Wait failed");
}
}
}

/**
* execute_builtin_command - executes built-in commands
* @command: tokenized commands
* @input_line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int execute_builtin_command(char **command, char *input_line)
{
if (strcmp(command[0], "env") == 0)
{
output_environment();
return (1);
}
else if (strcmp(command[0], "exit") == 0)
{
handle_exit_command(command, input_line);
return (1);
}

return (0);
}

/**
* tokenize_input - creates tokens from given input
* @input: input to be tokenized
*
* Return: array of strings representing tokens
*/
CharPtrPtr tokenize_input(char *input)
{
CharPtrPtr tokens = NULL;
const char *delimiters = " :\t\r\n";
int tokenCount = 0;
int bufferSize = TOKEN_BUFFER_SIZE;
int index = 0;
char *token = NULL;

tokens = malloc(bufferSize * sizeof(CharPtrPtr));
if (!tokens)
return (NULL);

token = strtok(input, delimiters);
while (token)
{
if (index >= bufferSize)
{
bufferSize += TOKEN_BUFFER_SIZE;
tokens = realloc(tokens, bufferSize * (sizeof(CharPtrPtr)));
if (!tokens)
return (NULL);
}

tokens[index] = create_duplicate_string(token);
if (!tokens[index])
{
deallocate_buffers(tokens);
return (NULL);
}

tokenCount++;
index++;

token = strtok(NULL, delimiters);
}

tokens[index] = NULL;
return (tokens);
}
