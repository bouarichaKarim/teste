#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * execute_builtin_command - takes a command and perfoms
 * the corresponding action for the built-in command.
 * @command: param command line.
 * Return: no return.
 */

void execute_builtin_command(char *command)
{
	if (strncmp(command, "cd", 2) == 0)
	{
		char *arg = strtok(command, " ");

		arg = strtok(NULL, " ");
		if (arg == NULL || strcmp(arg, "~") == 0)
		{
			char *home = getenv("HOME");

			if (home == NULL)
			{
				fprintf(stderr, "cd: No home directory\n");
				return;
			}
			if (chdir(home) != 0)
			{
				perror("cd");
			}
		} else if (strcmp(arg, "-") == 0)
		{
			char *previous = getenv("OLDPWD");

			if (previous == NULL)
			{
				fprintf(stderr, "cd: No previous directory\n");
				return;
			}
			if (chdir(previous) != 0)
			{
				perror("cd");
			}
		} else
		{
			if (chdir(arg) != 0)
			{
				perror("cd");
			}
		}
	}
}
