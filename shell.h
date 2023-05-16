#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#endif
