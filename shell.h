#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <errno.h>

#define BUFFER_SIZE 1024

#define MAX_ALIASES 20

#define MAX_CMD_LENGTH 10

#define MAX_ARGUMENTS 10

/*Global variables*/
char *prev_directory;
char *current_directory;
char *home_directory;
char *aliases[MAX_ALIASES][2];
/*static int num_aliases = 0;*/

void print_prompt(void);
char *read_cmd(void);
int my_atoi(const char *str);
int resize_buffer(char **buffer, size_t *size);
/**
 * my_getline - a function that gets a command from the environment
 * @lineptr: a double pointer to a line
 * @n: number of variables
 * Return: it return the 1 if successful
 */

ssize_t my_getline(char **lineptr, size_t *n);
void parse_cmd(char *cmd, char **args);
void execute_cmd(char **args);
void execute_exit(char **args);
void execute_env(void);
int str_cspn(const char *str, const char *reject);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *s);
void *my_memcpy(void *dest, const void *src, size_t n);
size_t my_strlen(const char *str);
char *my_getenv(const char *name, char **envp);
void execute_variable_replacement(char **args, char **envp);
char *my_strchr(const char *str, char target);
int my_strncmp(const char *str1, const char *str2, size_t n);
void my_strcpy(char *dest, const char *src);
void execute_cd(char **args);
void update_pwd(void);
void execute_alias(char **args);
void print_aliases(void);
void add_alias(char *name, char *value);
char *get_alias_value(char *name);
void execute_setenv(char **args);
void execute_unsetenv(char **args);

#endif /* SHELL_H */
