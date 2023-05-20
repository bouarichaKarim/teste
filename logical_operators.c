#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * execute_command - execute a single command within the shell.
 * @command: param command.
 * Return: return exit status integer.
 */

void execute_command(char *command)
{
<<<<<<< HEAD
	char *and_operator = strstr(command, "&&");
	char *or_operator = strstr(command, "||");
=======
    char *and_operator;
    char *or_operator;
    char *next_command;

    and_operator = strstr(command, "&&");
    or_operator = strstr(command, "||");
>>>>>>> 67c1d35f5945a19b178402c7f152549e86827bcc

	if (and_operator != NULL)
	{
		*and_operator = '\0';
		execute_command(command);

<<<<<<< HEAD
		char *next_command = and_operator + 2;

		execute_command(next_command);
	} else if (or_operator != NULL)
	{
		*or_operator = '\0';
		execute_command(command);

		char *next_command = or_operator + 2;

		execute_command(next_command);
	} else
	{
		if (is_builtin_command(command))
			execute_builtin_command(command);
		else
			printf("Command not found: %s\n", command);
	}
=======
        next_command = and_operator + 2;

        execute_command(next_command);
    }
    else if (or_operator != NULL)
    {
        *or_operator = '\0';
        execute_command(command);

        next_command = or_operator + 2;

        execute_command(next_command);
    }
    else
    {
        if (is_builtin_command(command))
            execute_builtin_command(command);
        else
            printf("Command not found: %s\n", command);
    }
>>>>>>> 67c1d35f5945a19b178402c7f152549e86827bcc
}
