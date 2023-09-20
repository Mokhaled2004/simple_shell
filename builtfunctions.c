#include "shell.h"
/**
* _env - print the environments
* @arguments: splitted string acc to breaks
* Return: EXIT_SUCCESS = 0
*/
int _env(__attribute__((unused)) char **arguments)
{
int len;
char **tempo = environ;

while (tempo && *tempo)
{
len = _strlen(*tempo);
write(STDOUT_FILENO, *tempo, len);
write(STDOUT_FILENO, "\n", 1);
tempo++;
}
return (EXIT_SUCCESS);
}
/**
* _setenv - set the environments
* @key: splitted string acc to breaks
* @value: splitted string acc to breaks
* Return: EXIT_SUCCESS = 0
*/
int _setenv(char *key, char *value)
{
char **args = NULL;
args = malloc(3 * sizeof(char *));
args[1] = _strcp(key);
args[2] = _strcp(value);
_variable(args);
_array_of_pointers(args);
return (EXIT_SUCCESS);
}
/**
* _cd - change directory
* @arguments: splitted string acc to breaks
* Return: EXIT_SUCCESS = 0
*/
int _cd(char **arguments)
{
char *pwd = NULL;
char *opwd = NULL;


if (arguments[1] == NULL)
{
arguments[1] = _getenv("HOME");
}


if (arguments[1][0] == '-' && arguments[1][1] == '\0')
{
arguments[1] = _getenv("OLDPWD");
if (!arguments[1])
{
write(STDERR_FILENO, &"cd: OLDPWD not set\n", 19);
return (EXIT_FAILURE);
}
}
opwd = _getenv("PWD");
_setenv("OLDPWD", opwd);
if (chdir(arguments[1]) != 0)
{
perror("cd");
return (EXIT_FAILURE);
}
else
{

pwd = getcwd(NULL, 0);
if (pwd != NULL)
{
_setenv("PWD", pwd);
free(pwd);
return (EXIT_SUCCESS);
}
}
return (EXIT_SUCCESS);
}
