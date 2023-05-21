#include "shell.h"
/**
 * search_path - searches for PATH directory
 * @p: first operand
 * @command: second operand
 *
 * Return: Unsigned integer character count
 */
char *search_path(char **p, char *command)
{
	int i;
	char *ret;

	for (i = 0; p[i]; i++)
	{
		ret = append_path(p[i], command);
		if (access(ret, F_OK | X_OK) == 0)
		{
			return (ret);
		}
		else
		{
			free(ret);
		}
	}
	return (NULL);
}
