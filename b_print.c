#include <unistd.h>
/* Function Definitions */
/**
* Writes a single character to the standard output.
*
* @param c The character to be written.
*/
void b_putchar(char c)
{
char buf[2];
buf[0] = c;
buf[1] = '\0';
write(STDOUT_FILENO, buf, 1);
}
/**
* Writes a null-terminated string to the standard output.
*
* @param s The string to be written.
*/
void b_puts(const char *s)
{
size_t i = 0;
while (s[i] != '\0')
{
b_putchar(s[i]);
i++;
}
}
