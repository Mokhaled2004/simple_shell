#include "shell.h"
/**
* _printnum - recursive function to print a number
*@n: number to print
*/
void _printnum(unsigned int n)
{
char num;

if (n / 10)
_num(n / 10);

num = n % 10 + '0';
write(STDERR_FILENO, &num, 1);
}
/**
* _positive - function to check positive numbers
*@str: string to check if have number
* Return: zero if positive number
*/
int _postive(char *str)
{
int i = 0;
while (str && *str)
{
i = *str - '0';
if (!(i >= 0 && i <= 9))
{
return (EXIT_FAILURE);
}
str++;
}
return (EXIT_SUCCESS);
}
