#include "shell.h"
/**
 * catch_signal - signal handler
 * @number: the number of signal
 */
void catch_signal(int number)
{
if (number == SIGINT)
{
write(STDOUT_FILENO, "\n ", 1);
exit(EXIT_SUCCESS);
}
}
/**
 * infinite_loop - function to make the shell always open
 * inside the loop we get string, split it and execute it
 * @program_path: the program path
 * Return: status of execution
 */
int infinite_loop(char *program_path)
{
int statuss = 0;
char **argss = NULL;
int proccess_counters = 1;
char *strings = NULL;
size_t string_sizes = 0;
char **pathss = _getallpaths();

signal(SIGINT, catch_signal);

/*print prompt if user run the program*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "m$ ", 3);
/* if not or get the command from pipe*/
/*it will start execute the command*/
while ((_getline(&strings, &string_sizes)))
{
/* split arguments && execution the commands*/
sh(strings, argss, pathss, proccess_counters, program_path, &statuss);
proccess_counters++;
fflush(stdout);
/*check non interactive mood*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "$ ", 3);
}
/*check EOF*/
/*the only way you can arrive here with EOF = -1*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "\n", 1);
_all(argss, strings, pathss);
_array_of_pointers(environ);
return (statuss);
}
