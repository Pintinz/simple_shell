#include "shell.h"

/**
 * execute_exit - a function that is responsible for
 * executing an exit action
 * @args: a double pointer that passes any arguments
 * to the exit command
 */

void execute_exit(char **args)
{
	/*Checks if an argument is provided for the exit command*/
	if (args[1] != NULL)
	{
		/*Convert the argument to an integer*/
		int exit_code = my_atoi(args[1]);

		/*Terminate the program with the specified exit code*/
		exit(exit_code);
	}
	exit(EXIT_SUCCESS);
}

/**
 * execute_env - a function responsible for handling
 * environmental variables
 */

void execute_env(void)
{
	char **env/* = environ*/;
	size_t env_len;
	char newline = '\n';

	while (*env)
	{
		env_len = my_strlen(*env);
		write(STDOUT_FILENO, *env, env_len);
		write(STDOUT_FILENO, &newline, 1);
		env++;
	}
}


/**
 * execute_cd - a function that handles
 * the change directory command
 * @args: a double pointer used to pass any arguments to the cd
 */


void execute_cd(char **args)
{
	if (args[1] == NULL)
	{
		/* Change to home directory if no argument is provided*/
		chdir(home_directory);
	}
	else if (my_strcmp(args[1], "-") == 0)
	{
		/*Change to previous directory if argument is "-"*/
		if (prev_directory != NULL)
		{
			char *temp;

			chdir(prev_directory);

			temp = current_directory;

			current_directory = prev_directory;
			prev_directory = temp;
		}
	}
	else
	{
		/* Change to the specified directory*/
		char *new_directory = args[1];

		if (chdir(new_directory) != 0)
		{
			char error_msg[MAX_CMD_LENGTH + 16] = "cd: ";
			char error_suffix[] = ": No such file or directory\n";

			my_strcpy(error_msg + 4, new_directory);
			my_strcpy(error_msg + 4 + my_strlen(new_directory), error_suffix);
			write(STDERR_FILENO, error_msg, my_strlen(error_msg));
		}
		else
		{
			update_pwd();
		}
	}
}
