#include "shell.h"

/**
 * isshellinteractive - checks if the shell is in interactive mode
 *
 * Returns:
 *   - 1 if the shell is in interactive mode
 *   - 0 otherwise
 */
int isshellinteractive(void)
{
    return (fcntl(STDIN_FILENO, F_GETFL) != -1);
}

/**
 *isCharacterSeparator: checks if a character is a separator
 *@c: the character to check
 *@separators: a string of separators
 *
 * Returns:
 *   - 1 if the character is a separator
 *   - 0 otherwise
 */
int isCharacterSeparator(char c, const char *separators)
for (; *separators != '\0'; separators++)
    {
        if (*separators == c)
            return 1;
    }
return :0;
}

/**
 * int isCharacterAlphabetic - checks if a character is an alphabetic character
 *
 * Parameters:
 * @c: the character to check
 *
 * Returns:
 *  1 if the character is an alphabetic character
 *  0 otherwise
 */
int isCharacterAlphabetic(int c)
{
return (isalpha(c) != 0);
}

/**
 *convertStringToInt:converts a string to an integer
 * @str: the string to be converted
 * Returns:
 *   - the converted integer value
 *   - 0 if the string does not contain any numbers
 */
int convertStringToInt(const char *str)
int result = 0;
    int sign = 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');
        }
        else if (i == 0 && str[i] == '-')
        {
            sign = -1;
        }
        else
        {
            break;
        }
    }

    return sign * result;
}
