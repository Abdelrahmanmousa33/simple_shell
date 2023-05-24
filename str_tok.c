#include "shell.h"
/**
 * str_tok - tokenize sting
 * @buffer: the stirng to tokenize
 * @argv: to save the tokens
 * Return: nothing
 */
void str_tok(char *buffer, char *argv[])
{
	char *token;
	int i = 0, j = 0;

	token = strtok(buffer, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	for (j = 0; j < i; j++)
	{
		if (argv[j][0] == EOF)
		{
			exit(0);
		}
	}
}
