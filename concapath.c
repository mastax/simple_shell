#include "shell.h"
/**
 * append_path - Concatenate a path token with a command token
 * @path: path string to append to
 * @command: command string to append
 * Return: buffer to appended path
 */
char *append_path(char *path, char *command)
{
	char *buff;
	size_t a = 0, b = 0;

	if (command == 0)
		command = "";
	if (path == 0)
		path = "";
	buff = malloc(sizeof(char) * _strlen(path) + _strlen(command) + 2);
	if (buff == NULL)
		return (NULL);
	while (path[a])
	{
		buff[a] = path[a];
		a++;
	}
	if (path[a - 1] != '/')
	{
		buff[a] = '/';
		a++;
	}
	while (command[b])
	{
		buff[a + b] = command[b];
		b++;
	}
	buff[a + b] = '\0';
	return (buff);
}
