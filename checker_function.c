#include "shell_header.h"

/**
 * Checks if the command is a built-in function or starts with a forward 
 * slash.
 * 
 * @param cmd - A pointer to a pointer to a char, representing the command 
 * and its arguments.
 * @param buf - A pointer to a char, representing the buffer.
 * @return Returns 1 if the command is a built-in function or starts with 
 * a forward slash, otherwise returns 0.
 */
int checker_function(char **cmd, char *buf)
{
    // Check if the command is a built-in function
    if (builtin_handler(cmd, buf))
        return 1;
    
    // Check if the command starts with a forward slash
    if (cmd[0][0] == '/')
    {
        run_command(cmd[0], cmd);
        return 1;
    }
    
    // Command is neither a built-in function nor starts with a forward slash
    return 0;
}
