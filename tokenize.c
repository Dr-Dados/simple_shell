#include "shell.h"
/**
 * tokenize - Split a string into tokens.
 * @lineptr: The input string to tokenize.
 *
 * Return: A double pointer to an array of tokens.
 * Each token is a substring of lineptr separated by whitespace characters.
 * The last element of the array is set to NULL.
 * If lineptr is NULL or contains only whitespace characters, return NULL.
 * If memory allocation fails, return NULL.
 */
char **tokenize(char *lineptr)
{
char **user_command = NULL;
char *token = NULL;
size_t i = 0;
int size = 0;

if (lineptr == NULL)
return (NULL);

for (i = 0; lineptr[i]; i++)
{
if (lineptr[i] == ' ')
size++;
}

if ((size + 1) == _strlen(lineptr))
return (NULL);

user_command = malloc(sizeof(char *) * (size + 2));
if (user_command == NULL)
return (NULL);

token = strtok(lineptr, " \n\t\r");

for (i = 0; token != NULL; i++)
{
user_command[i] = token;
token = strtok(NULL, " \n\t\r");
}

user_command[i] = NULL;
return (user_command);
}
