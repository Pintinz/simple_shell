#include "proj.h"

/**
 * free_all - Frees all dynamically allocated memory at the end of the main loop.
 * @tokens: Pointer to the tokens array.
 * @path: Pointer to the path variable.
 * @line: Pointer to the user input buffer.
 * @fullpath: Pointer to the full path.
 * @flag: Flag marking if fullpath was dynamically allocated.
 * Return: void.
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
	free(fullpath);
}

/**
 * free_dp - Frees a double pointer.
 * @array: Double pointer to free.
 * @length: Length of the double pointer.
 * Return: void.
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
	free(array[i]);
	i++;
	}
	free(array);
}

