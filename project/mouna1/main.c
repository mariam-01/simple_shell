#include "shell.h"
int main(void)
{
char input[MAX_INPUT_LENGTH];  /*Declare the 'input' variable here*/

while (1)
{
displayPrompt();

if (!getUserInput(input))
{
break;
}

/* Check if the command exists in the PATH */
if (access(input, X_OK) == 0)
{
runCommand(input);  /* Updated function name*/
}
else
{
executeCommand(input);  /*Original function name*/
}
}

return 0;
}
