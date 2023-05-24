#include "shell.h"


/**
 * my_getline - a function that gets a command from the environment
 * @lineptr: a double pointer to a line
 * @n: number of variables
 * Return: it return the 1 if successful
 */

ssize_t my_getline(char **lineptr, size_t *n)
{
	static char buffer[BUFFER_SIZE];
	 ssize_t buffer_pos = 0;
	 ssize_t buffer_size = 0;
	/*ssize_t bytesRead;*/
	ssize_t totalBytesRead;
	char c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);

		if (*lineptr == NULL)
		{
			return (-1); /*Error: memory allocation failed*/
		}
	}

	/*bytesRead = 0;*/
	totalBytesRead = 0;

	while (1)
	{
		/* Check if more data needs to be read into the buffer*/
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_pos = 0;


			if (buffer_size <= 0)
			{
				if (totalBytesRead == 0)
				{
					return (-1); /* Error: no input read */
				}
				else
				{
					break; /* Return the current line */
				}
			}
		}

		c = buffer[buffer_pos++];

		(*lineptr)[totalBytesRead++] = c;

		/*Check if more space is needed in lineptr*/
		if ((size_t)totalBytesRead >= *n - 1)
		{
			if (!resize_buffer(lineptr, n))
			{
				return (-1); /* Error: memory allocation failed*/
			}
		}

		if (c == '\n')
		{
			break;
		}
	}

	/* Add null terminator*/
	(*lineptr)[totalBytesRead] = '\0';

	return (totalBytesRead);
}


/**
 * resize_buffer - a function that resize a buffer
 * @buffer: a double pointer
 * @size: the size of the buffer
 * Return: it reurns the resize form
 */

int resize_buffer(char **buffer, size_t *size)
{
	size_t newSize = *size + BUFFER_SIZE;
	char *newBuffer = malloc(newSize);

	if (newBuffer == NULL)
	{
		return (0); /* Error: memory allocation failed*/
	}

	my_memcpy(newBuffer, *buffer, *size);
	free(*buffer);
	*buffer = newBuffer;
	*size = newSize;
	return (1); /* Success*/
}


/**
 * my_getenv - a function that gets inputs in the environment
 * @name: a pointer that represents the name of the environment
 * @envp: a pointer that represent the environment variables
 * Return: it returns NULL
 */

char *my_getenv(const char *name, char **envp)
{
	int i;
	size_t name_len;

	if (name == NULL || envp == NULL)
	{
		return (NULL);
	}

	name_len = my_strlen(name);

	for (i = 0; envp[i] != NULL; i++)
	{
		if (my_strncmp(envp[i], name, name_len) == 0 && envp[i][name_len] == '=')
		{
			return (envp[i] + name_len + 1);
		}
	}
	return (NULL);
}
