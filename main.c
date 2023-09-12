#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

int main() {
    char* line = NULL;
    size_t line_length = 0;
    char* args[MAX_ARGS];
    int status;

    while (1) {
        printf("$ ");
        ssize_t read = getline(&line, &line_length, stdin);
        if (read == -1) {
            if (feof(stdin)) {
                printf("[Disconnected...]\n");
                free(line);
                exit(0);
            }
            else {
                perror("getline failed");
                free(line);
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
            chdir(args[1]);
            continue;
        }
        else if (strcmp(args[0], "exit") == 0) {
            printf("[Disconnected...]\n");
            free(line);
            exit(0);
        }

        // create a child process and execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            free(line);
            exit(1);
        }
        else if (pid == 0) {
            // child process
            execve(args[0], args, NULL);
            perror("execve failed");
            free(line);
            exit(1);
        }
        else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
