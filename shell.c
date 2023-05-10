#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024

int main(void)
{
    char line[BUFFER_SIZE];

    while (1) {
        prompt();
        if (fgets(line, BUFFER_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }

        line[strcspn(line, "\n")] = '\0'; // Remove trailing newline

        execute_command(line);
    }

    return 0;
}