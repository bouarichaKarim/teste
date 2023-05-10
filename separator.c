#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void execute_command(char *command)
{
    // Check if the command contains a separator ;
    char *separator = strchr(command, ';');
    if (separator != NULL) {
        char *next_command = separator + 1;
        *separator = '\0'; // Replace ; with null terminator

        execute_command(command); // Execute the first command

        // Recursively execute the next command
        execute_command(next_command);
    } else {
        // No separator, execute the command as usual
        if (is_builtin_command(command))
            execute_builtin_command(command);
        else
            printf("Command not found: %s\n", command);
    }
}