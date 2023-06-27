#include "shell.h"

/**
* compare_strings - compares two strings
* @str1: first string
* @str2: second string
*
* Return: 0 if the strings are equal, a negative value if str1 is less than str2,
*         or a positive value if str1 is greater than str2
*/
int compare_strings(char *str1, char *str2)
{
while (*str1 && (*str1 == *str2))
{
str1++;
str2++;
}

return (int)(*str1 - *str2);
}
/**
* custom_strlen - returns the length of a string
* @str: string passed
*
* Return: returns length of string passed
*/
int custom_strlen(char *str)
{
int length = 0;

for (; *str != '\0'; str++)
length++;

return (length);
}
/**
* create_duplicate_string - creates a duplicate of a string
* @source: string to be duplicated
*
* Return: pointer to the duplicated string
*/
char *create_duplicate_string(char *source)
{
char *duplicate;
int length, i;

if (source == NULL)
return (NULL);

length = _strlen(source);

duplicate = malloc(sizeof(char) * (length + 1));
if (duplicate == NULL)
return (NULL);

for (i = 0; source[i] != '\0'; i++)
duplicate[i] = source[i];

duplicate[i] = '\0';

return (duplicate);
}
/**
* find_character - locates a character in a string
* @string: string to be checked
* @character: character to be located
*
* Return: returns a pointer to the first occurrence of the character
* or NULL if the character is not found
*/
char *find_character(char *string, char character)
{
for (; *string != '\0' && *string != character; string++);

if (*string == character)
return (string);
return (NULL);
}
/**
* custom_strncmp - compares two strings up to n bytes
* @str1: compared to str2
* @str2: compared to str1
* @n: number of bytes
*
* Return: difference between str1 and str2
*/
int custom_strncmp(char *str1, char *str2, int n)
{
int result = 0;

while (n > 0 && *str1 && *str2)
{
result = *str1 - *str2;
if (result != 0)
break;
str1++;
str2++;
n--;
}

return (result);
}
