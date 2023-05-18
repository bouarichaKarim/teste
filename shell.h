#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
extern int exit_status;

/**
 * struct alias_s - Structure for storing alias information.
 * @name: Name of the alias.
 * @value: Value of the alias.
 * @next: Pointer to the next alias in the linked list.
 */

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

void print_alias(alias_t *alias_list);
int add_alias(alias_t **alias_list, const char *name, const char *value);
char *find_alias(alias_t *alias_list, const char *name);

void prompt(void);
void execute_command(char *command);
int is_builtin_command(char *command);
void execute_builtin_command(char *command);
char **parse_arguments(char *line);
void free_arguments(char **arguments);
char *create_command_path(char *command, char *directory);
#endif
