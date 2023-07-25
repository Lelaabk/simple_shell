#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

extern char **environ;

char *removeenter(char *input);
void _puts(char *str);
int execute(char **buff);
int _strlen(char *input);
void printprompt(char *username);
void prompt(char *arg);
void errhandler(char *cmd, char *location);
void _free(char *input);
int _strcmp(char *inp1, char *inp2);
int _access(char *cmd);
char *_trimmer(char *input);
void signalhandler(int sig);
char **_strtok(char *input);
char **removetokens(char *input, char *delim);
int readcmd(char *input, char *delim);
void _freeptr(char **ptr);
int _istoken(char input, char *delim);
char *getpath(char *input);
char *_strcat(char *a, char *src);
int _strcpy(char *input, char *dest);
char **input_checker(char **ptr, char *str1,char *arg);
void _putout(char *str);

char **_reallocptr(char **ptr_o, int old_size, int new_size);
int _isenv(char *_env, char *name);
char *_get_env_name(char *name,char **_environ);
char *create_s_env(char *name, char *value);
void set_env(char *name, char *value, char **_environ);
char *_strncat(char *dest, const char *src);
char *removecomments(char *input);
void *_realloc(void *prev, int old, int new); 

#endif
