#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

void execute_command(char *command)
{
	if (is_builtin_command(command))
		execute_builtin_command(command);
	else
		printf("Command not found: %s\n", command);
}

int is_builtin_command(char *command)
{
	return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}

void execute_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0)
		exit(0);
	else if (strcmp(command, "env") == 0)
		system("env");
}

/**
*char **parse_arguments()
*{
*   return (NULL);
*}
*
*void free_arguments()
*{
*   
*}
*/
