#include "shell.h"
/**
* split - function that split string  into arguments
* @string: the string to split
* @breaks: array of breaks characters
* Return: array of arguments
*/
char **split(char *string, char *breaks)
{
char *argument;
char **arguments;
int position = 0, size = _strlen(string);

arguments = malloc((size + 1) * sizeof(char *));
if (!arguments)
{
perror("Error:failed to allocate memory");
exit(EXIT_FAILURE);
}

argument = strtok(string, breaks);
while (argument != NULL)
{
arguments[position++] = argument;
argument = strtok(NULL, breaks);

}

arguments[position] = NULL;
return (arguments);
}

/**
* _atoi - converts string to int
* @s: string to convert
* Description: converts string to int considering all negatives
* Return: integer
 **/

int _atoi(char *s)
{
int i, val, sign;

val = 0;
sign = 1;

for (i = 0; s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'); i++)
{
if (s[i] == '-')
sign = sign * -1;
}

for (i = 0; s[i] != 0; i++)
{
if (s[i] >= '0' && s[i] <= '9')
val = val * 10 + sign * (s[i] - '0');
if (val != 0 && !(s[i] >= '0' && s[i] <= '9'))
return (val);
}
return (val);
}
/**
* _clStr - clean string from new line and comment
* @str: string from user or pipe to clean
* Return: NULL if new line or string without comment
*/

char *_clStr(char *str)
{

if (*str == '\n' || *str == '#')
{
return (NULL);
}
str[_strlen(str) - 1] = '\0';
_rcomment(str);
return (str);
}
/**
* string_realloc - reallocate string
* @str: pointer of array of character to reallocate
* @new_size: number of bytes to allocate
*/
void string_realloc(char *str, size_t new_size)
{
char *new_str = NULL;
if (str == NULL)
{
return;
}
new_str = malloc(new_size);
if (new_str == NULL)
{
return;
}
new_str = _strcp(str);
free(str);
str = new_str;
}
/**
* _getline - Implement the getline function
* @string: the string pointer to pass the characters to
* @string_size: number of bytes that readed
* Return: the number of bytes read
*/
ssize_t _getline(char **string, size_t *string_size)
{
size_t buffer_size = BUFSIZ, position = 0;
char *buffer = NULL;
char c;

if (string == NULL || string_size == NULL)
{
return (-1);
}
buffer = malloc(buffer_size);
if (buffer == NULL)
{

return (-1);
}
while (read(STDIN_FILENO, &c, 1) == 1)
{
if (position >= buffer_size - 1)
{

buffer_size *= 2;
string_realloc(buffer, buffer_size);
}
buffer[position++] = c;
if (c == '\n')
{
break;
}
if (position == 0 && c == EOF)
{
free(buffer);
return (-1);
}
}
buffer[position] = '\0';
*string = buffer;
*string_size = buffer_size;
return (position);
}
