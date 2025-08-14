#include "shell.h"

/**
 * split_line - Splits a line into an array of tokens
 * @line: The input line to tokenize
 *
 * Return: Pointer to an array of tokens, or NULL on failure
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
 * free_argv - Frees memory allocated for argument vector
 * @argv: Pointer to the array of arguments
 */
void free_argv(char **argv)
{
	free(argv);
}
