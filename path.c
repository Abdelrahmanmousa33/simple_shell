#include "shell.h"
char *_path(char *command)
{
       int command_len = 0;
       struct stat fileSTAT;
       char *path_copy = NULL, *path,*token, *file_path, *command_copy;

        path = getenv("PATH");
        if (path == NULL)
                return (NULL);
        path_copy = strdup(path);
        command_len = strlen(command);
	command_copy = malloc(command_len + 1);
	strcpy(command_copy, command);
        token = strtok(path_copy, ":");
        while (token !=NULL)
        {
                file_path = malloc(command_len + strlen(token) + 2);
                strcpy(file_path, token);
                strcat(file_path, "/");
                strcat(file_path, command);
                strcat(file_path, "\0");
                if (stat(file_path, &fileSTAT) == 0)
                {
                        free(path_copy);
			free(command_copy);
                        return (file_path);
                }
                else
                {
			free(file_path);
                        token = strtok(NULL, ":");
                }
        }
	free(path_copy);
        if (stat(command, &fileSTAT) == 0)
                return (command_copy);
	free(command_copy);
        return (NULL);
}
