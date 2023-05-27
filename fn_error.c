#include "proj.h"

/**
 * errors - Prints errors based on the given error number.
 * @error: The error number associated with the perror statement.
 * Return: void.
 */
void errors(int error)
{
	switch (error)
	{
	case 1: /* Writes fork error to stderr */
	write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
	perror("Error");
	break;

	case 2: /* Writes execve error to stderr */
	perror("Error");
	break;

	case 3: /* Writes malloc error to stderr */
	write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
	break;

	case 4: /* Writes empty path error to stderr */
	write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
	break;

	default:
	return;
	}
}

