#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * execute_command - execute a single command within the shell.
 * @command: param command.
 * Return: return exit status integer.
 */

void execute_command(char *command)
{
    char *and_operator = strstr(command, "&&");
    char *or_operator = strstr(command, "||");

    if (and_operator != NULL)
    {
        *and_operator = '\0';
        execute_command(command);

        char *next_command = and_operator + 2;

        execute_command(next_command);
    } else if (or_operator != NULL)
    {
        *or_operator = '\0';
        execute_command(command);

        char *next_command = or_operator + 2;

        execute_command(next_command);
    } else
    {
        if (is_builtin_command(command))
            execute_builtin_command(command);
        else
            printf("Command not found: %s\n", command);
    }
}
