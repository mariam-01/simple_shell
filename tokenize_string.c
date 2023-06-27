#include "shell.h"

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
tokens = realloc(tokens, bufferSize * sizeof(CharPtrPtr));
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
