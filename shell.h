#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*read OR write buffers */
#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

/* coMmand chaining */
#define COMMAND_NORM	0
#define COMMAND_OR	1
#define COMMAND_AND	2
#define COMMAND_CHAIN	3

/* convert number TO DIFFERENT CASES */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* if using system getline function return 1  */
#define U_GETLINE 0 /*USE_GETLINE/
#define U_STRTOK 0 /*USE_STRTOK*/

#define HISTORY_FILE	".simple_shell_history" /*HIST_FILE*/
#define HISTORY_MAX	4096  /*HIST_MAX*/

extern char **env; /*environ*/


/**
 * struct list_string - a function with a singly linked list
 * @num: the number
 * @str: a string variable
 * @next: points to the next node in the array
 */
typedef struct list_string
{
	int num;
	char *str;
	struct list_string *next;
} list_t;

/**
 *struct pass_cmd - contains an arguements to pass into a function
 *@args: a string realised from getline that contains arguements
 *@argv: strings arrays generated from arg
 *@path_cmd: a path for the current command
 *@argc: the number of argument count
 *@line_num_count: the error line count
 *@error_num: the error code to exit
 *@line_count_flag: counts the line of input
 *@f_name: the filename of the program
 *@env: local copy of environ
 *@environ: custom modified copy of environ
 *@history: the history node of the array
 *@alias: the alias node of the array
 *@environ_changed: environ changed
 *@status: returns status of the last executed command
 *@cmd_buffer: the address of pointer of cmd_buf
 *@cmd_buffer_type: CMD_type ||, &&, ;
 *@read_fd: the fd from which to read line input
 *@history_count: the number of history line count
 */
typedef struct pass_cmd /*pass_info*/
{
	char *args; /*arg*/
	char **argv;
	char *path_cmd; /*path*/
	int argc;
	unsigned int line_num_count; /*line_count*/
	int error_num; /*err_num*/
	int line_count_flag; 
	char *f_name; /*fname*/
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int environ_changed; /*env_changed*/
	int status;

	char **cmd_buffer; /*cmd_buf*/
	int cmd_buffer_type; /*cmd_buf_type*/
	int read_fd; /*readfd*/
	int history_count; /*hist_count*/
} info_t;

#define INFO_INITIALS \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0} /*INFO_INIT*/

/**
 *struct built_in - AN ARRAY that contains a builtin string
 *@nature: the builtin command type
 *@func: the function of the builtin
 */
typedef struct built_in /*builtin*/
{
	char *nature; /*type*/
	int (*func)(info_t *);
} built_table; /*builtin_table*/


/* find_cmd.c */
int hsh(info_t *, char **);
int find_builtin_cmd(info_t *); /*find_builtin*/
void find_cmd_func(info_t *); /*find_cmd*/
void fork_cmd_func(info_t *); /*fork_cmd*/

/* cmd_parser.c */
int is_cmd_func(info_t *, char *); /*is_cmd*/
char *duplicate_chars(char *, int, int); /*dup_chars*/
char *find_path_cmd(info_t *, char *, char *); /*find_path*/

/* loop_hsh.c */
int loop_hsh(char **); /*loophsh*/

/* custom_func.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char m, int d); /* char c, int fd*/
int _putsfd(char *str, int d); /*char *str, int fd*/

/* custom_strings.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* 1-custom_strings.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* 2-custom_strings.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* tokenize_func.c */
char **strtow1(char *, char *);
char **strtow2(char *, char);

/* realloc_func.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* free_memory.c */
int vfree(void **); /*bfree*/

/* check_atoi.c */
int check_interactive_mode(info_t *); /*interactive*/
int check_delim(char, char *); /*is_delim*/
int check_alpha(int); /*_isalpha*/
int _atoi(char *);

/* error_func.c */
int _erratoi(char *);
void display_error(info_t *, char *); /*print_error*/
int display_decimal(int, int); /*print_d*/
char *convert_digit(long int, int, int); /*convert_number*/
void rm_comments(char *); /*remove_comments*/

/* builtin.c */
int my_exit(info_t *); /*_myexit*/
int _cd(info_t *); /*_mycd*/
int _help(info_t *); /*_myhelp*/

/*1-builtin.c */
int _history(info_t *); /*_myhistory*/
int _alias(info_t *); /*_myalias*/
int display_alias(list_t *); /*print_alias*/
int put_alias(info_t *, char *); /*set_alias*/
int unput_alias(info_t *, char *); /*unset_alias*/

/*getline_func.c */
ssize_t get_input_func(info_t *); /*get_imput*/
int _getline(info_t *, char **, size_t *);
void sigint_handler(int); /*sigintHandler*/

/* getinfo_func.c */
void clear_cmd(info_t *); /*clear_info*/
void set_cmd(info_t *, char **); /*set_info*/
void free_cmd(info_t *, int); /*free_info*/

/* environ_func.c */
char *_getenv(info_t *, const char *);
int _env(info_t *); /*_myenv*/
int _setenv2(info_t *); /*_mysetenv*/
int _unsetenv2(info_t *); /*_myunsetenv*/
int generate_env_list(info_t *); /*populate_env_list*/

/* getenv_func.c */
char **get_env(info_t *); /*get_environ*/
int _unsetenv1(info_t *, char *); /*_unsetenv*/
int _setenv1(info_t *, char *, char *);/*_setenv*/

/* history_func.c */
char *get_hist(info_t *); /*get_history_file*/
int write_hist(info_t *); /*write_history*/
int read_hist(info_t *); /*read_history*/
int create_history_list(info_t *, char *, int); /*build_history_list*/
int renum_history(info_t *info); /*renumber_history*/

/* lists_func.c */
list_t *add_more_node(list_t **, const char *, int); /*add_node*/
list_t *end_add_node(list_t **, const char *, int); /*add_note_end*/
size_t display_list_str(const list_t *); /*print_list_str*/
int remove_index_node(list_t **, unsigned int); /*delete_node_at_index*/
void free_list(list_t **); 
 
/* 1-lists_func.c */
size_t length_list(const list_t *); /*length_list*/
char **convert_list_strings(list_t *); /*list_to_strings*/
size_t display_list(const list_t *); /* print_list*/
list_t *node_beginning(list_t *, char *, char); /*node_starts_with*/
ssize_t fetch_node_index(list_t *, list_t *); /*get_node_index*/

/* vars_func.c */
int _chain(info_t *, char *, size_t *); /*is_chain*/
void _check(info_t *, char *, size_t *, size_t, size_t); /*check_chain*/
int rep_aliases(info_t *); /*replace_alias*/
int rep_variables(info_t *); /*replace_vars*/
int rep_string(char **, char *); /*replace_string*/

#endif
