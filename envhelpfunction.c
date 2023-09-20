#include "shell.h"

/**
* _getenv - get environment from environ
* @string: environment to search in environ
* Return: address of its value if  found - NULL if not
*/
char *_getenv(char *string)
{
int len = _strlen(string);
int i = 0;

while (environ[i] != NULL)
{
if (_strcmp(string, environ[i]) == 0)
{
return (&environ[i][len + 1]);
}
i++;
}
return (NULL);
}

/**
* get_all_paths - split the found path into paths
* Return: splitted paths (allocated in memory)
*/
char **get_all_paths(void)
{
char *path = _getenv("PATH");
char *pathcp = _strcp(path);
char **splitted_paths = split(pathcp, ":");
char **copy_splitted_paths = copy_strings(splitted_paths);

free(pathcp);
free(splitted_paths);
return (copy_splitted_paths);
}
