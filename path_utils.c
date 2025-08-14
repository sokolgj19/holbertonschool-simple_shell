#include "shell.h"

/**
 * _strdup_local - Duplicates a string using malloc
 * @s: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL on failure
 */
static char *_strdup_local(const char *s)
{
	size_t len;
	char *p;

	if (!s)
		return (NULL);
	len = strlen(s);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	memcpy(p, s, len + 1);
	return (p);
}

/**
 * find_env_value - Finds the value of an environment variable
 * @env: Environment array
 * @name: Name of the variable
 *
 * Return: Pointer to the value string or NULL if not found
 */
char *find_env_value(char **env, const char *name)
{
	size_t nlen;
	int i;

	if (!env || !name)
		return (NULL);

	nlen = strlen(name);
	for (i = 0; env[i]; i++)
	{
		if (!strncmp(env[i], name, nlen) && env[i][nlen] == '=')
			return (env[i] + nlen + 1);
	}
	return (NULL);
}

/**
 * join_path - Joins a directory and command into a single path
 * @dir: Directory
 * @cmd: Command
 *
 * Return: Malloc'd full path or NULL on failure
 */
static char *join_path(const char *dir, const char *cmd)
{
	size_t len;
	char *out;

	len = strlen(dir) + 1 + strlen(cmd) + 1;
	out = (char *)malloc(len);
	if (!out)
		return (NULL);

	out[0] = '\0';
	strcat(out, dir);
	strcat(out, "/");
	strcat(out, cmd);
	return (out);
}

/**
 * resolve_command - Resolves a command into a full path
 * @cmd: Command to resolve
 * @env: Environment variables
 *
 * Description:
 * - If cmd contains '/', checks if it's executable.
 * - Otherwise, searches in PATH. Empty PATH entries map to ".".
 *
 * Return: Malloc'd full path or NULL if not found
 */
char *resolve_command(char *cmd, char **env)
{
	char *path, *norm, *p, *dir, *full;
	size_t i, j, len;

	if (!cmd || !*cmd)
		return (NULL);

	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (_strdup_local(cmd));
		return (NULL);
	}

	path = find_env_value(env, "PATH");
	if (!path || !*path)
		return (NULL);

	len = strlen(path);
	norm = (char *)malloc(len * 2 + 3);
	if (!norm)
		return (NULL);

	j = 0;
	if (path[0] == ':')
	{
		norm[j++] = '.';
		norm[j++] = ':';
		i = 1;
	}
	else
	{
		i = 0;
	}

	while (i < len)
	{
		if (path[i] == ':')
		{
			norm[j++] = ':';
			if (i + 1 >= len || path[i + 1] == ':')
				norm[j++] = '.';
			i++;
		}
		else
		{
			norm[j++] = path[i++];
		}
	}
	if (j > 0 && norm[j - 1] == ':')
		norm[j++] = '.';

	norm[j] = '\0';

	p = strtok(norm, ":");
	while (p)
	{
		dir = p;
		full = join_path(dir, cmd);
		if (!full)
		{
			free(norm);
			return (NULL);
		}
		if (access(full, X_OK) == 0)
		{
			free(norm);
			return (full);
		}
		free(full);
		p = strtok(NULL, ":");
	}

	free(norm);
	return (NULL);
}
