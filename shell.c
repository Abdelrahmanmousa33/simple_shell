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
	char *buffer = NULL, *argv[10], *prompt = "## ", *command;
	int chars_red = 0, status;
	size_t buf_size = 0;
	pid_t child;
	bool mode_check = false;

	argv[9] = NULL;
	
	if (ac > 1)
	{
		write(STDOUT_FILENO, "usage ./hsh", 11);
		exit(0);
	}
	while (1)
	{
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
		 builtin(argv);
		 if (strcmp(argv[0], "exit") == 0)
			exit(atoi(argv[1]));
		command = _path(argv[0]);
		if (command == NULL)
		{
			 printf("%s:%s:no such file or directory\n", av[0], argv[0]);
			continue;
		}
		child = _fork(buffer);
		if (child == 0)
			_execve(command, argv, av, env);
		waitpid(child, &status, 0);
		free(command);
	}
}
