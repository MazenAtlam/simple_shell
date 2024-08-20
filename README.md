# Simple Shell

- A shell is a program that executes other programs in response to text commands.
- It provides a command line user interface for Unix-like operating systems.
- The shell is both an interactive command language and a scripting language.

## Install

Write the following commands in your cmd prompt:

1. Clone this repo
```
git clone https://github.com/MazenAtlam/simple_shell.git
```
2. Go to the simple_shell directory
```
cd simple_shell
```
3. Compile the c files
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
4. Run the shell
```
./hsh
```
5. To exit from the shell
```
exit
```

## Commands

This shell behaves like "/bin/sh" in Unix-shell, but does not support all commands.
