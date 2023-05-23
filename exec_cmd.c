#include "shell.h"
/**
 * exec_cmd - This funct createe a new child process
 * executes a command, and wait for the child process
 * to update its status
 * @c: command
 * @command: vector array of pointers to commands
 *
 * Return: void
 */

void exec_cmd(char *c, char **command)
{
	pid_t newProcess;
	int status;
	char **envp = environ;

	newProcess = fork();
	if (newProcess < 0)
		perror(c);
	if (newProcess == 0)
	{
		execve(c, command, envp);
		perror(c);
		free(c);
		free_cmds(command);
		exit(98);
	}
	else
	{
		wait(&status);
	}
}
