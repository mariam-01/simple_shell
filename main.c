#include "header.h"
/**

main - entry point of the program
This is the main function of the program. It serves as the entry point
and executes a sequence of tasks by calling various functions defined in
separate files. The tasks include accessing a file, changing the current
working directory, closing a file descriptor, closing a directory, executing
a new process, exiting the program, flushing a stream, creating a new process
(forking), freeing allocated memory, retrieving the current working directory,
reading input from a stream, getting the process ID, checking if a file
descriptor refers to a terminal, sending a signal to a process, allocating
memory dynamically, opening a file, and returning 0 to indicate successful
execution.
Return: Always returns 0 to indicate successful execution of the program.
*/
int main()
{
access_task();
chdir_task();
close_task();
closedir_task();
execve_task();
exit_task();
_exit_task();
fflush_task();
fork_task();
free_task();
getcwd_task();
getline_task();
getpid_task();
isatty_task();
kill_task();
malloc_task();
open_task();

return (0);
}
