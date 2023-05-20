#include "shell.h"

/**
 * execute_command_comments - execute command, and handles both
 * regular commands and comments.
 * @command: param command line.
 * Return: no return.
 */

void execute_command_comments(char *command)
{
	if (command[0] == '#')
		return;

	if (is_builtin_command(command))
		execute_builtin_command_variables(command);
	else
		printf("Command not found: %s\n", command);
}
