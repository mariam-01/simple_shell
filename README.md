# Simple Shell Project

This is a simple UNIX command line interpreter, developed as part of a project. The shell allows users to execute basic commands and provides some built-in functionality.

## Requirements

- The shell is developed and compiled on Ubuntu 20.04 LTS using gcc.
- All files are compiled with the options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- The shell follows the Betty style for code formatting and is checked using `betty-style.pl` and `betty-doc.pl`.
- Header files are include guarded.
- System calls are used when necessary.
- The shell should not have any memory leaks.
- The shell should have a README.md file and an AUTHORS file.

## Features

- Display a prompt and wait for the user to enter a command.
- Execute commands with arguments.
- Handle errors for invalid commands or executables not found.
- Handle the "end of file" condition (Ctrl+D) to exit the shell.
- Implement the built-in commands `exit` and `env`.
- Pass the environment variables to the executed commands.
- Handle the PATH to find the executables.

## Usage

1. Compile the shell using the provided compilation command.
2. Run the shell by executing the compiled binary file.
3. Enter commands at the prompt and press Enter to execute them.
4. Use the built-in command `exit` to exit the shell.
5. Use the built-in command `env` to print the current environment.

## Files

- `main.c`: Contains the main function and entry point of the shell.
- `shell.c`: Implements the core functionality of the shell.
- `utils.c`: Contains utility functions used in the shell.
- `main.h`: Header file with function declarations used in the shell.
- `README.md`: This file, providing information about the project.
- `AUTHORS`: File listing the contributors to the project.

## Compilation

To compile the shell, use the following command:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
