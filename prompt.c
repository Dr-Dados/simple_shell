#include "shell.h"
#include <sys/wait.h>
/**
 * prompt - Display a prompt and execute commands entered by the user.
 * @av: Array of strings representing command-line arguments.
 * @env: Array of strings representing the environment variables.
 */
void prompt(char **av, char **env)
{
char *str = NULL;
int i = 0, status;
size_t n = 0;
ssize_t sz;
char *argv[] = {NULL, NULL};
pid_t ch_pid;

while (1)
{
if (isatty(STDIN_FILENO))
printf("cisfun$ ");
sz = getline(&str, &n, stdin);
if (sz == -1)
{
free(str);
exit(EXIT_FAILURE);
}
while (str[i])
{
if (str[i] == '\n')
str[i] = 0;
i++;
}
argv[0] = str;
ch_pid = fork();
if (ch_pid == -1)
{
free(str);
exit(EXIT_FAILURE);
}
if (ch_pid == 0)
{
if (execve(argv[0], argv, env) == -1)
printf("%s: No such file or directory\n", av[0]);
}
else
wait(&status);
}
}
