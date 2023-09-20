#include "shell.h"

/**
 * _array_of_pointers - free array of allocated pointers
 * @array: array of pointers
 */
void _array_of_pointers(char **array)
{
char **temps = array;

while (array && *array)
{
free(*array);
array++;
}
free(temps);
}

/**
 * *_strings - hard copy
 * @str: array of strings
 * Return: allocated new copy array
 */
char **_strings(char **str)
{
char **news_array = NULL;
int i = 0;

while (str[i])
{
i++;
}
news_array = malloc(sizeof(char *) * (i + 1));
i = 0;
while (str[i])
{
news_array[i] = _strcp(str[i]);
i++;
}
news_array[i] = NULL;
return (news_array);
}
/**
 * _idx_from_array - remove element from array
 * @idx: index of element
 * @array: array to remove element from
 */
void _idx_from_array(int idx, char **array)
{
int j = idx;
int length = 0;
while (array && array[length])
{
length++;
}
length++;
free(array[j]);
for (; j < (length - 1); j++)
{
array[j] = array[j + 1];
}
}
