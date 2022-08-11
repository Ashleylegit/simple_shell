#include "shell_header.h"
/**
 *checker_function - function that checks to see weather its a built in function
 *@cmd: char
 *@buf: char 
 *Return: 1 or 0
 */
int checker_function(char **cmd, char *buf)
{
	if (builtin_handler(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		run_command(cmd[0], cmd);
		return (1);
	}
	return (0);
}
