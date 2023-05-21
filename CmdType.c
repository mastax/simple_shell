#include "shell.h"
/**
 * command_type - check the command if its a builtin or exec
 * @command: array of pointers to command line args
 * @b: line-ptr returned by getline func
 * Return: 1 if success, 0 if failure.
 */
int command_type(char **command, char *b)
{
	if (is_builtin(command, b))
	{
		return (1);
	}
	else if (**command == '/')
	{
		exec_cmd(command[0], command);
		return (1);
	}
	return (0);
}
