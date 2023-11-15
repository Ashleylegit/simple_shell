#include "shell_header.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Tokenizes a string based on a delimiter and returns an array of tokens.
 *
 * @param line The string to be tokenized.
 * @return An array of strings where each element represents a token from 
 * the input string. The last element is set to NULL to indicate the end 
 * of the array.
 */
char **token_function(char *line)
{
    if (line == NULL)
        return NULL;

    char *delim = " :\t\r\n";
    char **tokens = NULL;
    size_t index = 0;
    bool flag = false;
    char *saveptr;

    size_t estimated_tokens = strlen(line) / 2;
    tokens = malloc((estimated_tokens + 1) * sizeof(char *));
    if (tokens == NULL)
        return NULL;

    char *buf = strdup(line);
    if (buf == NULL)
    {
        free(tokens);
        return NULL;
    }

    char *bufp = buf;

    while (*bufp)
    {
        char *result = strpbrk(bufp, delim);
        if (result != NULL && !flag)
        {
            size_t new_size = (index + 2) * sizeof(char *);
            if (new_size > (estimated_tokens + 1) * sizeof(char *))
            {
                char **new_tokens = realloc(tokens, new_size);
                if (new_tokens == NULL)
                {
                    for (size_t i = 0; i < index; i++)
                        free(tokens[i]);
                    free(tokens);
                    free(buf);
                    return NULL;
                }
                tokens = new_tokens;
            }
            flag = true;
        }
        else if (result == NULL && flag)
            flag = false;
        bufp++;
    }

    char *token = strtok_r(buf, delim, &saveptr);
    while (token)
    {
        tokens[index] = strdup(token);
        if (tokens[index] == NULL)
        {
            for (size_t i = 0; i < index; i++)
                free(tokens[i]);
            free(tokens);
            free(buf);
            return NULL;
        }
        token = strtok_r(NULL, delim, &saveptr);
        index++;
    }
    tokens[index] = NULL;
    free(buf);
    return tokens;
}
