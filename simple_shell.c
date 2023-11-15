#include "shell_header.h"

#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <winsock.h>
#include <unistd.h>

struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, void *);
    int sa_flags;
    void (*sa_restorer)(void);
};

/**
 * Main function of the shell program.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings representing the command line arguments.
 * @param envp An array of strings representing the environment variables.
 * @param error A pointer to an ErrorCode variable.
 * @return 0 if the program executed successfully.
 */
int main(int argc, char **argv, char *envp[], ErrorCode *error)
{
    // Initialize variables
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t linesize = 0;
    char **command = NULL, **paths = NULL;
    fd_set readfds;

    // Ignore unused variables
    (void)envp, (void)argv;

    // Check if there are command line arguments
    if (argc < 1)
        return (-1);

    // Set up signal handler for SIGINT
    struct sigaction sa = {0};
    if (mode_function != NULL) {
        sa.sa_handler = mode_function;
    } else {
        sa.sa_handler = SIG_DFL;
    }
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
    }
    
    int running = 1;
    while (running)
    {
        // Prompt the user for input
        prompt_function();

        // Use select to check if there is input available
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;
        int ready = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);
        if (ready == -1) {
            perror("select");
            break;
        }
        if (ready > 0 && FD_ISSET(STDIN_FILENO, &readfds)) {
            // Read the input line
            linesize = getline(&line, &bufsize, stdin);
            if (linesize < 0)
                break;
        }

        // Tokenize the input line
        command = token_function(line);
        if (command == NULL || *command == NULL || **command == '\0')
            continue;

        // Check for errors in the command
        if (checker_function(command, line))
            continue;

        // Find the path of the command
        char* path = findpath_function();
        paths = token_function(path);
        char* pathcommand = path_function(paths, command[0], *error);
        if (!pathcommand)
            handle_error("Failed to find path command", *error);
        else
            run_command(pathcommand, command);
        
        // Free allocated memory
        free(command);
        free(paths);
        free(pathcommand);
    }

    // Print newline if necessary
    if (linesize < 0 && flags.interactive)
        putchar('\n');

    // Free allocated memory
    free(line);

    return (0);
}

