#include <stdio.h>
#include "shell.h"

void prompt(void)
{
    if (isatty(STDIN_FILENO))
        printf("$ ");
}