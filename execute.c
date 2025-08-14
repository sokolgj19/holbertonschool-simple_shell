#include "shell.h"

/**
 * execute_command - forks and executes a command
 * @argv: argument vector
 * @envp: environment variables
 *
 * Return: status code
 */
int execute_command(char **argv, char **envp)
{
	pid_t pid;
	int status;

	if (argv == NULL || argv[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}
