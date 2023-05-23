#include "shell.h"

/**
 * print_prompt - A function that prints a prompt
 */

void print_prompt(void)
{
	if (write(STDOUT_FILENO, "simple_shell$ ", 14) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}

/**
 * read_cmd - A function that reads a command.
 * Return: it returns cmd
 */

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t cmd_size = 0;

	if (my_getline(&cmd, &cmd_size) == -1)
	{
		if (feof(stdin))
		{
			return (NULL);
		}
		perror("my_getline");
		exit(EXIT_FAILURE);
	}
	/* Remove the trailing newline character*/
	cmd[str_cspn(cmd, "\n")] = '\0';

	return (cmd);
}
/**
 * parse_cmd - A function that takes a string argument (the user's input)
 *	and extracts the command and its arguments.
 * @cmd: the command to be extracted
 * @args: the arguments taken
 */
void parse_cmd(char *cmd, char **args)
{
	char *token_cmd = strtok(cmd, " ");
	int i;

	for (i = 0; token_cmd != NULL; i++)
{
	args[i] = token_cmd;
	token_cmd = strtok(NULL, " ");
}
	args[i] = NULL;
}
/**
 * execute_cmd - A function that takes an argument, args
 * @args: a pointer to a list of strings
 */
void execute_cmd(char **args)
{
	int status;
	char *envp[] = { NULL };/* Empty environment variable array*/
	pid_t pid = fork();

	switch (pid)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
		case 0:
			/* Child process execution*/

			if (execve(args[0], args, envp) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			break;
		default:
			/* Parent process execution*/
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
	}
}

/**
 * execute_variable_replacement - a function that performs variable replacement
 * @args: an array of string that represent cmd-line arguments
 * @envp: an array of string that represent the env variables
 */

void execute_variable_replacement(char **args, char **envp)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		char *env_var = my_strchr(args[i], '$');

		if (env_var != NULL)
		{
			char *var_name = env_var + 1;
			char *var_value = my_getenv(var_name, envp);

			if (var_value != NULL)
			{
				size_t arg_len = my_strlen(args[i]);
				size_t var_len = my_strlen(var_value);
				size_t new_arg_len = arg_len - 1 + var_len;

				char *new_arg = (char *)malloc(new_arg_len + 1);

				my_strcpy(new_arg, args[i]);
				my_strcpy(new_arg + arg_len - 1, var_value);

				args[i] = new_arg;
			}
		}
	}
}
