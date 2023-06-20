#include "shell.h"
/* main.c */

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, non-zero on failure
 */
int main(void)
{
char *args[] = {"ls", "-l", NULL};
const char *command_path = "/bin/ls";


/* Example usage of execute_command_with_args */
execute_command_with_args("ls", args);
/* Example usage of execute_command_with_path */
execute_command_with_path(command_path, args);

/* Run the simple shell */
run_shell();

/* Execute the "env" built-in command*/
execute_env();

/*Exit the shell*/
shell_exit();


/*Run the simple shell*/
run_shell();
return (0);
}
