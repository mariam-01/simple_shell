#ifndef SHELL_H
#define SHELL_H

/* Function Declarations */
char **parse_command(char *command);
int execute_command(char **args);
void shell_loop();
int execute_builtin(char **args);

#endif /* SHELL_H */
