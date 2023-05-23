#include "shell.h"

/**
 * is_builtin - checks if a command is a builtin function
 * and executes it
 * @command: array of command line arguments
 * @b: line_buffer created in main
 *
 * Return: 1 if the fommand is a builtin function, 0 otherwise.
 */

int is_builtin(char **command, char *b)
{
	struct builtins builtins = { "env", "exit" };

	if (_strcmp(*command, builtins.env) == 0)
	{
		env_builtin();
		return (1);
	}
	else if (_strcmp(*command, builtins.exit) == 0)
	{
		logout(command, b);
		return (1);
	}
	else
	{
		return (0);
	}
}
