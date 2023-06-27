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
int find_command_path(char *command, char *path, char *command_path);
void run_executable(char *command, char *command_path);
#endif /* SHELL_H */
