#include "shell.h"

/**
 * execute_command - Executes the setenv or unsetenv command.
 * @command: param of command.
 * Return: no return.
 */

void execute_command_setenv_unsetenv(char *command)
{
	if (strncmp(command, "setenv", 6) == 0)
	{
		char *variable = strtok(command, " ");
		char *value = strtok(NULL, " ");

		if (variable != NULL && value != NULL)
		{
			setenv(variable, value, 1);
		} else
		{
			fprintf(stderr, "Invalid setenv command\n");
		}
	}
	else if (strncmp(command, "unsetenv", 8) == 0)
	{
		char *variable = strtok(command, " ");

		if (variable != NULL)
		{
			unsetenv(variable);
		} else
		{
			fprintf(stderr, "Invalid unsetenv command\n");
		}
	}
	else
	{
		if (is_builtin_command(command))
			execute_builtin_command(command);
		else
			printf("Command not found: %s\n", command);
	}
}
