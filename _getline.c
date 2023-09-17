#include "shell.h"
#include <unistd.h>
/**
 * _getline - lol
 * @line: loll
 * @len: loolo
 * Return: lol
*/
int _getline(char **line, int *len)
{
char buffer[1024];
int buffer_index = 0;
int buffer_size = 0;
char c;

if (line == NULL)
return (-1);
while (1)
{
if (buffer_index >= buffer_size)
{
buffer_size = read(STDIN_FILENO, buffer, 1024);
buffer_index = 0;
if (buffer_size <= 0)
{
break;
}
}
c = buffer[buffer_index++];

if (c == '\n')
{
(*line)[*len] = '\0';
break;
}
else
{
*line = _realloc(*line, (*len) * sizeof(char), (*len + 1) * sizeof(char));
(*line)[(*len)++] = c;
}
}
return (*len);
}
