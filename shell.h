#ifndef _SHELL_H
#define _SHELL_H

/* libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>

/*String functions*/

char *duplicate_string(char *str);
char *check_string(char *str, int chr);
int _strlen(const char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *first, const char *second, int n);

/* CMD_handler */

char *_getpath(void);
char **tokenize(char *str);
void exec_cmd(char *c, char **command);
char *append_path(char *path, char *command);
char *search_path(char **p, char *command);

/* Built_ins */

void env_builtin(void);
void logout(char **command, char *b);
int is_builtin(char **command, char *b);
void prompt_printer(void);
void handle_signal(int n);

/* Helper_FUNCTIONS */

int command_type(char **command, char *b);
int free_cmds(char **m);

/* Environment */

extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;

/**
 * struct builtins - Handles builtins
 * @env: first mmbr.
 * @exit: second mmbr.
 */
struct builtins
{
	char *env;
	char *exit;
} builtins;

/**
 * struct info - status info struct
 * @final_exit: first mmbr.
 * @ln_count: second mmbr.
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
 * struct flags - this struct hold flags.
 * @interactive: first mmbr.
 */
struct flags
{
	bool interactive;
} flags;

#endif
