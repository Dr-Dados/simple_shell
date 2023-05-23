#include "shell.h"
/**
 * main - Entry point of the program.
 * @ac: Number of command-line arguments.
 * @av: Array of strings representing command-line arguments.
 * @env: Array of strings representing the environment variables.
 * Return: 0 on success, or an error code on failure.
 */
int main(int ac, char **av, char **env)
{
if (ac == 1)
{
prompt(av, env);
}
return (0);
}
