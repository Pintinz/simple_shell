#include "shell.h"

/**
 * update_pwd - a function that update
 * the current working directory
 */



void update_pwd(void)
{
	free(prev_directory);
	prev_directory = current_directory;
	current_directory = getcwd(NULL, 0);

	if (current_directory == NULL)
	{
		/* If getcwd() returns NULL, an error occurred*/
		perror("getcwd() error");
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_alias - a function that handles the alias command
 * @args: a double pointer used to pass any arguments to the aliacommand
 */

void execute_alias(char **args)
{
	if (args[1] == NULL)
	{
		print_aliases();
	}
	else if (args[2] == NULL)
	{
		char *name = args[1];
		char *value = get_alias_value(name);

		if (value == NULL)
		{
			const char *error_message = "Alias not found: ";
			size_t prefix_length = my_strlen(error_message);
			size_t name_length = my_strlen(name);
			size_t message_length = prefix_length + name_length + 1;

			char *error_output = malloc(message_length);

			if (error_output == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			my_strcpy(error_output, error_message);
			my_strcpy(error_output + prefix_length, name);
			error_output[message_length - 1] = '\n';

			if (write(STDERR_FILENO, error_output, message_length) == -1)
				perror("write");

			free(error_output);
		}
		else
		{
			size_t name_length = my_strlen(name);
			size_t value_length = my_strlen(value);
			size_t output_length = name_length + value_length + 5;

			char *output = malloc(output_length);

			if (output == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			my_strcpy(output, name);
			my_strcpy(output + name_length, "='");
			my_strcpy(output + name_length + 2, value);
			my_strcpy(output + name_length + 2 + value_length, "'\n");

			if (write(STDOUT_FILENO, output, output_length) == -1)
			{
				perror("write");
			}

			free(output);
		}
	}
	else
	{
		char *name = args[1];
		char *value = args[2];

		add_alias(name, value);
	}
}

/**
 * print_aliases - a function used to print or display aliases
 */

void print_aliases(void)
{
	int num_aliases = 0;
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		write(STDOUT_FILENO, aliases[i][0], my_strlen(aliases[i][0]));
		write(STDOUT_FILENO, "='", 2);
		write(STDOUT_FILENO, aliases[i][1], my_strlen(aliases[i][1]));
		write(STDOUT_FILENO, "'\n", 2);
	}
}

/**
 * add_alias - a function that creates an alias
 * @name: the name of the alias
 * @value: the value of the alias
 */

void add_alias(char *name, char *value)
{
	int num_aliases = 0;

	if (num_aliases < MAX_ALIASES)
	{
		aliases[num_aliases][0] = name;
		aliases[num_aliases][1] = value;
		num_aliases++;
	}
	else
	{
		const char *error_message_1 = "Maximum number of aliases reached\n";
		size_t message_length = my_strlen(error_message_1);

		if (write(STDERR_FILENO, error_message_1, message_length) == -1)
			perror("write");
	}
}

/**
 * get_alias_value - a function that retrieve the value of an alias
 * @name: the name of the alias
 * Return: it returns NULL
 */

char *get_alias_value(char *name)
{
	int num_aliases = 0;
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (my_strcmp(aliases[i][0], name) == 0)
			return (aliases[i][1]);
	}
	return (NULL);
}
