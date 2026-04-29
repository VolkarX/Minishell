# Minishell (mysh)

![Epitech](https://img.shields.io/badge/Epitech-Project-blue)
![C](https://img.shields.io/badge/Language-C-orange)

> **⚠️ WARNING:** This is an Epitech project. It is strictly forbidden to copy, reuse, or plagiarize this code for your own projects. Academic integrity rules apply.

## Description

Minishell (also called `mysh`) is a UNIX command interpreter built in C. It replicates the core functionalities of traditional shells like `bash` or `zsh` by executing system commands, handling environment variables, and supporting basic file redirections and pipes.

## Features

- **Command Execution:** Search and execute commands located in the directories specified by the `PATH` environment variable.
- **Built-ins:** 
  - `cd`: Change the current working directory.
  - `env`: Display the environment variables.
  - `setenv`: Add or modify an environment variable.
  - `unsetenv`: Remove an environment variable.
  - `exit`: Quit the shell (supports numeric exit codes).
- **Control Operators and Redirections:**
  - Pipes (`|`): Connect the output of one command to the input of another.
  - Redirections (`<`, `>`, `>>`): Redirect standard input/output from/to files.
  - Sequences (`;`): Execute multiple commands sequentially on a single line.

## Compilation

The project comes with a `Makefile`. To compile the project, simply run:

```bash
make
```

### Available Make rules:
- `make`: Compiles the executable `mysh`.
- `make clean`: Removes intermediate generated files and object files.
- `make fclean`: Removes the executable and cleans the repository completely.
- `make re`: Performs `fclean` followed by `make`.
- `make valgrind`: Compiles the program with debug flags (`-g3`) for memory leak analysis using Valgrind.

## Usage

Start the shell by running the executable:

```bash
./mysh
```

You will be presented with a prompt where you can enter commands just like in a standard shell:

```bash
$> ls -la
$> echo "Hello World!" > output.txt
$> cat output.txt | grep "Hello"
$> cd /tmp ; ls
```

To exit the shell, type `exit` or press `Ctrl+D` (EOF).

## Project Structure

- `src/`: Contains all the source code of the project.
  - `components/`: Handlers for the different shell functions (cd, exi, pipes, redirections, setenv, etc.).
  - `utils/`: Common utilities and string manipulation functions.
- `include/`: Header files for the project (`my.h`).
- `Makefile`: Compilation instruction file.

## Disclaimer

This repository is for educational purposes only. If you are an Epitech student, do not copy this code, as you risk failing your project and facing disciplinary action for cheating.
