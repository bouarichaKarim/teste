#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_ALIASES 100

typedef struct
{
	char *name;
	char *value;
} Alias;

Alias aliases[MAX_ALIASES];
int num_aliases = 0;

void execute_builtin_command(char *command)
{
	if (strncmp(command, "alias", 5) == 0)
       	{
		char *arg = strtok(command, " ");
		arg = strtok(NULL, " ");

		if (arg == NULL)
		{
			print_aliases();
		}
		else 
		{
			char *name = strtok(arg, "=");
			char *value = strtok(NULL, "=");

			if (value == NULL)
		       	{
				print_alias(name);
			}
			else
		       	{
				define_alias(name, value);
			}
		}
	}
}

void define_alias(char *name, char *value)
{
	if (num_aliases >= MAX_ALIASES)
       	{
		fprintf(stderr, "Cannot define more aliases\n");
		return;
	}

	aliases[num_aliases].name = strdup(name);
	aliases[num_aliases].value = strdup(value);
	num_aliases++;
}

void print_aliases()
{
	for (int i = 0; i < num_aliases; i++)
       	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

void print_alias(char *name)
{
	for (int i = 0; i < num_aliases; i++)
       	{
		if (strcmp(aliases[i].name, name) == 0)
	       	{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
			return;
		}
	}
	fprintf(stderr, "Alias '%s' not found\n", name);
}
