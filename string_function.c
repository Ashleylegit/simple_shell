#include "shell_header.h"

/**
* _strcmp - function that compares two strings
* @in1: char
* @in2: char
* Return: (0)
*/
int _strcmp(char *in1, char *in2)
{
	int i = 0, output;

	while (*(in1 + i) == *(in2 + i) && *(in1 + i) != '\0')
		i++;

	output = (*(in1 + i) - *(in2 + i));

	return (output);
}

/**
* _strlen - function that calculates the length of a string
* @s: char
* Return: (0)
*/
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
* _strncmp - function that compares two strings up to n bytes
* @in1: char
* @in2: char
* @n: int
* Return: (in1 - in2)
*/
int _strncmp(char *in1, char *in2, int n)
{
	int i;

	for (i = 0; in1[i] && in2[i] && i < n; i++)
	{
		if (in1[i] != in2[i])
			return (in1[i] - in2[i]);
	}
	return (0);
}

/**
* _strdup - function that duplicates a string
* @s: char
* Return: (0)
*/
char *_strdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* _strchr - function that locates a character in a string
* @s: char
* @c: char
* Return: pointer or NULL
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
