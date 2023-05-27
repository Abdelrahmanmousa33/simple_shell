#include "shell.h"
/**
 * builtin - checks for builtins
 * @command: the command to check
 * @buffer:  to free if program fails
 * Return: nothing
 */
int builtin(char *command[], char *buffer)
{
	if (strcmp(command[0], "exit") == 0)
	{
		free(buffer);
		if (command[1] == NULL)
			exit(0);
		else
		{
			return (1);			
		}
	}
	if (strcmp(command[0], "env") == 0)
	{
		command[0] = "/bin/env";
		return(0);
	}
	return (0);
	
}
