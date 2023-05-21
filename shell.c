#include "shell.h"
/**
 * main - the shell entry point.
 * @argc: argument counter.
 * @argv: argument vector.
 * @envp: environment variable.
 *
 * Return: always 0.
 */
int main(int argc, char **argv, char **envp)
{
	char *lineptr = NULL, *pathcommand = NULL, *path = NULL;
	size_t buffer_size = 0;
	ssize_t n_chars_read = 0;
	char **command = NULL, **paths = NULL;
	(void) envp, (void) argv;
	if (argc < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_cmds(command);
		free_cmds(paths);
		free(pathcommand);
		prompt_printer();
		n_chars_read = getline(&lineptr, &buffer_size, stdin);
		if (n_chars_read < 0)
			break;
		info.ln_count++;
		if (lineptr[n_chars_read - 1] == '\n')
			lineptr[n_chars_read - 1] = '\0';
		command = tokenize(lineptr);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		/*check the type of command - builtin or external*/
		if (command_type(command, lineptr))
			continue;
		path = _getpath();
		paths = tokenize(path);
		pathcommand = search_path(paths, command[0]);
		/*if the command is not found, print an error*/
		if (pathcommand == NULL)
			perror(argv[0]);
		else
			exec_cmd(pathcommand, command);
	}
	/* print a newline if the loop was terminayed by an error*/
	if (n_chars_read < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(lineptr);
	return (0);
}
