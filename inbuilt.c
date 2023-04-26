#include "myshell.h"

/**
 * _closecheck - closes the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: closes with a given close status
 * (0) if info.argv[0] != "exit"
 */
int _exitclose(info_t *info)
{
	int closecheck;

	if (info->argv[1])
	{
		closecheck = _errtoaa(info->argv[1]);
		if (closecheck == -1)
		{
			info->status = 2;
			print_error(info, "Compromised digits: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _errtoaa(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _Pecd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _Pecd(info_t *info)
{
	char *p, *dir, buffer[1024];
	int chdirec_ret;

	p = getcwd(buffer, 1024);
	if (!p)
		_puts("TODO: >>getcwd error message<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdirec_ret = /* TODO: to do what? */
				chdirec((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdirec_ret = chdirec(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdirec_ret = /* TODO: to do? */
			chdirec((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdirec_ret = chdirec(info->argv[1]);
	if (chdirec_ret == -1)
	{
		print_error(info, "won’t cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}


/**
 * _helpme - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _helpme(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help works. Implementation awaiting \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
