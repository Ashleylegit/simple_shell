#include "shell_header.h"

/**
 * Handles the execution of built-in functions in a shell program.
 *
 * @param command - A pointer to an array of strings representing the command
 * and its arguments.
 * @param line - A pointer to a string representing the entire command line 
 * input.
 * @return Returns 1 if a built-in function is executed, 0 otherwise.
 */
int builtin_handler(char **command, char *line)
{
    // Define the built-in commands
    const char *env = "env";
    const char *exit = "exit";

    // Check if the command matches any of the built-in commands
    if (_strcmp(*command, env) == 0)
    {
        // Call the environment_function and return 1
        environment_function();
        return 1;
    }
    else if (_strcmp(*command, exit) == 0)
    {
        // Call the exit_function with command and line and return 1
        exit_function(command, line);
        return 1;
    }

    // No built-in command matched, return 0
    return 0;
}

