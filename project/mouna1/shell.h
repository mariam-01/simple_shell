#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

void displayPrompt();
int getUserInput(char *input);
void executeCommand(const char *command);
void exitFailure(void);
void printCommandNotFoundError(const char *command);
void printCommandExecutionError(const char *command);
void removeTrailingNewline(char *str);
void executeCommandWithPath(const char *command);
int isCommandInPath(const char *command);
void printForkFailedError(void);
void runCommand(const char *command);




#endif /* SHELL_H */
