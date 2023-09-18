#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 80
#define MAX_ARGV 10
#define MAX_ARGS 10
#define BUFFER_SIZE 1024

extern char **environ;

void print_environmentt(void);
void change_directory(char *directory, char *previous_directory);
void execute_command(char *command, char *args[]);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int _getline(char **line, size_t *line_length, FILE *input_stream);
void _printf(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _snprintf(char *str, size_t size, char *str1, char *str2);
size_t _strlen(const char *str);
#endif
