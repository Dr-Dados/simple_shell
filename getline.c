#include "shell.h"
/**
 * _getline_command - Reads a line of input from the user.
 * Return: The input line as a string.
 */
char *_getline_command(void)
{
char *lineptr = NULL;
size_t charter_user = 0;

if (isatty(STDIN_FILENO))
printf("cisfun$ ");

if (getline(&lineptr, &charter_user, stdin) == -1)
{
free(lineptr);
return (NULL);
}

return (lineptr);
}

