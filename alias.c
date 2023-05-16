#include "shell.h"

/**
 * print_alias - Print the aliases stored in the alias list
 * @alias_list: The alias list
 */
void print_alias(alias_t *alias_list)
{
	alias_t *alias;

	alias = alias_list;
	while (alias != NULL)
	{
		printf("%s='%s'\n", alias->name, alias->value);
		alias = alias->next;
	}
}

/**
 * add_alias - Add an alias to the alias list
 * @alias_list: The alias list
 * @name: The name of the alias
 * @value: The value of the alias
 *
 * Return: 0 on success, -1 on failure
 */
int add_alias(alias_t **alias_list, const char *name, const char *value)
{
	alias_t *new_alias;

	new_alias = malloc(sizeof(alias_t));
	if (new_alias == NULL)
	{
		perror("malloc");
		return -1;
	}

	new_alias->name = strdup(name);
	if (new_alias->name == NULL)
	{
		perror("strdup");
		free(new_alias);
		return -1;
	}

	new_alias->value = strdup(value);
	if (new_alias->value == NULL)
	{
		perror("strdup");
		free(new_alias->name);
		free(new_alias);
		return -1;
	}

	new_alias->next = *alias_list;
	*alias_list = new_alias;

	return 0;
}

/**
 * find_alias - Find an alias in the alias list
 * @alias_list: The alias list
 * @name: The name of the alias to find
 *
 * Return: The value of the alias if found, NULL otherwise
 */
char *find_alias(alias_t *alias_list, const char *name)
{
	alias_t *alias;

	alias = alias_list;
	while (alias != NULL)
	{
		if (_strcmp(alias->name, name) == 0)
			return alias->value;
		alias = alias->next;
	}

	return NULL;
}
