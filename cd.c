#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void execute_builtin_command(char *command)
{
    if (strncmp(command, "cd", 2) == 0) {
        char *arg = strtok(command, " ");
        arg = strtok(NULL, " ");
        
        if (arg == NULL || strcmp(arg, "~") == 0) {
            // No argument or argument is "~" (home directory)
            char *home = getenv("HOME");
            if (home == NULL) {
                fprintf(stderr, "cd: No home directory\n");
                return;
            }
            if (chdir(home) != 0) {
                perror("cd");
            }
        } else if (strcmp(arg, "-") == 0) {
            // Argument is "-"
            char *previous = getenv("OLDPWD");
            if (previous == NULL) {
                fprintf(stderr, "cd: No previous directory\n");
                return;
            }
            if (chdir(previous) != 0) {
                perror("cd");
            }
        } else {
            // Change to the specified directory
            if (chdir(arg) != 0) {
                perror("cd");
            }
        }
    }
}