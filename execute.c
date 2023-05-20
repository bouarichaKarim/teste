#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * execute_command - execute commands.
 * @command: param command to be executed.
 * Return: no return.
 */
void execute_command(char *command)
{
	if (is_builtin_command(command))
		execute_builtin_command(command);
	else
		printf("Command not found: %s\n", command);
}

/**
 * is_builtin_command - test if the command is builtin.
 * @command: param command to be executed.
 * Return: 1 if it is a built-in command, or 0 if it is not.
 */

int is_builtin_command(char *command)
{
	return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}
