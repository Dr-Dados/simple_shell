#include "shell.h"

/**
 * _fork_fun - Forks a child process and executes the command.
 * @arg: Command and arguments.
 * @av: Command and arguments (unused).
 * @env: Environment variables.
 * @lineptr: User input line.
 * @np: Number of commands executed so far (unused).
 * @c: Indicator whether command is found in PATH (unused).
 * Return: Status of the child process.
 */

int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
 
pid_t child_pid;
int status = 0, exec_status = 0;
struct stat stat_lineptr;
(void)av;
child_pid = 0;
 (void)np;
child_pid = fork();
if (child_pid == -1)
{
perror("Error");
free(lineptr);
exit(errno);
}
if (child_pid == 0)
{
exec_status = execve(arg[0], arg, env);
if (exec_status == -1)
{
if (stat(arg[0], &stat_lineptr) == 0)
{
perror(av[0]);
exit(errno);
}
if (c == 0)
{
perror(av[0]);
exit(errno);
}
free(arg[0]);
free(lineptr);
exit(0);
}
}
else
{
waitpid(child_pid, &status, WUNTRACED);
}

return (status);
}
/**
 * lsh_exit - Exits the shell.
 * @args: Command and arguments (unused).
 * Return: Exit status 200.
 */
int lsh_exit(char **args)
{
(void)args;
return (200);
}
/**
 * lsh_cd - Changes the current directory.
 * @args: Command and arguments.
 * Return: 1 on success, otherwise an error occurred.
 */
int lsh_cd(char **args)
{
if (args[1] == NULL)
fprintf(stderr, "lsh: expected argument to \"cd\"\n");
else
{
if (chdir(args[1]) != 0)
perror("lsh");
}
return (1);
}
/**
 * lsh_help - Displays information about the shell.
 * @args: Command and arguments.
 * Return: Always 1.
 */
int lsh_help(char **args)
{
int i;
printf("Simple Shell\n");
printf("Type program names and arguments, and hit enter.\n");
printf("The following are built-in:\n");

for (i = 0; i < 4; i++)
printf("  %s\n", args[i]);

printf("Use the man command for information on other programs.\n");
return (1);
}
/**
 * lsh_ctrld - Handles the Ctrl+D input.
 * @args: Command and arguments (unused).
 * Return: Always 1.
 */
int lsh_ctrld(char **args)
{
(void)args;
write(STDOUT_FILENO, "\n", 1);
return (1);
}

