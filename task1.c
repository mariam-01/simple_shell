#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024


/**
* displayPrompt - Displays the shell prompt
*/
void displayPrompt(void)
{
write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
* removeNewline - Removes the newline character from a string
* @str: The string to modify
*/
void removeNewline(char *str)
{
str[strcspn(str, "\n")] = '\0';
}

/**
* executeCommand - Executes a command in the shell
* @command: The command to execute
*/
void executeCommand(char *command)
{
pid_t pid = fork();
extern char **environ;
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char **args = malloc(sizeof(char *) * 2);
args[0] = command;
args[1] = NULL;

execve(command, args, environ);

/* execve returned, meaning the command was not found */
write(STDOUT_FILENO, "./shell: No such file or directory\n", 35);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
/**
* shell - The main loop for the shell
*/
void shell(void)
{
char command[BUFFER_SIZE];
ssize_t bytesRead;

while (1)
{
displayPrompt();

bytesRead = read(STDIN_FILENO, command, BUFFER_SIZE);
if (bytesRead == -1)
{
perror("read");
exit(EXIT_FAILURE);
}

if (bytesRead == 0)
continue;

removeNewline(command);

if (strcmp(command, "exit") == 0)
{
write(STDOUT_FILENO, "./shell: No such file or directory\n", 35);
continue;
}

if (strcmp(command, "/bin/ls") == 0)
executeCommand(command);
else
write(STDOUT_FILENO, "./shell: No such file or directory\n", 35);
}
}
