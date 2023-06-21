#include "shell.h"


/**
 * _strlen - returns string length
 * @s: string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
return (strlen(s));
}


/**
 * _strncpy - copies a string
 *@dest: pointer
 *@src: pointer
 *@n: number of bytes
 * Return: pointer to the resulting string
 */
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}
for (j = i; j < n; j++)
{
dest[j] = '\0';
}
return (dest);
}

/**
 * _strcmp - compares two strings
 *@s2: pointer
 *@s1: pointer
 * Return: returns a value
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s1 == *s2)
{
s1++;
s2++;
}
return (*s1 - *s2);
}

