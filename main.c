#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

extern char **environ;

/**
* print_environment - lol
* Return: lol
*/
void print_environment(void)
{
int i;
for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
int main(void)
{
char *line = NULL;
size_t line_length = 0;
char *args[MAX_ARGS];
int status;
char previous_directory[MAX_LINE_LENGTH];
while (1)
{
printf("HOME$ ");
ssize_t read = getline(&line, &line_length, stdin);
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
int i = 0;
args[i] = strtok(line, " \n");
while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " \n");
}
args[i] = NULL;
if (strcmp(args[0], "cd") == 0)
{
if (args[1] == NULL)
{
chdir(getenv("HOME"));
}
else
{
if (strcmp(args[1], "-") == 0)
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
chdir(args[1]);
}
}
continue;
}
else if (strcmp(args[0], "exit") == 0)
{
printf("[Disconnected...]\n");
exit(0);
}
else if (strcmp(args[0], "env") == 0)
{
print_environment();
continue;
}
pid_t pid = fork();
if (pid < 0)
{
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
execve(args[0], args, environ);
char command_path[256];
snprintf(command_path, sizeof(command_path), "/usr/bin/%s", args[0]);
execve(command_path, args, environ);
perror("execve failed");
exit(1);
}
else
{
waitpid(pid, &status, 0);
}
}
free(line);
return (0);
}
