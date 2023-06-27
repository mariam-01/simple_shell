#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void) {
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters_read;
pid_t child_pid;
int status;

while (1) {
printf("$ "); /* Display prompt */
characters_read = getline(&buffer, &bufsize, stdin); /* Read command line */

if (characters_read == -1) {
if (feof(stdin)) {
printf("\n"); /* Handle end of file (Ctrl+D) */
break;
} else {
perror("getline");
continue;
}
}

buffer[characters_read - 1] = '\0'; /* Remove newline character */

if (strcmp(buffer, "exit") == 0) {
break; /* Handle exit command */
}

child_pid = fork(); /* Create a child process */

if (child_pid == -1) {
perror("fork");
continue;
}

if (child_pid == 0) {
/* Child process */
char *args[] = {buffer, NULL};
execve(buffer, args, NULL); /* Execute the command */

/* execve returns only if an error occurs */
perror("execve");
exit(EXIT_FAILURE);
} else {
/* Parent process */
waitpid(child_pid, &status, 0); /* Wait for the child process to finish */
}
}

free(buffer);
return EXIT_SUCCESS;
}
