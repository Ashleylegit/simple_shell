#include "shell_header.h"

/**
 * Writes a single character to the standard output.
 *
 * @param c The character to be written.
 * @return The number of characters written.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * Writes a string to the standard output.
 *
 * @param s The string to be written.
 * @return The number of characters written.
 */
int print_s(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}

