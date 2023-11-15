$$ Contributors $$
= Ashley Baker | https://github.com/ashleylegit

$$ Description $$
This project is a simulation of the Thompson shell (https://en.wikipedia.org/wiki/Thompson_shell) written entirely in C. It was built and tested on Ubuntu 20.04 LTS operating system.

This project was designed by Julien Barbier with the intention to challenge a lot about everything that can be learned about the C programming language:
- Basics of programming
- Basics of C
- Basics of thinking like an engineer
- Group work
- Learning how to learn

# Simple Shell in C

This project is a simple implementation of a shell in the C programming language. The shell provides a basic command-line interface, handling user input, parsing commands, and executing processes. This README file outlines the foundational aspects of building this simple shell.

## Table of Contents
1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
   - [Prerequisites](#prerequisites)
   - [Compilation](#compilation)
3. [Features](#features)
   - [User Input](#user-input)
   - [Command Parsing](#command-parsing)
   - [Process Execution](#process-execution)
   - [Input Redirection](#input-redirection)
   - [Piping](#piping)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

This simple shell project aims to provide a foundational understanding of building a command-line interface in C. The implementation covers key concepts such as handling user input, parsing commands, and executing processes.

## Getting Started

### Prerequisites

To run the simple shell, ensure that you have the following prerequisites installed:

- C compiler (e.g., GCC)

### Compilation

Compile the source code using the provided Makefile
This will generate the executable `simple_shell`.


## Features

### User Input

The shell accepts user input through the command-line interface. It prompts the user for commands and processes them accordingly.

### Command Parsing

User commands are parsed to extract individual components, allowing for the identification of executable programs and their arguments.

### Process Execution

The shell can execute processes using system calls such as `fork` and `exec`. It handles both foreground and background processes.

### Input Redirection

Support for input redirection is included, allowing users to redirect input from a file to a command.

### Piping

The shell supports basic piping, enabling the output of one command to serve as the input for another.

## Usage

To use the simple shell, run the executable: ./simple_shell
You will be prompted with a command-line interface where you can enter commands. Explore various features, such as input redirection and piping.

## Contributing

Contributions are welcome! If you'd like to contribute to the development of this simple shell, please follow the [contributing guidelines](CONTRIBUTING.md).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

