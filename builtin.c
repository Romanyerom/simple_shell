#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit argument */
	{
		exitcheck = _erratoi(info->argv[1]);

		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exitcheck;
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int _mycd(info_t *info)
{
	char *dir, buffer[1024];
	int chdir_ret;

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");

		if (!dir)
		{
			/* TODO: Handle error here, when HOME is not set */
			_puts("HOME not set\n");
			return (1);
		}
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		dir = _getenv(info, "OLDPWD=");

		if (!dir)
		{
			/* TODO: Handle error here, when OLDPWD is not set */
			_puts("OLDPWD not set\n");
			return (1);
		}
	}
	else
		dir = info->argv[1];

	chdir_ret = chdir(dir);

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(dir);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}

	return (0);
}

/**
 * _myhelp - displays help information
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	/* TODO: Implement help functionality here */
	_puts("Help message goes here\n");

	/* The condition below appears to be redundant and can be removed */
	/* if (0) */
	/* 	_puts(*arg_array); */ /* temp att_unused workaround */

	return (0);
}
