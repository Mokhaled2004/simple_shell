#include "shell.h"
/**
* execve_error - function to print execve error message
* @msg: the error message
* @command: the false command that entered
* @count: the number of proccess
* @p_path: the path of program
*/

void execve_error(char *msg, char *command, int count, char *p_path)
{
int s_length;
s_length = _strlen(p_path);
write(STDERR_FILENO, p_path, s_length);
write(STDERR_FILENO, ": ", 2);
_num(count);
write(STDERR_FILENO, ": ", 2);
s_length = _strlen(command);
write(STDERR_FILENO, command, s_length);
write(STDERR_FILENO, ": ", 2);
s_length = _strlen(msg);
write(STDERR_FILENO, msg, s_length);
write(STDERR_FILENO, "\n", 1);
}
