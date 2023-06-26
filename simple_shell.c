#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024



int main() {
char input[BUFFER_SIZE];
pid_t pid;

while (1) {
printf("$ ");
fflush(stdout);

fgets(input, BUFFER_SIZE, stdin);
input[strcspn(input, "\n")] = '\0';  /* Remove the newline character */

if (strcmp(input, "exit") == 0)
break;

if (strcmp(input, "env") == 0) {
extern char **environ;
char **env = environ;

while (*env) {
printf("%s\n", *env);
env++;
}
continue;
}

/* Fork a child process */
pid = fork();

if (pid < 0) {
perror("fork");
exit(1);
} else if (pid == 0) {
/* Child process */

/* Tokenize the input command */
char *token = strtok(input, " ");
char *args[BUFFER_SIZE];
int i = 0;

while (token != NULL) {
args[i++] = token;
token = strtok(NULL, " ");
}

args[i] = NULL;

/* Execute the command */
execvp(args[0], args);

/* If execvp returns, an error occurred */
perror("execvp");
exit(1);
} else {
/* Parent process */
wait(NULL);
}
}

return 0;
}

