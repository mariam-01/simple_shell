#ifndef SHELL_H
#define SHELL_H

/* Include necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Macro Definitions */
#define BUFFER_SIZE 1024
#define PROMPT "$ "

/* Function Prototypes */
void display_prompt(void);
void remove_newline(char *buffer);
void execute_command(char *command);

#endif /* SHELL_H */
