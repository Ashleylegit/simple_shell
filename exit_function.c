#include "shell_header.h"

/**
 * This function takes in two parameters: 'command' (a pointer to a pointer 
 * to char) and 'line' (a pointer to char). It is responsible for freeing 
 * the memory allocated for 'line' and 'command' and then exiting the program 
 * with a success status.
 *
 * @param command A pointer to a pointer to char representing the command 
 * to be executed.
 * @param line A pointer to char representing the input line.
 *
 * @return None.
 */
void exit_function(char **command, char *line)
{
  // Free memory allocated for line if it is not NULL
  if (line)
  {
    free(line);
  }
  
  // Free memory allocated for command if it is not NULL
  if (command)
  {
    free_buffer(command);
  }
  
  // Exit the program with a success status
  exit(EXIT_SUCCESS);
}
