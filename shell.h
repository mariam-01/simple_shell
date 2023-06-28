#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#define TOKEN_BUFFER_SIZE 256
typedef char **CharPtrPtr;

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
int check_and_execute(char **cmd, char *buf);
void display_shell_prompt(void);
int is_shell_interactive(void);
void run_command(char *path, char **args);
CharPtrPtr tokenize_input(char *input);
void handle_exit_command(char **command, char *line);
void handle_interactive_signal(int signal_num);
char *search_valid_path(char **path_tokens, char *command);
char *concatenate_path(char *path, char *command);
int execute_builtin_command(char **command, char *input_line);
char *get_path_from_env(void);
void output_environment(void);
int compare_strings(char *str1, char *str2);
int custom_strlen(char *s);
int custom_strncmp(char *str1, char *str2, int n);
char *create_duplicate_string(char *source);
char *find_character(char *string, char character);
char *combine_path_command(char *path, char *command);
int check_access(const char *path, int mode);
void deallocate_buffers(char **buffers);
int check_access(const char *path, int mode);
/**
 *struct info - a structure
 *@final_exit: integer
 *@ln_count: integer
 * Return: 0
 */
struct info
{
int final_exit;
int ln_count;
} info;

/**
 *struct flags - a structure
 *@interactive: booleen
 * Return: 0
 */

struct flags
{
bool interactive;
} flags;

#endif /* SHELL_H */
