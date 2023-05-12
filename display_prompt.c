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

	if (getline(&cmd, &cmd_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			return (NULL);
		}
		perror("getline");
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
 * execute_cmd - A function that takes an argument and executes it
 * @args: arguments passed to be executed
 */

void execute_cmd(char **args)
{
	pid_t pid = fork();

	switch (pid)
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			break;
		case 0:
			/* Child process execution*/
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			break;
		default:
			/* Parent process execution*/
			if (waitpid(pid, NULL, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			break;
	}
}
