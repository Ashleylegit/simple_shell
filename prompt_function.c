#include "shell_header.h"

#include <unistd.h>

/**
 * Displays a prompt on the command line if the standard input and standard 
 * output are connected to a terminal.
 */
void prompt_function(void)
{
    if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
    {
        write(STDERR_FILENO, "$(^_^)$ ", 8);
    }
}
