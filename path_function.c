#include "shell_header.h"

/**
 * It processes an array of strings representing paths, a command string 
 * to append to each path, and an ErrorCode variable; validates inputs, 
 * iterates through each path, appends the command, and returns the path 
 * if it corresponds to an executable file, logging errors and returning 
 * a message if no valid path is found.
 *
 * path: an array of strings representing different paths
 * command: a string representing the command to be appended to each path
 * error: a pointer to an ErrorCode variable to store error information
 *
 * returns: a pointer or NULL
 */
char *path_function(char **path, char *command, ErrorCode *error)
{
    if (path == NULL || command == NULL)
        return NULL;

    char *output;

    for (int i = 0; path[i]; i++)
    {
        output = path_append(path[i], command, error);
        if (output == NULL)
        {
            log_error("Failed to append path: %s", path[i]);
            goto cleanup;
        }

        struct stat file_stat;
        if (stat(output, &file_stat) == -1)
        {
            log_error("Failed to get file stat: %s", output);
            goto cleanup;
        }

        if (S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR))
        {
            return output;
        }

        free(output);
    }

    return "Error: No valid path found for command";

cleanup:
    free(output);
    return NULL;
}
