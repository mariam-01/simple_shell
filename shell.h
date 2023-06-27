#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

#define BUFFER_SIZE 1024

void displayPrompt(void);
void removeNewline(char *str);
void executeCommand(char *command);
void shell(void);

#endif /* SHELL_H */
