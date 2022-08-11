#include "shell_header.h"

/**
 *mode_function - function that keeps track
 *@m: int
 *Return: nothing
 */
void mode_function(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
