#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * execute_commands_from_file - execute commands from a file
 * in the shell.
 * @filename: name of the file.
 * Return: no return.
 */

void execute_commands_from_file(const char *filename)
{
  char line[BUFFER_SIZE];
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error opening file: %s\n", filename);
		return;
	}

	while (fgets(line, BUFFER_SIZE, file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		execute_command(line);
	}

	fclose(file);
}
