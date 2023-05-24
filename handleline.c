#include "honor.h"

int main(void)
{
	char *line;
	char *fullpath = NULL;
	char *path = NULL;
	char **tokens;
	size_t bufsize = 0;

	while (1)
	{
	if (isatty(STDIN_FILENO))
	_puts(PROMPT);

	if (getline(&line, &bufsize, stdin) == -1)
	{
	if (isatty(STDIN_FILENO))
	_puts("\n");
	break;
	}

	tokens = tokenizer(line);

	if (tokens[0] != NULL)
	{
	fullpath = _which(tokens[0], fullpath, path);

	if (fullpath == NULL)
	{
	errors(4);
	free_all(tokens, path, line, fullpath, 0);
	continue;
	}

	if (child(fullpath, tokens) == -1)
	{
	errors(2);
	free_all(tokens, path, line, fullpath, 1);
	exit(EXIT_FAILURE);
	}
	}

	free_all(tokens, path, line, fullpath, 1);
	}

	free(line);
	return (0);
}

