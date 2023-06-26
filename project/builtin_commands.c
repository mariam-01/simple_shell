#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void executeSetenv(char **arguments)
{
    if (arguments[1] == NULL || arguments[2] == NULL)
    {
        write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", strlen("Usage: setenv VARIABLE VALUE\n"));
        return;
    }

    if (setenv(arguments[1], arguments[2], 1) != 0)
    {
        write(STDERR_FILENO, "Failed to set environment variable\n", strlen("Failed to set environment variable\n"));
    }
}

void executeUnsetenv(char **arguments)
{
    if (arguments[1] == NULL)
    {
        write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", strlen("Usage: unsetenv VARIABLE\n"));
        return;
    }

    if (unsetenv(arguments[1]) != 0)
    {
        write(STDERR_FILENO, "Failed to unset environment variable\n", strlen("Failed to unset environment variable\n"));
    }
}
