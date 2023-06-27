#include "shell.h"


/**
* handle_exit_command - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Returns: None
*/
void handle_exit_command(char **command, char *line)
{
free(line);
deallocate_buffers(command);
exit(0);
}

