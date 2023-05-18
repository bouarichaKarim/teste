#include <unistd.h>
#include <stdio.h>
#include "shell.h"

/**
 * prompt - display the shell prompt.
 * Return: no return.
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}
