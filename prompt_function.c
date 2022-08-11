#include "shell_header.h"

/**
* prompt_function - function that prompts the user for an input
* Return: no return
*/
void prompt_function(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$(^_^)$ ", 8);
}
