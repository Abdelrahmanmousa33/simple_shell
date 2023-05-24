#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
void str_tok(char *buffer, char *argv[]);
void _execve(char *argv[], char **av, char **env);
void builtin(char *command[], char *buffer);
pid_t _fork(char *buffer);
size_t _strlen(char *str);
#endif
