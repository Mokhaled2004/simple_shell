#include "shell.h"

/**
* _checkexit - check that argument[0] = exit
* exit with argument[1] if exists
* @str: input string to shell
* @args: splitted string acc to breaks
* @paths: splitted path from environment
* @st: status of execution
* @p: number of proccess
* @pth: the program path
* Return: zero if found exit but not true
* one if not found
*/
int _checkexit(char **args, char *str, char **paths, int *st, char *pth, int p)
{
char *msg = NULL;
int arg1_result;
if (_strcmp("exit", args[0]) == 0)
{
if (args[1])
{
if (_postive(args[1]) == 0)
{
arg1_result = _atoi(args[1]);
_all(args, str, paths);
_array_of_pointers(environ);
exit(arg1_result);
}
else
{
msg = _strccat2("Illegal number", args[1]);
execve_error(msg, args[0], p, pth);
free(msg);
*st = 2;
return (0);
}
}
_all(args, str, paths);
_array_of_pointers(environ);
exit(*st);
}
return (1);
}

/**
* _checkbuiltin - check the builtin environments
* @arguments: splitted string acc to breaks
* Return: -1 if not builtin else return builtin function
*/

int _checkbuiltin(char **arguments)
{

char *builtin_str[] = {"env", "setenv", "unsetenv", "cd"};

int (*builtin_func[])(char **) = {&_env,
&_variable, &_env_variable, &_cd};
int i;

int num_builtins = (sizeof(builtin_str) / sizeof(char *));

for (i = 0; i < num_builtins; i++)
{
if (_strcmp(arguments[0], builtin_str[i]) == 0)
{
return ((*builtin_func[i])(arguments));
}
}
return (-1);
}
