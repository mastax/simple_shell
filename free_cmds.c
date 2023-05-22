#include "shell.h"
/**
 * free_cmds - This fuunction frees the cmd array
 * @m: pointer to an array
 *
 * Return: void
 */
void free_cmds(char **m)
{
	int i = 0;

	if (m == NULL)
		return;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}
