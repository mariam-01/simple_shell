#include "shell.h"

/**
* my_strlen - Calculates the length of a string.
* @str: The input string.
*
* This function calculates the length of the input
* string and returns the result.
*
* Return: The length of the string.
*/
int my_strlen(const char *str)
{
int length = 0;
while (str[length] != '\0')
{
length++;
}
return (length);
}
