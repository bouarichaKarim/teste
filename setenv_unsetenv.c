#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void execute_command(char *command)
{
    // Handle setenv command
    if (strncmp(command, "setenv", 6) == 0) {
        char *variable = strtok(command, " ");
        char *value = strtok(NULL, " ");

        if (variable != NULL && value != NULL) {
            // Set the environment variable using setenv function
            setenv(variable, value, 1);
        } else {
            fprintf(stderr, "Invalid setenv command\n");
        }
    }
    // Handle unsetenv command
    else if (strncmp(command, "unsetenv", 8) == 0) {
        char *variable = strtok(command, " ");
        if (variable != NULL) {
            // Unset the environment variable using unsetenv function
            unsetenv(variable);
        } else {
            fprintf(stderr, "Invalid unsetenv command\n");
        }
    }
    // Not a setenv or unsetenv command, execute the command as usual
    else {
        if (is_builtin_command(command))
            execute_builtin_command(command);
        else
            printf("Command not found: %s\n", command);
    }
}