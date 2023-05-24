#include "honor.h"

/**
 * free_all - reallocates memory  space at end of main loop
 * @chanks:are pointers to the  tokens array
 * @path: pointer to path variables
 * @line: pointer to user input buffer
 * @fullpath: pointer to full path
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void free_all(char **chanks, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(chanks);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - frees double pointers.
 * @array: double pointer to be free.
 * @length: length of double pointers.
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int num;

	num = 0;
	while (num < length)
	{
		free(array[num]);
		num++;
	}
	free(array);
}
