#include "shell.h"

/**
 * execute_command_separator - execute single command.
 * @command: command.
 * Return: return status of command.
 */

void execute_command_separator(char *command)
{
	char *separator = strchr(command, ';');

	if (separator != NULL)
	{
		char *next_command = separator + 1;

		*separator = '\0';

		execute_command(command);

		execute_command(next_command);
	} else
	{
		if (is_builtin_command(command))
			execute_builtin_command(command);
		else
			printf("Command not found: %s\n", command);
	}
}
