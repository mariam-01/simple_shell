#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 10


void print_prompt(void);
ssize_t read_input(char *buffer, size_t size);
void execute_command(const char *command);
void run_shell(void);
void execute_command_with_args(const char *command, char **args);
void execute_command_with_path(const char *command, char *arguments[]);
char *create_command_path(const char *dir, const char *command);
void shell_exit(void);
void execute_env(void);
char *shell_getline(void);
void execute_custom_command(const char *command, char *args[]);
int parse_input(const char *input, char *commands[]);
void execute_command_with_args_custom(const char *command, char *args[]);
void execute_command_with_path_custom(const char *command, char *arguments[]);
void write_command_info(const char *command);
void print_arguments(char *args[]);
void free_arguments(char *args[]);
char *create_command_path(const char *dir, const char *command);
void execute_child_process(const char *command_path, char *arguments[]);
void handle_child_process_status(pid_t child_pid, const char *command);
int my_strlen(const char *str);




#endif /* SHELL_H */
