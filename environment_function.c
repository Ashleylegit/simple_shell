#include "shell_header.h"

/**
 * Prints out the environment variables.
 *
 * This function prints out each environment variable in the current 
 * environment, with each variable on a new line.
 */
void environment_function(void)
{
    char **env = environ;

    for (int x = 0; env[x]; x++)
    {
        printf("%s\n", env[x]);
    }
}

