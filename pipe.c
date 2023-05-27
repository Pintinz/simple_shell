#include "shell.h"

int execute_command(char **tokens)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error: Failed to create child process\n");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execvp(tokens[0], tokens) == -1)
		{
			perror("Error: Command execution failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}

	return (-1);
}

int execute_logical_operator(char **tokens, char *operator)
{
	int status = execute_command(tokens);

	if ((strcmp(operator, "&&") == 0 && status != 0) ||
		(strcmp(operator, "||") == 0 && status == 0))
		return (0);

	return (1);
}

int execute_commands(char **commands)
{
	int status = 0;
	char *operators[] = {"&&", "||"};
	int num_operators = sizeof(operators) / sizeof(operators[0]);

	for (int i = 0; commands[i] != NULL; i++)
	{
		int j = 0;
		char *command = commands[i];

		while (j < num_operators)
		{
			char *operator = strstr(command, operators[j]);

			if (operator != NULL)
			{
				*operator = '\0';
				char **tokens = tokenizer(command);

				if (tokens[0] != NULL)
				{
					status = execute_logical_operator(tokens, operators[j]);
					free(tokens);
				}

				command = operator + strlen(operators[j]) + 1;
				j = -1;
			}
			j++;
		}

		if (command[0] != '\0')
		{
			char **tokens = tokenizer(command);

			if (tokens[0] != NULL)
			{
				status = execute_logical_operator(tokens, "");
				free(tokens);
			}
		}
	}

	return (status);
}

int main(void)
{
	while (TRUE)
	{
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);

		if (builtin_status == 0)
			continue;

		char **commands = tokenizer(line);
		int command_status = execute_commands(commands);
		free(commands);

		if (command_status == -1)
			errors(2);
	}

	return (0);
}

