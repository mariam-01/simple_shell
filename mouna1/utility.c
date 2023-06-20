#include "shell.h"

/* Remove the trailing newline character from a string */
void removeTrailingNewline(char *str)
{
str[strcspn(str, "\n")] = '\0';
}
