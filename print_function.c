#include "shell_header.h"

/**
* _putchar - function that writes the character c to stdout
* @c: char
* Return: (-1 or 1)
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_s - function that prints a string
* @s: char
* Return: (i)
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
