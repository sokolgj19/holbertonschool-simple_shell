#include "shell.h"

/**
 * handle_exit - handles the "exit" builtin
 * @args: argument vector
 * @line: input line
 * @last_status: last command status
 */
void handle_exit(char **args, char *line, int last_status)
{
	free_argv(args);
	free(line);
	exit(last_status);
}

/**
 * handle_env - handles the "env" builtin
 */
void handle_env(void)
{
	int i;

	for (i = 0; environ && environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * main_loop - runs the main shell loop
 * @line: input buffer
 * @n: buffer size
 * @argv: program arguments
 * @last_status: last command status pointer
 * @interactive: interactive mode flag
 */
void main_loop(char *line, size_t n, char **argv,
	       int *last_status, int interactive)
{
	ssize_t r;
	char **args;

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "($) ", 4);

		r = getline(&line, &n, stdin);
		if (r == -1)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = split_line(line);
		if (!args || !args[0])
		{
			free_argv(args);
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
			handle_exit(args, line, *last_status);
		else if (strcmp(args[0], "env") == 0)
			handle_env();
		else
			execute_command(args, environ,
				argv[0] ? argv[0] : "hsh", last_status);

		free_argv(args);
	}
}

/**
 * main - entry point of shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: last status
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t n = 0;
	int last_status = 0;
	int interactive = isatty(STDIN_FILENO);

	(void)argc;

	main_loop(line, n, argv, &last_status, interactive);

	free(line);
	return (last_status);
}
