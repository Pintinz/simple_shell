#include "proj.h"

/**
 * print_prompt - Checks the mode and prints a prompt if in interactive mode
 * @fd: File descriptor
 * @buf: Buffer
 **/
void print_prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		print_string(PROMPT);
}

/**
 * print_string - Prints a string without a newline character
 * @str: String to print
 * Return: void
 */
void print_string(char *str)
{
	unsigned int length;

	length = string_length(str);

	write(STDOUT_FILENO, str, length);
}

