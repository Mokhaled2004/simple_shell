#include "shell.h"

void print_environmentt(void);
void change_directory(char *directory);
void execute_command(char *command, char *args[]);
/**
 * print_environmentt - Print the environment variables
*/
void print_environmentt(void)
{
int i;
for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
/**
 * change_directory - Print the environment variables
 * @directory: lol
*/
void change_directory(char *directory)
{
char previous_directory[MAX_LINE_LENGTH];
previous_directory[0] = '\0';
if (directory == NULL)
{
chdir(getenv("HOME"));
}
else
{
if (strcmp(directory, "-") == 0)
{
if (previous_directory[0] != '\0')
{
printf("%s\n", previous_directory);
chdir(previous_directory);
}
else
{
printf("No previous directory available.\n");
}
}
else
{
getcwd(previous_directory, sizeof(previous_directory));
chdir(directory);
}
}
}
/**
 * execute_command - Print the environment variables
 * @command: lol
 * @args: lol
*/
void execute_command(char *command, char *args[])
{
pid_t pid = fork();
int status;
if (pid < 0)
{
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
char command_path[256];
snprintf(command_path, sizeof(command_path), "/usr/bin/%s", command);
execve(command_path, args, environ);
perror("execve failed");
exit(1);
}
else
{
waitpid(pid, &status, 0);
}
}
/**
 * main - Simple shell program
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
char *line = NULL, *args[MAX_ARGS];
size_t line_length = 0;
ssize_t read;
int i;

while (1)
{
printf("HOME$ ");
read = getline(&line, &line_length, stdin);
if (read == -1)
{
if (feof(stdin))
{
printf("[Disconnected...]\n");
exit(0);
}
else
{
perror("getline failed");
exit(1);
}
}

i = 0;
args[i] = strtok(line, " \n");
while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " \n");
}
args[i] = NULL;
if (strcmp(args[0], "cd") == 0)
{
change_directory(args[1]);
continue;
}
else if (strcmp(args[0], "exit") == 0)
{
printf("[Disconnected...]\n");
exit(0);
}
else if (strcmp(args[0], "env") == 0)
{
print_environmentt();
continue;
}
execute_command(args[0], args);
}
free(line);
return (0);
}
