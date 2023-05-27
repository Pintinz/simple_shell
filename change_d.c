#include "shell.h"

/**
 * builtin_cd - Change the current directory of the process
 * @tokens: Array of tokens containing the command and arguments
 * Return: Always returns 1 to continue execution
 */
int builtin_cd(char **tokens)
{
	char *path;

	if (tokens[1] == NULL || _strcmp(tokens[1], "-", _strlen(tokens[1])) == 0)
	{
		path = _getenv("OLDPWD");
		if (path == NULL)
		{
			perror("Error: OLDPWD not set\n");
			return (1);
		}
	}
	else
	{
		path = tokens[1];
	}

	if (chdir(path) == -1)
	{
		perror("Error: Failed to change directory\n");
		return (1);
	}

	char *cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("Error: Failed to get current directory\n");
		return (1);
	}

	if (setenv("OLDPWD", _getenv("PWD"), 1) == -1)
	{
		perror("Error: Failed to set OLDPWD\n");
		return (1);
	}

	if (setenv("PWD", cwd, 1) == -1)
	{
		perror("Error: Failed to set PWD\n");
		return (1);
	}

	free(cwd);
	return (1);
}

int main(void)
{
	/* Rest of the code */

	built_s builtin[] = {
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{"cd", builtin_cd}, // Added cd builtin
		/* Add more builtins here */
	};
	int num_builtins = shell_num_builtins(builtin);
	int i;

	while (TRUE)
	{
		/* Rest of the main function */
		/* ... */

		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);

		/* Rest of the main function */
		/* ... */
	}

	return (0);
}

