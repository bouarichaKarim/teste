#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * parse_arguments - Tokenizes a string into arguments.
 * @line: The input string to be tokenized.
 *
 * Return: return an array of strings containing the arguments.
 */

char **parse_arguments(char *line)
{
	char **arguments = NULL;
	char *buffer;
	int arg_count = 0;

	buffer = strdup(line);
	arguments = malloc(sizeof(char *) * 2);

	char *token = strtok(buffer, " ");

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

	free(buffer);

	return (arguments);
}

/**
 * free_arguments - Frees the memory allocated for
 * an array of arguments.
 * @arguments: The array of arguments to be freed.
 * Return: no return.
 */


void free_arguments(char **arguments)
{
	int i = 0;

	while (arguments[i] != NULL)
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
