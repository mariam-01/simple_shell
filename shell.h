#ifndef SHELL_H
#define SHELL_H

void tokenizeCommand(char* command, char** arguments);
void executeLs(char** arguments);
void executeLsDetailed(char** arguments);
void executeExit(int status);
void printEnvironment(void);
void runShell(void);
char* customGetline(void);
void executeUnsetenv(cha **arguments);
void executeSetenv(char **arguments);
#endif /* SHELL_H */
