#include "shell.h"
/**
 * _strlen - works like strlen
 * @str: the string
 * Return: str len
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
