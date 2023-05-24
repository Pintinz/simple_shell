#include "honor.h"

/**
 * tokenizer - breaks  string into small chanks
 * @str:  input from user
 * Return: pointer to array ofthe  tokens
 */
char **tokenizer(char *str)
{
	char **tokens;
	char *chanks;
	unsigned int num;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	chanks = strtok(str, "\n\t\r ");

	num = 0;
	while (chanks != NULL)
	{
		tokens[num] = chanks;
		chanks = strtok(NULL, "\n\t\r ");
		num++;
	}

	tokens[num] = NULL;

	return (tokens);
}
