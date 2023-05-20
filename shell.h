#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
extern int exit_status;
extern char **environ;

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
void execute_command_comments(char *command);
void execute_command_logical_operators(char *command);
void execute_command_separator(char *command);
void execute_command_setenv_unsetenv(char *command)
int is_builtin_command(char *command);
void execute_builtin_command(char *command);
char **parse_arguments_tokenize(char *line);
void free_arguments_tokenize(char **arguments);
char **parse_arguments_arguments(char *line);
void free_arguments_arguments(char **arguments);
char *create_command_path(char *command, char *directory);
char *get_command_path(char *command);
void execute_commands_from_file(const char *filename);
char *get_input_line(void);
#endif
