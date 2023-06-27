#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * main - The entry point of the shell program
 *
 * Return: 0 on successful execution
 */
int main(void)
{
shell();
return (0);
}
