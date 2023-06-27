/*
 * File: command.c
 * Auth: Mouna Menouer
 *       Meriem
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

#define BUFFER_SIZE 1024
#define PROMPT "$ "

/**
* display_prompt - Displays the shell prompt
*/
void display_prompt(void)
{
write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

/**
* remove_newline - Removes the trailing newline character from the buffer
* @buffer: The input buffer containing the command
*/
void remove_newline(char *buffer)
{
buffer[strcspn(buffer, "\n")] = '\0';
}

/**
* execute_command - Executes the specified command
* @command: The command to be executed
*/
void execute_command(char *command)
{
char *args[2];
int status;
pid_t pid = fork();
args[0] = command;
args[1] = NULL;


if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
execve(args[0], args, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
wait(&status);
}
}
