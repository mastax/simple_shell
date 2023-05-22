#include "shell"
/**
 * env_builtin - Prints the current environment
 * Description: This function is responsible for
 * printing the current
 *
 * Return: 0 indicating succesful execution.
 */
void env_builtin(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const, void *) env[], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
