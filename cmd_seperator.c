#include "shell.h"

/**
 * execute_command - Execute a single command
 * @tokens: Array of tokens containing the command and arguments
 * Return: Status of the command execution
 */
int execute_command(char **tokens)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: Failed to create child process\n");
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execvp(tokens[0], tokens) == -1)
		{
			perror("Error: Command execution failed\n");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* Parent process */
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
	}
}

/**
 * execute_commands - Execute multiple commands separated by ";"
 * @commands: Array of command strings
 * Return: Status of the last command execution
 */
int execute_commands(char **commands)
{
	int status = 0;
	int i = 0;
	char **tokens;

	while (commands[i] != NULL)
	{
		tokens = tokenizer(commands[i]);
		if (tokens[0] != NULL)
		{
			status = execute_command(tokens);
			free(tokens);
		}
		i++;
	}

	return status;
}

int main(void)
{
	/* Rest of the code */

	while (TRUE)
	{
		/* Rest of the main function */
		/* ... */

		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);

		if (builtin_status == 0)
			continue;

		/* Execute multiple commands separated by ";" */
		char **commands = tokenizer(line);
		int command_status = execute_commands(commands);
		free(commands);

		if (command_status == -1)
			errors(2);

		/* Rest of the main function */
		/* ... */
	}

	return (0);
}

