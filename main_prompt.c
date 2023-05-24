#include "shell.h"
/**
 * main - the main entry point
 * @argc: an integer that represents the number of command-line
 * arguments passed
 * @argv: A pointer to an array of strings
 * @envp: the environment variable
 * Return: it exits the program
 */



int main(int argc, char **argv, char **envp)
{
	char *cmd;
	char *args[MAX_ARGUMENTS];
	/*Initialize global variables*/
	prev_directory = NULL;
	current_directory = NULL;
	home_directory = my_getenv("HOME", envp);
	update_pwd();

	/*Handle file mode*/
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);

		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	while (1)
	{
		print_prompt();
		cmd = read_cmd();

		if (cmd == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		parse_cmd(cmd, args);
		execute_variable_replacement(args, envp);

		if (my_strcmp(args[0], "exit") == 0)
			execute_exit(args);
		else if (my_strcmp(args[0], "env") == 0)
			execute_env();
		else if (my_strcmp(args[0], "cd") == 0)
			execute_cd(args);
		else if (my_strcmp(args[0], "alias") == 0)
			execute_alias(args);
		else if (my_strcmp(args[0], "setenv") == 0)
			execute_setenv(args);
		else if (my_strcmp(args[0], "unsetenv") == 0)
			execute_unsetenv(args);
		else
			execute_cmd(args);
		free(cmd);
	}
		exit(EXIT_SUCCESS);
}
