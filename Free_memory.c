#include "shell.h"
/**
* deallocate_buffers - frees buffers
* @buffers: buffer to be freed
*
* Returns: None
*/
void deallocate_buffers(char **buffers)
{
int i = 0;
if (buffers == NULL)
return;

for (i = 0; buffers[i] != NULL; i++)
{
free(buffers[i]);
}

free(buffers);
}
