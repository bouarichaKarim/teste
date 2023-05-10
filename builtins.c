#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void execute_builtin_command(char *command)
{
    if (strcmp(command, "exit") == 0) {
        exit(0);
    }
    else if (strcmp(command, "env") == 0) {
        char **env = environ;
        while (*env) {
            printf("%s\n", *env);
            env++;
        }
    }
    // Add more built-in commands here...
}