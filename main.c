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
<<<<<<< HEAD

int main() {
    char *line = NULL;
    size_t line_length = 0;
    char *args[MAX_ARGS];
    int status;
    char previous_directory[MAX_LINE_LENGTH]; // Store the previous directory

    while (1) {
        printf("HOME$ ");
        ssize_t read = getline(&line, &line_length, stdin);
        if (read == -1) {
            if (feof(stdin)) {
                // Ctrl+D was pressed, exit the shell
                printf("[Disconnected...]\n");
                exit(0);
            } else {
                perror("getline failed");
                exit(1);
            }
        }

        // tokenize the input
        int i = 0;
        args[i] = strtok(line, " \n");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " \n");
        }
        args[i] = NULL;

        // handle built-in commands
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                // No arguments provided, go to the home directory
                chdir(getenv("HOME"));
            } else {
                if (strcmp(args[1], "-") == 0) {
                    // "-" argument provided, go to the previous directory
                    if (previous_directory[0] != '\0') {
                        printf("%s\n", previous_directory);
                        chdir(previous_directory);
                    } else {
                        printf("No previous directory available.\n");
                    }
                } else {
                    // Other directory provided, change to that directory
                    getcwd(previous_directory, sizeof(previous_directory));
                    chdir(args[1]);
                }
            }
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            printf("[Disconnected...]\n");
            exit(0);
        } else if (strcmp(args[0], "env") == 0) {
            print_environment();
            continue;
        }

        // create a child process and execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // child process
           
            char command_path[256];
            snprintf(command_path, sizeof(command_path), "/usr/bin/%s", args[0]);
            execve(command_path, args, environ);
            perror("execve failed");
            exit(1);
        } else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    free(line);
    return 0;
=======
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
>>>>>>> ab81a577e7c5cbfa301f702f6bd55eb2dfcb0366
}
