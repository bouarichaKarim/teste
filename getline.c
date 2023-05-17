#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * get_input_line - reads line and stores it in the buffer.
 * Return: return -1 if error
 */

char *get_input_line(void)
{
	static char line[BUFFER_SIZE];
	static int line_pos;
	static int line_len;
	static int read_more = 1;

	if (read_more)
	{
		line_len = read(STDIN_FILENO, line, BUFFER_SIZE);
		if (line_len == 0)
			return (NULL);
		line_pos = 0;
		read_more = 0;
	}

	if (line[line_pos] == '\n')
	{
		line[line_pos] = '\0';
		line_pos = 0;
		read_more = 1;
		return (line);
	}

	char *cmd = &line[line_pos];

	line_pos++;
	return (cmd);
}
