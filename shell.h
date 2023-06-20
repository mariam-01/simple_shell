#ifndef SHELL_H
#define SHELL_H

void tokenizeCommand(char* command, char** arguments);
void executeLs(char** arguments);
void executeLsDetailed(char** arguments);
void executeExit(void);
void printEnvironment(void);
void runShell(void);
char* customGetline(void);
#endif /* SHELL_H */
