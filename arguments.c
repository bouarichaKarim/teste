#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"


/**
 * parse_arguments - takes the command line and parses it
 * into an array of arguments.
 * @line: param command line.
 * Return: return array of arguments.
 */

char **parse_arguments(char *line)
{
	char **arguments = NULL;
	char *token;
	int arg_count = 0;

	arguments = malloc(sizeof(char *) * 2);

	token = strtok(line, " ");
	while (token != NULL)
	{

		arguments[arg_count] = malloc(strlen(token) + 1);
		strcpy(arguments[arg_count], token);
		arg_count++;


		if (arg_count % 2 == 0)
		{
			arguments = realloc(arguments, sizeof(char *) * (arg_count + 2));
		}

		token = strtok(NULL, " ");
	}

	arguments[arg_count] = NULL;

	return (arguments);
}

/**
 * free_arguments - frees the memory allocated for
 * the array of arguments.
 * @arguments: param of array of arguments.
 * Return: no return.
 */

void free_arguments(char **arguments)
{
	int i = 0
		;
	while (arguments[i] != NULL)
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
