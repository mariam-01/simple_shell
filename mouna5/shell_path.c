#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define MAX_PATHS 64

volatile sig_atomic_t stop = 0;

void handleSignal(int signal)
{
if (signal == SIGINT)
{
stop = 1;
}
}
int tokenize(char *command, char *arguments[])
{
int argc = 0;
char *token = strtok(command, " \t\n");
while (token != NULL && argc < MAX_ARGUMENTS - 1)
{
arguments[argc++] = token;
token = strtok(NULL, " \t\n");
}
arguments[argc] = NULL;
return argc;
}

int findCommand(char *command, char *paths[])
{
int i = 0;
char *path = paths[i];
char commandPath[MAX_COMMAND_LENGTH];
while (paths[i] != NULL)
{
if (strstr(command, paths[i]) == command)
{
return i; /*Return index directly if command includes path*/
}

snprintf(commandPath, sizeof(commandPath), "%s/%s", path, command);
if (access(commandPath, X_OK) == 0)
{
return (i);
}
i++;
}
return (-1);
}

int main()
{
char *paths[MAX_PATHS] = {"/bin", "/usr/bin", NULL};

signal(SIGINT, handleSignal);

while (!stop)
{
char command[MAX_COMMAND_LENGTH];
char *arguments[MAX_ARGUMENTS];
int argc;
int pathIndex;
pid_t pid;
char error_msg[64];

write(STDOUT_FILENO, ":) ", 3);

if (fgets(command, sizeof(command), stdin) == NULL)
{
write(STDOUT_FILENO, "\n", 1);
break;
}

command[strcspn(command, "\n")] = '\0';

argc = tokenize(command, arguments);
if (argc == 0)
{
continue;
}

pathIndex = findCommand(arguments[0], paths);
if (pathIndex == -1)
{
char error_msg[64];
snprintf(error_msg, sizeof(error_msg), "Command not found: %s\n", arguments[0]);
write(STDOUT_FILENO, error_msg, strlen(error_msg));
continue;
}

pid = fork();
if (pid == -1)
{
char error_msg[64];
snprintf(error_msg, sizeof(error_msg), "fork: ");
write(STDERR_FILENO, error_msg, strlen(error_msg));
perror("");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char commandPath[MAX_COMMAND_LENGTH];
if (strstr(arguments[0], paths[pathIndex]) == arguments[0])
{
snprintf(commandPath, sizeof(commandPath), "%s", arguments[0]);
}
else
{
snprintf(commandPath, sizeof(commandPath), "%s/%s", paths[pathIndex], arguments[0]);
}

execv(commandPath, arguments);

snprintf(error_msg, sizeof(error_msg), "execv: ");
write(STDERR_FILENO, error_msg, strlen(error_msg));
perror("");
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);

if (WIFEXITED(status))
{

}
else if (WIFSIGNALED(status))
{
char signal_msg[64];
snprintf(signal_msg, sizeof(signal_msg), "Child process terminated by signal %d\n", WTERMSIG(status));
write(STDOUT_FILENO, signal_msg, strlen(signal_msg));
}
}
}

return (0);
}
