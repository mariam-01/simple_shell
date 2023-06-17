#ifndef B_CHECK_H
#define B_CHECK_H

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

/* Task 1: Command Line Interpreter */
void execute_command_line(char *command);

/* Task 2: Handle Command Lines with Arguments */
void tokenize_arguments(char *command, char *args[]);

/* Task 3: Handle the PATH */
char *find_command_path(char *command);

/* Task 4: Implement the exit Built-in */
void exit_shell(void);

/* Task 5: Implement the env Built-in */
void print_environment(char *envp[]);

#endif /* B_CHECK_H */
