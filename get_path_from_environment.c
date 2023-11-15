#include "shell_header.h"

/**
 * Retrieves the value of the PATH environment variable.
 *
 * This function iterates through the environment variables until it 
 * finds the PATH variable,  * extracts the path from it, and returns it.
 *
 * @return A pointer to the path string if the PATH environment variable 
 * is found, otherwise NULL.
 */
char *get_path_from_environment(void)
{
    // Iterate through the environment variables
    for (char **env = environ; *env != NULL; env++)
    {
        // Check if the current variable is the PATH variable
        if (strncmp(*env, "PATH=", 5) == 0)
        {
            // Extract the path from the variable
            char *path = *env + 5;
            return path;
        }
    }
    return NULL;
}

