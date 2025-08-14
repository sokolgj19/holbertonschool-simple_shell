#include "shell.h"

/**
 * get_path_dirs - splits PATH into directories
 * @envp: environment variables
 *
 * Return: array of PATH directories or NULL
 */
char **get_path_dirs(char **envp)
{
	char *path = NULL, *copy, **dirs;
	size_t i = 0, bufsize = 64;

	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break;
		}
		i++;
	}
	if (!path)
		return (NULL);

	copy = strdup(path);
	if (!copy)
		return (NULL);

	dirs = malloc(bufsize * sizeof(char *));
	if (!dirs)
		return (free(copy), NULL);

	i = 0;
	for (char *tok = strtok(copy, ":"); tok; tok = strtok(NULL, ":"))
	{
		if (i + 1 >= bufsize)
		{
			bufsize *= 2;
			dirs = realloc(dirs, bufsize * sizeof(char *));
			if (!dirs)
				return (free(copy), NULL);
		}
		dirs[i++] = strdup(tok);
	}
	dirs[i] = NULL;
	free(copy);
	return (dirs);
}

/**
 * join_path - joins dir + command
 * @dir: directory
 * @cmd: command
 *
 * Return: malloc'ed string
 */
char *join_path(char *dir, char *cmd)
{
	size_t len = strlen(dir) + strlen(cmd) + 2;
	char *full = malloc(len);

	if (!full)
		return (NULL);

	strcpy(full, dir);
	strcat(full, "/");
	strcat(full, cmd);

	return (full);
}

/**
 * find_command - searches for a command in PATH
 * @cmd: command name
 * @envp: environment variables
 *
 * Return: malloc'ed full path or NULL
 */
char *find_command(char *cmd, char **envp)
{
	char **dirs = get_path_dirs(envp);
	char *full = NULL;
	size_t i = 0;

	if (!dirs)
		return (NULL);

	while (dirs[i])
	{
		full = join_path(dirs[i], cmd);
		if (full && access(full, X_OK) == 0)
			break;
		free(full);
		full = NULL;
		i++;
	}
	for (i = 0; dirs[i]; i++)
		free(dirs[i]);
	free(dirs);

	return (full);
}
