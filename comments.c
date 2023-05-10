#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void execute_command(char *command)
{
    // Ignore comments (lines starting with '#')
    if (command[0] == '#')
        return;

    // Execute the command as usual
    if (is_builtin_command(command))
        execute_builtin_command(command);
    else
        printf("Command not found: %s\n", command);
}