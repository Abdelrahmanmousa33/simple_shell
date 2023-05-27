#include "shell.h"
/**
 * builtin - checks for builtins
 * @command: the command to check
 * @buffer:  to free if program fails
 * Return: nothing
 */
void builtin(char *command[])
{
	if (strcmp(command[0], "env") == 0)
	{
		command[0] = "/bin/env";
	}
	
}
