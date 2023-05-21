#include "shell.h"
/**
 * _getpath - func finds and return the PATH
 * variable for the global environment vector
 *
 * Return: PATH, or NULL
 */
char *_getpath(void)
{
	int i = 0;
	char **env = environ;
	char *path = NULL;

	for (; *env; env++)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
	}
	return (NULL);
}
