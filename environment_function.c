#include "shell_header.h"

/**
 * Prints out the environment variables.
 *
 * This function prints out each environment variable in the current 
 * environment, with each variable on a new line.
 */
void environment_function(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
