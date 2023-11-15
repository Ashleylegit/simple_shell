#include "shell_header.h"

/**
 * Writes a single character to the standard output.
 *
 * @param c The character to be written.
 * @return The number of characters written.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * Writes a string to the standard output.
 *
 * @param s The string to be written.
 * @return The number of characters written.
 */
int print_s(const char *s)
{
    if (s == NULL)
    {
        return -1; // Return -1 to indicate failure
    }

    fputs(s, stdout);

    return strlen(s); // Return the length of the string
}

