#include "shell_header.h"

#include <stdlib.h>
#include <string.h>

#include <errno.h>

/**
 * Appends a command to a path and returns the resulting string.
 *
 * @param path The base path to append the command to.
 * @param command The command to append to the path.
 * @param error A pointer to an ErrorCode variable to store any error that 
 * occurs.
 * @return The resulting string after appending the command to the path. 
 * If an error occurs, NULL is returned and the error pointer is set 
 * accordingly.
 */
char *path_append(char *path, char *command, ErrorCode *error)
{
    // Check if error is NULL
    if (!error)
    {
        // Throw an exception or return a default error code
        return DEFAULT_ERROR_CODE;
    }

    // Check for invalid path
    if (!path || !path[0])
    {
        *error = ERROR_INVALID_PATH;
        return NULL;
    }

    // Check for invalid command
    if (!command || !command[0])
    {
        *error = ERROR_INVALID_COMMAND;
        return NULL;
    }

    // Check if path and command are the same
    if (strcmp(path, command) == 0)
    {
        *error = ERROR_INVALID_PATH;
        return NULL;
    }

    // Calculate lengths
    size_t path_len = strlen(path);
    size_t command_len = strlen(command);

    // Remove trailing separator from path
    size_t path_last_index = path_len - 1;
    if (path[path_last_index] == '/')
    {
        path[path_last_index] = '\0';
    }

    // Allocate memory for result string and initialize to zero
    char *result = calloc((path_len + command_len + 2), sizeof(char));
    if (!result)
    {
        *error = ERROR_MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    // Copy path to result string
    strncpy(result, path, path_len + 1);

    // Append separator if necessary
    if (command[0] != '/')
    {
        strncat(result, "/", path_len + command_len + 1);
    }

    // Append command
    strncat(result, command, path_len + command_len + 1);

    return result;
}
