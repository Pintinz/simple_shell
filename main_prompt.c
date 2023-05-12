#include "shell.h"

/**
 * main - a function that prints all other functions
 * Return: it exits the code
 */

int main(void)
{
	char *cmd;
	char *args[MAX_CMD_LENGTH];

	while (1)
	{
		print_prompt();
		cmd = read_cmd();

		if (cmd == NULL || my_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		parse_cmd(cmd, args);
		execute_cmd(args);

		free(cmd);
	}

	exit(EXIT_SUCCESS);
}
