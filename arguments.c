#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char **parse_arguments(char *line)
{
    char **arguments = NULL;
    char *token;
    int arg_count = 0;

    // Allocate memory for the arguments array
    arguments = malloc(sizeof(char *) * 2); // Start with 2 arguments

    // Tokenize the line based on spaces
    token = strtok(line, " ");
    while (token != NULL) {
        // Allocate memory for each argument
        arguments[arg_count] = malloc(strlen(token) + 1);
        strcpy(arguments[arg_count], token);
        arg_count++;

        // Resize the arguments array if needed
        if (arg_count % 2 == 0) {
            arguments = realloc(arguments, sizeof(char *) * (arg_count + 2));
        }

        token = strtok(NULL, " ");
    }

    // Set the last argument to NULL
    arguments[arg_count] = NULL;

    return arguments;
}

void free_arguments(char **arguments)
{
    int i = 0;
    while (arguments[i] != NULL) {
        free(arguments[i]);
        i++;
    }
    free(arguments);
}