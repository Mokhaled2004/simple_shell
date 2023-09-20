#include "shell.h"

/**
 * _strlen - string length
 * @str: array of charahcters null terminated
 * Return: length of string
 */
int _strlen(char *str)
{
int i = 0;

while (str && str[i] != '\0')
i++;

return (i);
}
/**
 * _strcmp - compared two strings
 * @str1: first one
 * @str2: seocnd one
 * Return: (0) match (1) not match
 */
int _strcmp(char *str1, char *str2)
{
int pos = 0;

while (str1[pos])
{
if (str1[pos] != str2[pos])
return (1);
pos++;
}
return (0);
}

/**
 * _strcp - copy str to new allocated one and return it
 * @str: source
 * Return: newly allocated string copy of source
 */
char *_strcp(char *str)
{
int lengths, i = 0;
char *_strcp = NULL;

lengths = _strlen(str);
/* 1 to null character */
_strcp = malloc(lengths + 1);
while (i < lengths && str[i])
{
_strcp[i] = str[i];
i++;
}
_strcp[i] = '\0';
return (_strcp);
}

/**
 * _strconcat - add str2 command to str1 path
 * @str1: first string
 * @str2: second string
 * Return: str1 after addition
 */
char *_strccat(char *str1, char *str2)
{
int str1_lengths, str2_lengths, i;
char *full_str = NULL;

i = 0;
str1_lengths = _strlen(str1);
str2_lengths = _strlen(str2);
/* 2 for / , \0 chars */
full_str = malloc(str1_lengths + str2_lengths + 2);
for (i = 0; i < str1_lengths; i++)
full_str[i] = str1[i];

full_str[i] = '/';

for (i = 0; i < str2_lengths; i++)
full_str[(i + str1_lengths)+1] = str2[i];

full_str[str1_lengths + str2_lengths + 1] = '\0';
return (full_str);
}
/**
 * _rcomment - remove comment # from string
 * @str: string from stander input
 */
void _rcomment(char *str)
{
int j = 0;
while (str && str[j] != '\0')
{
if (str[j] == ' ' && str[j + 1] == '#')
{
str[j] = '\0';
break;
}
j++;
}
}
