#include "shell.h"
#include <sys/wait.h>

/**
 * prompt - Display a prompt and execute commands entered by the user.
 * @av: Array of strings representing command-line arguments.
 * @env: Array of strings representing the environment variables.
 */
void prompt(char **av, char **env)
{
char *str = NULL, *argv[MAX_COMMAND] ,*token;
int status,j;
size_t n = 0;
ssize_t sz;
pid_t ch_pid;

while (1)
{
if (isatty(STDIN_FILENO))
printf("cisfun$ ");
sz = getline(&str, &n, stdin);
if (sz == -1)
break;
str[sz - 1] = '\0';
j = 0;
token = strtok(str, " ");
while (token != NULL && j < MAX_COMMAND - 1)
{
argv[j] = token;
token = strtok(NULL, " ");
j++;
}
argv[j] = NULL;
ch_pid = fork();
if (ch_pid == -1)
{
perror("fork");
break;
}
if (ch_pid == 0)
{
if (execve(argv[0], argv, env) == -1)
printf("%s: No such file or directory\n", av[0]);
}
else
wait(&status);
}
free(str);
exit(EXIT_FAILURE);
}
