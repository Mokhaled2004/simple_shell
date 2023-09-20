#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
/* global variable to access environment */

extern char **environ;

int infinite_loop(char *program_path);


void sh(char *str, char **args, char **paths, int p_cnt,
char *p_path,  int *st);

int _full_path(char *argument);
char *_small_path(char *argument, char **path);

int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strccat(char *str1, char *str2);
char *_strcp(char *str);
void _rcomment(char *str);

char **split(char *string, char *breaks);
int _atoi(char *s);
char *_clStr(char *str);
ssize_t _getline(char **string, size_t *string_size);

char *_strccat2(char *str1, char *str2);

char **_getallpaths(void);
char *_getenv(char *string);

void _before_exec(char **args, char **paths, int p_cnt, char *p_path, int *st);
void _execution(char **arguments, int *st);

char **_strings(char **str);
void _array_of_pointers(char **array);
void _idx_from_array(int idx, char **array);

int h_exit(char **args, char *str, char **paths, int *st, char *pth, int p);
int _builtin(char **arguments);

int _variable(char **arguments);
int _env_variable(char **arguments);
int _cd(char **arguments);
int _env(char **arguments);

void _all(char **arguments, char *string, char **paths);

void execve_error(char *msg, char *command, int count, char *p_path);
/*number helper functions*/
void _num(unsigned int n);
int _postive(char *str);
int set_env(char *key, char *value);
#endif
