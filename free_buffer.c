#include "shell_header.h"

/**
* free_buffer - function that frees the buffers
* @buf: char
* Return: (0)
*/
void free_buffer(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
