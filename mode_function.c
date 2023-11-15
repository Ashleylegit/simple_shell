#include "shell_header.h"

/**
 * This function writes a newline character and a prompt symbol to the 
 * standard error file descriptor.
 *
 * @param m - An integer parameter representing the mode value. This 
 * parameter is ignored.
 *
 * @return None.
 */
void mode_function(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
