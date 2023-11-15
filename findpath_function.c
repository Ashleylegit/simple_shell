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
char *findpath_function(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
