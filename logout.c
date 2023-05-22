#include "shell.h"
/**
 * logout - Frees the buffer and exits the program.
 * @cmd: Array of command line arguments.
 * @b: Line buffer created in main.
 *
 * Return: void
 */

void logout(char **command, char *b)
{
	free(b);
	free_cmds(command);
	exit(0);
}
