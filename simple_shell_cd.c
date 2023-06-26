#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * Updates the environment variable PWD with the current working directory.
 */
void update_pwd() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        setenv("PWD", cwd, 1);
    } else {
        perror("getcwd() error");
    }
}

/**
 * Changes the current directory of the process.
 *
 * @param directory The directory path to change to.
 * @return 0 if the directory is changed successfully, -1 otherwise.
 */
int cd_command(char *directory) {
    if (directory == NULL || strcmp(directory, "") == 0) {
        directory = getenv("HOME");
        if (directory == NULL) {
            fprintf(stderr, "cd: $HOME not set\n");
            return -1;
        }
    } else if (strcmp(directory, "-") == 0) {
        directory = getenv("OLDPWD");
        if (directory == NULL) {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return -1;
        }
        printf("%s\n", directory);
    }

    char *current_dir = malloc(1024);
    if (getcwd(current_dir, 1024) == NULL) {
        perror("getcwd() error");
        free(current_dir);
        return -1;
    }

    if (chdir(directory) != 0) {
        perror("chdir() error");
        free(current_dir);
        return -1;
    }

    setenv("OLDPWD", current_dir, 1);
    free(current_dir);

    update_pwd();
    return 0;
}

/**
 * Main entry point of the program.
 *
 * @return 0 on successful execution.
 */
int main() {
    // Example usage
    if (cd_command(NULL) == 0) {
        printf("Changed directory to: %s\n", getenv("PWD"));
    }

    if (cd_command("-") == 0) {
        printf("Changed directory to: %s\n", getenv("PWD"));
    }

    return 0;
}
