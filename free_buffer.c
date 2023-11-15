#include "shell_header.h"

/**
* Frees the memory allocated for a buffer of strings.
*
* @param buf A double pointer to a buffer of strings (char **).
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
