#include "shell.h"
/**
 * _fork - creats a child process
 * @buffer: to free if fork fails
 * Return: process id
 */
pid_t _fork(char *buffer)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	return (child);

}
