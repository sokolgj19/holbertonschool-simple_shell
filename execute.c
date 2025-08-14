#include "shell.h"

/**
 * execute_command - executes a command by forking a child process
 * @argv: argument vector for the command
 * @env: environment variables
 * @progname: name of the shell program (for error messages)
 * @last_status: pointer to store the last exit status
 *
 * Return: Always 0. The result of the command is stored in *last_status.
 *
 * Description:
 * - Checks if the command exists (resolve_command).
 * - If it does not exist, prints an error to stderr and sets status = 127.
 * - If it exists, forks and execves. Updates *last_status accordingly.
 */
int execute_command(char **argv, char **env, const char *progname,
		    int *last_status)
{
	pid_t pid;
	int status = 0;
	char *full = resolve_command(argv[0], env);

	if (!full)
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n",
			progname, argv[0]);
		*last_status = 127;
		return (0);
	}

	pid = fork();
	if (pid == -1)
	{
		perror(progname);
		free(full);
		*last_status = 1;
		return (0);
	}

	if (pid == 0)
	{
		execve(full, argv, env);
		perror(progname);
		_exit(126);
	}

	free(full);
	if (waitpid(pid, &status, 0) == -1)
	{
		perror(progname);
		*last_status = 1;
		return (0);
	}

	if (WIFEXITED(status))
		*last_status = WEXITSTATUS(status);
	else
		*last_status = 1;

	return (0);
}
