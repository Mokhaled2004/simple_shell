#include "shell.h"
/**
* _all - free all memory from arguments & string & paths
* @string: input string to shell
* @arguments: splitted string acc to breaks
* @paths: splitted path from environment
*/
void _all(char **arguments, char *string, char **paths)
{
free(string);
free(arguments);
_array_of_pointers(paths);
}

