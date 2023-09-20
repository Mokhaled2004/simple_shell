#include "shell.h"
/**
 * _execution - function that Execute external command
 * @arguments: the arguments of command
 * the arguments[0] is the path of program to Execute
 * @st: status of execution
 * Return: status of execution
 */
void _execution(char **arguments, int *st)
{
pid_t pid;
int statuss = 0;
/*using fork to create child proccess*/
pid = fork();
if (pid == 0)
{
/*child proccess*/
execve(arguments[0], arguments, environ);
}
else if (pid == -1)
{
/*failed to fork proccess*/
perror("Error: Cannot fork");
exit(EXIT_FAILURE);
}
else
{
/*parent proccess*/
if (waitpid(pid, &statuss, 0) == -1)
{
perror("Error: waitpid failed");
exit(EXIT_FAILURE);
}
}
if (WIFEXITED(statuss))
{
int exit_statuss = WEXITSTATUS(statuss);
*st = exit_statuss;
}
}

/**
 * _before_exec - check certain condition betfore execution
 * @args: arguments splitted
 * @paths: paths splitted
 * @p_cnt: number of proccess
 * @p_path: the program path
 * @st: status of execution
 * Return: status of execution
 */
void _before_exec(char **args, char **paths, int p_cnt, char *p_path, int *st)
{
char *fullpaths = NULL;

if (access(args[0], F_OK) == 0)
_execution(args, st);
else if (_full_path(args[0]) == 0)
_execution(args, st);
else
{
fullpaths = _small_path(args[0], paths);
if (fullpaths != NULL)
{
args[0] = fullpaths;
_execution(args, st);
free(fullpaths);
}
else
{
execve_error("not found", args[0], p_cnt, p_path);
*st = 127;
return;
}
}
}
