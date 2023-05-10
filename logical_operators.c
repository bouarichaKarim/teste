#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void execute_command(char *command)
{
    // Check if the command contains the logical operators && or ||
    char *and_operator = strstr(command, "&&");
    char *or_operator = strstr(command, "||");

    if (and_operator != NULL) {
        // Execute the first command before &&
        *and_operator = '\0'; // Replace && with null terminator
        execute_command(command);

        // Execute the second command after &&
        char *next_command = and_operator + 2;
        execute_command(next_command);
    } else if (or_operator != NULL) {
        // Execute the first command before ||
        *or_operator = '\0'; // Replace || with null terminator
        execute_command(command);

        // Execute the second command after ||
        char *next_command = or_operator + 2;
        execute_command(next_command);
    } else {
        // No logical operator, execute the command as usual
        if (is_builtin_command(command))
            execute_builtin_command(command);
        else
            printf("Command not found: %s\n", command);
    }
}