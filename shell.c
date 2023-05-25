#include "shell.h"
/**
 * main - the main code of my unix like shell
 * @ac: number of arguments
 * @av: arguments string
 * @env: enviroment variables
 * Return: failure or success
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *argv[10], *prompt = "## ";
	int chars_red = 0, status;
	size_t buf_size = 0;
	pid_t child;
	bool mode_check = false;

	argv[9] = NULL;
	while (1)
	{
		if (ac != 1)
			write(STDOUT_FILENO, "usage ./hsh", 11);
		fflush(stdout);
		if (mode_check == false)
		{
			if (isatty(STDIN_FILENO) == 0)
				mode_check = true;
			else
				write(STDOUT_FILENO, prompt, 3);
		}
		chars_red = getline(&buffer, &buf_size, stdin);
		if (chars_red == -1)
		{
			if (mode_check == false)
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(0);
		}
		if (buffer[chars_red - 1] == '\n')
			buffer[chars_red - 1] = '\0';
		str_tok(buffer, argv);
		if (argv[0] == NULL || _strlen(argv[0]) == 0)
			continue;
		builtin(argv, buffer);
		child = _fork(buffer);
		if (child == 0)
			_execve(argv, av, env);
		waitpid(child, &status, 0);
	}
}