#include "shell.h"

/**
 * _full_path - check if argument is full_path
 * @argument: string to test
 * Return: result of access (0)success
 */
int _full_path(char *argument)
{
return (access(argument, X_OK));
}

/**
 * _small_path - check if arfument is small_path
 * @argument: string to test
 * @path: array of separted paths to contactenate to argument
 * Return: allocated full path (success) NULL (fail)
 */
char *_small_path(char *argument, char **path)
{
char *fullpaths;

while (*path != NULL)
{
fullpaths =  _strccat(*path, argument);
if (_full_path(fullpaths) == 0)
{
return (fullpaths);
}
free(fullpaths);
path++;
}
return (NULL);
}
