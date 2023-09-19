#include "shell.h"

/**
 * print_environment - Print the environment variables
 */
void print_environment(void)
{
    int i;
    for (i = 0; environ[i] != NULL; i++)
    {
        _printf(environ[i]);
        _putchar('\n');
    }
}

/**
 * change_directory - Change the current working directory
 * @directory: The directory to change to
 * @previous_directory: Reference to the previous directory
 */
void change_directory(char *directory, char *previous_directory)
{
    if (directory == NULL)
    {
        chdir(getenv("HOME"));
    }
    else
    {
        if (_strcmp(directory, "-") == 0)
        {
            if (previous_directory[0] != '\0')
            {
                _printf(previous_directory);
                _putchar('\n');
                chdir(previous_directory);
            }
            else
            {
                _printf("No previous directory available.\n");
            }
        }
        else
        {
            getcwd(previous_directory, MAX_LINE_LENGTH);
            chdir(directory);
        }
    }
}

/**
 * handle_exit - Handle the exit command with the provided exit status
 * @args: The arguments for the exit command
 * @exit_status: Reference to the exit status variable
 */
void handle_exit(char *args[], int *exit_status)
{
    if (args[1] != NULL)
    {
        *exit_status = _atoi(args[1]);
    }
    _printf("[Disconnected...]\n");
    exit(*exit_status);
}

/**
 * execute_command - Execute the given command
 * @command: The command to execute
 * @args: The arguments for the command
 * @exit_status: Reference to the exit status variable
 */
void execute_command(char __attribute__((unused)) *command, char *args[], int *exit_status)
{
    pid_t pid = fork();
    int status;
    if (_strcmp(command, "exit") == 0)
    {
        handle_exit(args, exit_status);
    }
    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        char command_path[256];
        snprintf(command_path, 256, "/usr/bin/%s", args[0]);
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
    char *line = NULL, *args[MAX_ARGS], previous_directory[MAX_LINE_LENGTH];
    size_t line_length = 0;
    ssize_t read;
    int i, exit_status = 0;
    previous_directory[0] = '\0';

    while (_printf("HOME$ "), (read = getline(&line, &line_length, stdin)) != -1)
    {
        i = 0;
        args[i] = strtok(line, " \n");
        while (args[i])
            args[++i] = strtok(NULL, " \n");
        if (!args[0])
            continue;
        if (_strcmp(args[0], "cd") == 0)
        {
<<<<<<< HEAD
            change_directory(args[1], previous_directory);
            continue;
=======
            if (args[1] != NULL)
            {
                exit_status = _atoi(args[1]); 
            }
            _printf("[Disconnected...]\n");
            exit(exit_status);  
>>>>>>> 439a290bbccc036d8d774a24e0dd6f19628e97a4
        }
        if (_strcmp(args[0], "exit") == 0)
        {
            handle_exit(args, &exit_status);
        }
        if (_strcmp(args[0], "env") == 0)
        {
            print_environment();
            continue;
        }
        execute_command(args[0], args, &exit_status);
    }
    if (read == -1)
    {
        _printf("[Disconnected...]\n");
        exit(0);
    }
    perror("getline failed");
    exit(1);
}
