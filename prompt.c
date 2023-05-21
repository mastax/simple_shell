#include "shell.h"
/**
 * prompt_printer - this function prints the prompt
 * if the shell is in interactive mode
 *
 * Return: Nothing
 */
void prompt_printer(void)
{
	/*check if both input and output are connected*/
	/* if true, set interactive flag to 1 */
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	/* if runnig an interactive terminal session */
	/* print the prompt sypbole $ to stderr */
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
