#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

extern int exit_status;
void execute_builtin_command(char *command)
{
    if (command[0] == '$') {
        char *variable = command + 1; // Skip "$" prefix

        if (strcmp(variable, "?") == 0) {
            printf("%d\n", exit_status);
        }
        else if (strcmp(variable, "$") == 0) {
            printf("%d\n", getpid());
        }
        else {
            char *value = getenv(variable);
            if (value != NULL) {
                printf("%s\n", value);
            }
            else {
                fprintf(stderr, "Variable %s not found\n", variable);
            }
        }
    }
}
