#include "shell.h"
/**
 * handle_signal - allows Ctrl+c to be printed
 * @n: signalnum
 * Return : void
 */
void handle_signal(int n __attribute__((unused)))
{
	/* Write a newline char to the standard error */
	write(STDERR_FILENO, "\n", 1);
	/* Write the prompt symole "$ "*/
	write(STDERR_FILENO, "$ ", 2);
}
