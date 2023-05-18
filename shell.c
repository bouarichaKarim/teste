#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * main - Entry point for the shell program.
 * Return: Always 0.
 */

int main(void)
{
	char line[BUFFER_SIZE];

	while (1)
	{
		prompt();
		if (fgets(line, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		execute_command(line);
	}

	return (0);
}
