#include "shell.h"

/**
 * split_line - splits a line into tokens
 * @line: input string
 *
 * Return: NULL-terminated array of strings
 */
char **split_line(char *line)
{
	size_t bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *tok;

	if (!tokens)
		return (NULL);

	tok = strtok(line, " \t\r\n");
	while (tok)
	{
		if (i + 1 >= bufsize)
		{
			bufsize *= 2;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				return (NULL);
		}
		tokens[i++] = tok;
		tok = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_argv - frees a token array allocated by split_line
 * @argv: token array
 */
void free_argv(char **argv)
{
	free(argv);
}
