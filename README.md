# Simple Shell  
**“The Gates of Shell” – A UNIX command line interpreter built in C.**  

This project was developed as part of the Holberton School curriculum to understand how a shell works under the hood.  

---

## 📖 Table of Contents  
- [About the Project](#-about-the-project)  
- [Learning Objectives](#-learning-objectives)  
- [Features](#-features)  
- [Requirements](#-requirements)  
- [Compilation](#-compilation)  
- [Usage](#-usage)  
- [Examples](#-examples)  
- [Built-in Commands](#-built-in-commands)  
- [Project Structure](#-project-structure)  
- [Authors](#-authors)  

---

## 🔎 About the Project  
The **simple_shell** project is a recreation of a basic UNIX shell.  
It executes commands read from standard input (interactive or non-interactive mode), manages processes, uses the environment, and implements some built-ins.  

The goal is to gain a deeper understanding of system calls, process creation, and program execution in Linux.  

---

## 🎯 Learning Objectives  
By completing this project, we learned and can explain:  

- Who designed and implemented the original UNIX operating system  
- Who wrote the first version of the UNIX shell  
- Who invented the B programming language (direct predecessor to C)  
- Who is Ken Thompson  
- How a shell works internally  
- What a PID and a PPID are  
- How to manipulate the environment of the current process  
- The difference between a function and a system call  
- How to create processes with `fork()`  
- The three valid prototypes of `main` in C  
- How the shell uses the `PATH` to locate programs  
- How to execute another program with `execve()`  
- How to wait for processes with `wait()`  
- What EOF (“end-of-file”) means  

---

## ⚙️ Features  
Our shell supports:  

- Displaying a prompt and waiting for user input  
- Executing commands entered by the user  
- Handling command arguments  
- Using the environment `PATH` to locate executables  
- Forking only if the command exists  
- Handling errors and printing messages similar to `/bin/sh`  
- Handling the end of file (Ctrl+D) gracefully  

**Built-ins implemented:**  
- `exit` → exit the shell  
- `env` → print the environment variables  

---

## 📋 Requirements  
- Allowed editors: `vi`, `vim`, `emacs`  
- Compilation on **Ubuntu 20.04 LTS** with:  

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

---

## Authors 

- Sokol Gjeka