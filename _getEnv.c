#include "honor.h"
/**
 * _getenv - gets a variabl that shows the envirnment
 * @name: environment variable to getinfo
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, num;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	environ_copy = NULL;
	environ_copy = copy_env(environ_copy, environ_length);

	length = _strlen((char *)name);
	num = 0;
	while (environ_copy[num] != NULL)
	{
		variable = environ_copy[num];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (*value == '\0')
			{
				errors(4);
				exit(EXIT_FAILURE);
			}
			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(environ_copy, environ_length);
			return (path);
		}
		num++;
	}
	return (NULL);
}

/**
 * copy_env - copies the env variables
 * @environ_copy:a ponter  pointer to copy  environment variables..
 * @environ_length: length of env variable
 * Return: double pointer to copy of env variable
 */
char **copy_env(char **environ_copy, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int num;

	environ_copy = malloc(sizeof(char **) * (environ_length));
	if (environ_copy == NULL)
	{
		errors(3);
		return (NULL);
	}

	num = 0;
	while (num < environ_length)
	{
		variable = environ[num];
		variable_length = _strlen(variable);

		environ_copy[num] = malloc(sizeof(char) * variable_length + 1);
		if (environ_copy[num] == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(environ_copy[num], environ[num]);
		num++;
	}

	return (environ_copy);
}
