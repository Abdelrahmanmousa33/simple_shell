#include "shell.h"
/**
 * _execve - excutes another program
 * @argv: commands array
 * @av: my shell name
 * @env: env variables
 * Return: nothing
 */
void _execve(char *command, char *argv[], char **av, char **env)
{
	if (execve(command, argv, env) == -1)
	{
		printf("%s:%s:no such file or directory\n", av[0], argv[0]);
		exit(0);
	}
}
