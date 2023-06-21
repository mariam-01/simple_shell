#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void tokenizeCommand(char *command, char **arguments);
void executeLs(char **arguments);
void executeLsDetailed(char **arguments);
void executeExit(void);
void printEnvironment(void);
void runShell(void);
char *customGetline(void);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);

int _getc(int fd);
char* _fgets(char* str, int n, FILE* stream);

#endif /* SHELL_H */


