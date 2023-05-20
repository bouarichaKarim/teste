#include "shell.h"

/**
 * parse_arguments_tokenize - Tokenizes a string into arguments.
 * @line: The input string to be tokenized.
 *
 * Return: return an array of strings containing the arguments.
 */

char **parse_arguments_tokenize(char *line)
{
	char **arguments;
	char *token;
	int arg_count = 0;

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		arg_count++;
		token = strtok(NULL, " \t\n");
	}

	arguments = malloc((arg_count + 1) * sizeof(char *));
	if (arguments == NULL)
	{
		perror("Allocation error");
		return (NULL);
	}

	token = strtok(line, " \t\n");
	arg_count = 0;
	while (token != NULL)
	{
		arguments[arg_count] = strdup(token);
		if (arguments[arg_count] == NULL)
		{
			perror("Allocation error");
			free_arguments(arguments);
			return (NULL);
		}
		arg_count++;
		token = strtok(NULL, " \t\n");
	}

	arguments[arg_count] = NULL;
	return (arguments);
}

/**
 * free_arguments_tokenize - Free the memory used by an array of arguments.
 * @arguments: Array of arguments.
 */
void free_arguments_tokenize(char **arguments)
{
	int i;

	if (arguments == NULL)
		return;

	for (i = 0; arguments[i] != NULL; i++)
		free(arguments[i]);

	free(arguments);
}
