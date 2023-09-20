#include "shell.h"

/**
 * _strccat2 - add str2 command to str1 path
 * @str1: first string
 * @str2: second string
 * Return: str1 after addition
 */
char *_strccat2(char *str1, char *str2)
{
int str1_lengths, str2_lengths, i;
char *full_str = NULL;

i = 0;
str1_lengths = _strlen(str1);
str2_lengths = _strlen(str2);
/* 2 for / , \0 chars */
full_str = malloc(str1_lengths + str2_lengths + 3);
for (i = 0; i < str1_lengths; i++)
full_str[i] = str1[i];

full_str[i++] = ':';
full_str[i] = ' ';

for (i = 0; i < str2_lengths; i++)
full_str[(i + str1_lengths)+2] = str2[i];

full_str[str1_lengths + str2_lengths + 2] = '\0';
return (full_str);
}
