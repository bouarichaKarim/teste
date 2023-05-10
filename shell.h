#ifndef SHELL_H
#define SHELL_H

/* Function prototypes */
void prompt(void);
void execute_command(char *command);
int is_builtin_command(char *command);
void execute_builtin_command(char *command);
char **parse_arguments(char *line);
void free_arguments(char **arguments);

#endif /* SHELL_H */