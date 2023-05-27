#include "proj.h"

/**
 * tokenize_string - Tokenizes a string
 * @str: User input string
 * Return: Pointer to an array of tokens
 */
char **tokenize_string(char *str)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char *) * BUFFER);
	if (tokens == NULL)
	{
	handle_errors(3);
	exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
	tokens[i] = token;
	token = strtok(NULL, "\n\t\r ");
	i++;
	}

	tokens[i] = NULL;

	return (tokens);
}

