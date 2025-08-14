Simple Shell
“The Gates of Shell” – A UNIX command line interpreter built in C.
This project was developed as part of the Holberton School curriculum to understand how a shell works under the hood.

📖 Table of Contents
About the Project

Learning Objectives

Features

Requirements

Compilation

Usage

Examples

Built-in Commands

Project Structure

Authors

🔎 About the Project
The simple_shell project is a recreation of a basic UNIX shell.
It executes commands read from standard input (interactive or non-interactive mode), manages processes, uses the environment, and implements some built-ins.
The goal is to gain a deeper understanding of system calls, process creation, and program execution in Linux.

🎯 Learning Objectives
By completing this project, we learned and can explain:

Who designed and implemented the original UNIX operating system

Who wrote the first version of the UNIX shell

Who invented the B programming language (direct predecessor to C)

Who is Ken Thompson

How a shell works internally

What a PID and a PPID are

How to manipulate the environment of the current process

The difference between a function and a system call

How to create processes with fork()

The three valid prototypes of main in C

How the shell uses the PATH to locate programs

How to execute another program with execve()

How to wait for processes with wait()

What EOF (“end-of-file”) means

⚙️ Features
Our shell supports:

Displaying a prompt and waiting for user input

Executing commands entered by the user

Handling command arguments

Using the environment PATH to locate executables

Forking only if the command exists

Handling errors and printing messages similar to /bin/sh

Handling the end of file (Ctrl+D) gracefully

Built-ins:

exit – exit the shell

env – print the environment variables

📋 Requirements
Allowed editors: vi, vim, emacs

Compilation on Ubuntu 20.04 LTS with:

bash
Copy
Edit
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Code must follow the Betty style

No memory leaks

Maximum of 5 functions per file

Header files must be include guarded

Only allowed to use system calls when needed

🛠 Compilation
Compile with:

bash
Copy
Edit
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
💻 Usage
Interactive mode:
bash
Copy
Edit
$ ./hsh
($) /bin/ls
file1.c  file2.c  hsh
($) exit
$
Non-interactive mode:
bash
Copy
Edit
$ echo "/bin/ls" | ./hsh
file1.c  file2.c  hsh
📂 Examples
Error handling:

bash
Copy
Edit
$ ./hsh
($) qwerty
./hsh: 1: qwerty: not found
($)
Using PATH:

bash
Copy
Edit
$ ./hsh
($) ls -l /tmp
total 0
-rw------- 1 user user 0 Aug 14 12:00 tmpfile
($)
🔧 Built-in Commands
exit → exits the shell

env → prints the current environment

📑 Project Structure
css
Copy
Edit
.
├── AUTHORS
├── README.md
├── man_1_simple_shell
├── shell.h
├── main.c
├── execute.c
├── path_utils.c
├── builtins.c
├── prompt.c
└── ...
👥 Authors
Project done by:

Sokol Gjeka
