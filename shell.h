#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

void display_prompt(void);
char* read_command(void);
void execute_command(char* command);
void cleanup(char* buffer);

#endif /* SHELL_H */
