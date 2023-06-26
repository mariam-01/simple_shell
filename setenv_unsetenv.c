#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * Sets an environment variable with the specified name and value.
 *
 * @param variable The name of the environment variable.
 * @param value The value to be assigned to the environment variable.
 * @return 0 if the environment variable is set successfully, -1 otherwise.
 */
int setenv_command(char *variable, char *value) {
    if (setenv(variable, value, 1) != 0) {
        perror("Failed to set environment variable");
        return -1;
    }
    return 0;
}

/**
 * Unsets an environment variable with the specified name.
 *
 * @param variable The name of the environment variable to be unset.
 * @return 0 if the environment variable is unset successfully, -1 otherwise.
 */
int unsetenv_command(char *variable) {
    if (unsetenv(variable) != 0) {
        perror("Failed to unset environment variable");
        return -1;
    }
    return 0;
}

/**
 * Main entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main() {
  
    if (setenv_command("MY_VAR", "my_value") == 0) {
        write(STDOUT_FILENO, "Environment variable set successfully\n", 37);
    }

    if (unsetenv_command("MY_VAR") == 0) {
        write(STDOUT_FILENO, "Environment variable unset successfully\n", 39);
    }

    return 0;
}
