#include "shell.h"

/**
 * set_environ - set environ at idx i
 * @i: index
 * @arg1: variable name
 * @arg2: value
 */
void set_environ(int i, char *arg1, char *arg2)
{
int lens1 = _strlen(arg1);
int lens2 = _strlen(arg2);
int total_lengths = lens1 + lens2 + 2;
int j = 0;
int idx = 0;

environ[i] = malloc(total_lengths);
if (!environ[i])
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

for (j = 0; j < lens1; j++)
{
environ[i][idx] = arg1[j];
idx++;
}
environ[i][idx] = '=';
idx++;
for (j = 0; j < lens2; j++)
{
environ[i][idx] = arg2[j];
idx++;
}
environ[i][idx] = '\0';
}

/**
 * copy_array_of_strings2 - hard copy
 * @str: array of strings
 * Return: allocated new copy array
 */
char **copy_array_of_strings2(char **str)
{
int counts = 0;
char **new_arrays = str;
int i;

while (*new_arrays)
{
counts++;
new_arrays++;
}

new_arrays = malloc(sizeof(char *) * (counts + 2));
if (!new_arrays)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

for (i = 0; i < counts; i++)
{
new_arrays[i] = _strcp(str[i]);
if (!new_arrays[i])
{
perror("Memory allocation failed");
_array_of_pointers(new_array);
exit(EXIT_FAILURE);
}
}
new_arrays[counts + 1] = NULL;

return (new_arrays);
}

/**
 * _variable - set the environment
 * @arguments: splitted string according to breaks
 * Return: EXIT_SUCCESS = 0
 */
int _variable(char **arguments)
{
int i = 0, j;
int lens1 = 0;
char **new_environs = NULL;
if (arguments[1] != NULL && arguments[2] != NULL)
{
lens1 = _strlen(arguments[1]);
while (environ[i])
{
for (j = 0; j <= lens1; j++)
{
if (arguments[1][j] != environ[i][j])
break;
}
if (j == lens1)
{
free(environ[i]);
set_environ(i, arguments[1], arguments[2]);
return (EXIT_SUCCESS);
}
i++;
}

new_environs = copy_array_of_strings2(environ);
if (!new_environs)
{
perror("Memory allocation failed");
return (EXIT_FAILURE);
}

_array_of_pointers(environ);
environ = new_environs;

set_environ(i, arguments[1], arguments[2]);
}
else
{
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}

/**
 * _env_variable - unset the environment
 * @arguments: splitted string according to breaks
 * Return: EXIT_SUCCESS = 0
 */
int _env_variable(char **arguments)
{
int i = 0, j;
int lens1 = 0;
if (arguments[1] != NULL)
{
lens1 = _strlen(arguments[1]);
while (environ[i])
{
for (j = 0; j <= lens1; j++)
{
if (arguments[1][j] != environ[i][j])
break;
}
if (j == lens1)
{
/* remove variable*/
_idx_from_array(i, environ);
return (EXIT_SUCCESS);
}
i++;
}
}
return (EXIT_FAILURE);
}
