#include "proj.h"

/**
 * _getline - Reads a line of input from a file.
 * @fp: The file pointer to read input from.
 * Return: The buffer containing the user input.
 */
char *_getline(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, fp);
	if (read == -1)
	{
	free(line);
	exit(EXIT_SUCCESS);
	}

	return (line);
}
