#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_CMD_LENGTH 100

void print_prompt(void);
char *read_cmd(void);
void parse_cmd(char *cmd, char **args);
void execute_cmd(char **args);
int str_cspn(const char *str, const char *reject);

#endif /* SHELL_H */
