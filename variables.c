#include "shell.h"

/**
 * execute_builtin_command_variables - Executes a built-in command.
 * @command: The command to execute.
 *
 * Return: No return.
 */

void execute_builtin_command_variables(char *command)
{
	if (command[0] == '$')
	{
		char *variable = command + 1;

		if (strcmp(variable, "?") == 0)
		{
			printf("%d\n", exit_status);
		}
		else if (strcmp(variable, "$") == 0)
		{
			printf("%d\n", getpid());
		}
		else
		{
			char *value = getenv(variable);

			if (value != NULL)
			{
				printf("%s\n", value);
			}
			else
			{
				fprintf(stderr, "Variable %s not found\n", variable);
			}
		}
	}
}
