#include "shell.h"

/**
 * my_exit - a function that Exits the shell
 * @info: a string containing arguments
 * Return: if info.argv[0] != "exit"
 */
int myExit(info_t *info)
{
	int exitCode;
	int m = 0;

	switch (info->argv[1] != NULL)
	{
	case 1:
	exitCode = _erratoi(info->argv[1]);
	switch (exitCode)
	{
	case -1:
	info->status = 2;
	display_error(info, "Illicit number: ");
	_eputs(info->argv[1]);
	_eputchar('\n');
	return (1);
	default:
	info->error_num = exitCode;
	return (-2);
	}
	default:
	info->error_num = -1;
	return (-2);
	}
}

/**
 * _cd - a function that changes the current directory
 * @info: a string containing arguments
 * Return: Always 0
 */
int _cd(info_t *info)
{
	char *currentDir, *newDir, buffer[1024];
	int chdirResult;

	currentDir = getcwd(buffer, 1024);
	if (!currentDir)
	_puts("TODO: >>getcwd failure emsg here<<\n");

	switch (info->argv[1] != NULL)
	{
	case 0:
	newDir = _getenv(info, "HOME=");
	chdirResult = chdir((newDir != NULL) ? newDir :
			(_getenv(info, "PWD=") ? _getenv(info, "PWD=") : "/"));
	break;

	default:
	if (_strcmp(info->argv[1], "-") == 0)
	{
	if (_getenv(info, "OLDPWD=") == NULL)
	{
	_puts(currentDir);
	_putchar('\n');
	return (1);
	}
	else
	{
	_puts(_getenv(info, "OLDPWD="));
	_putchar('\n');
	chdirResult = chdir((_getenv(info, "OLDPWD=")) ? _getenv(info, "OLDPWD=")
			: "/");
	}
	}
	else
	{
	chdirResult = chdir(info->argv[1]);
	}
	break;
	}

	if (chdirResult == -1)
	{
	display_error(info, "can't cd to ");
	_eputs(info->argv[1]);
	_eputchar('\n');
	}
	else
	{
	_setenv1(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv1(info, "PWD", getcwd(buffer, 1024));
	}

	return (0);
}

/**
 * _help - a function that Prints out help details
 * @info: a string containing arguments
 * Return: Always 0
 */
int _help(info_t *info)
{
	char **argArray;

	argArray = info->argv;
	_puts("help calls works. Function not yet implemented \n");

	switch (0)
	{
	case 0:
	_puts(*argArray);
	break;
	}

	return (0);
}
