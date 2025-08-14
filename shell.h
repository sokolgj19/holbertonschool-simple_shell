#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * struct environ - global environment variable
 * @environ: external pointer to environment variables
 */
extern char **environ;

/* String tokenizing */
char **split_line(char *line);
void free_argv(char **argv);

/* Command resolution */
char *resolve_command(char *cmd, char **env);
char *find_env_value(char **env, const char *name);

/* Execution */
int execute_command(char **argv, char **env,
		    const char *progname, int *last_status);

#endif /* SHELL_H */
