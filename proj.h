#ifndef PROJ_H
#define PROJ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * struct list_s - Linked list of variables
 * @value: Value
 * @next: Pointer to next node
 *
 * Description: Generic linked list struct for variables.
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - Linked list of builtins
 * @name: Name of builtin
 * @p: Pointer to function
 *
 * Description: Struct for builtin functions.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompt(int fd, struct stat buf);
char *_getline(FILE *fp);
char **tokenizer(char *str);
char *_which(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void errors(int error);

/* Utility functions */
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

/* Prototypes for builtins */
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);

/* Prototypes for the helper functions for path linked list */
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

/* Prototypes for free functions */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);
#endif /* PROJ_H */

