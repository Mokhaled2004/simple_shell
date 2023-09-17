#include "shell.h"

/**
<<<<<<< HEAD
 * print_environmentt - Print the environment variables
 */
void print_environmentt(void)
=======
 * print_environment - Print the environment variables
 */
void print_environment(void)
>>>>>>> a692efbd9c799684a470ac9f79a246e10c8d9267
{
    int i;
    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}

/**
 * change_directory - Change the current working directory
 * @directory: The directory to change to
 * @previous_directory: Reference to the previous directory
 */
void change_directory(char *directory, char *previous_directory)
{
<<<<<<< HEAD
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
            getcwd(previous_directory, MAX_LINE_LENGTH);
            chdir(directory);
        }
    }
=======
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
getcwd(previous_directory, MAX_LINE_LENGTH);
chdir(directory);
}
}
>>>>>>> a692efbd9c799684a470ac9f79a246e10c8d9267
}

/**
 * execute_command - Execute the given command
 * @command: The command to execute
 * @args: The arguments for the command
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
<<<<<<< HEAD
    char *line = NULL, *args[MAX_ARGS], previous_directory[MAX_LINE_LENGTH];
    size_t line_length = 0;
    ssize_t read;
    int i;
    previous_directory[0] = '\0';

    while (printf("HOME$ "), (read = getline(&line, &line_length, stdin)) != -1)
    {
        i = 0;
        args[i] = strtok(line, " \n");
        while (args[i])
            args[++i] = strtok(NULL, " \n");
        
        if (!args[0])
            continue;
        if (strcmp(args[0], "cd") == 0)
        {
            change_directory(args[1], previous_directory);
            continue;
        }
        if (strcmp(args[0], "exit") == 0)
        {
            printf("[Disconnected...]\n");
            exit(0);
        }
        if (strcmp(args[0], "env") == 0)
        {
            print_environmentt();
            continue;
        }

        execute_command(args[0], args);
    }
    if (feof(stdin))
    {
        printf("[Disconnected...]\n");
        exit(0);
    }
    perror("getline failed");
    exit(1);
=======
char *line = NULL, *args[MAX_ARGS], previous_directory[MAX_LINE_LENGTH];
size_t line_length = 0;
ssize_t read;
int i;
previous_directory[0] = '\0';

while (printf("HOME$ "), (read = getline(&line, &line_length, stdin)) != -1)
{
i = 0;
args[i] = strtok(line, " \n");
while (args[i])
args[++i] = strtok(NULL, " \n");
if (!args[0])
continue;
if (strcmp(args[0], "cd") == 0)
{
change_directory(args[1], previous_directory);
continue;
}
if (strcmp(args[0], "exit") == 0)
{
printf("[Disconnected...]\n");
exit(0);
}
if (strcmp(args[0], "env") == 0)
{
print_environment();
continue;
}
execute_command(args[0], args);
}
if (feof(stdin))
{
printf("[Disconnected...]\n");
exit(0);
}
perror("getline failed");
exit(1);
>>>>>>> a692efbd9c799684a470ac9f79a246e10c8d9267
}
