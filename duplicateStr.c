#include "shell.h"
/**
 * duplicate_string - returns a pointer to a newly allocated
 * @str: string to be duplicated
 *
 * Return: pointer to the duplicated string
 * or NULL if it fails
 */
char *duplicate_string(char *str)
{
	char *p;
	int i, len;

	if (str == NULL)
	{
		return (NULL);
	}
	len = _strlen(str);
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		p[i] = str[0];
	p[i++] = '\0';
	return (p);
}
