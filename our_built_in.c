#include "our_shell.h"

/**
* our_exit - exit program with status
* @data: struct for the program's data
* Return: zero if sucess, or other number if its declared in the arguments
*/
int our_exit(data_of_program *data)
{
int k;

if (data->tokens[1] != NULL)
{
for (k = 0; data->tokens[1][k]; k++)
if ((data->tokens[1][k] < '0' || data->tokens[1][k] > '9')
&& data->tokens[1][k] != '+')
{
errno = 2;
return (2);
}
errno = _atoi(data->tokens[1]);
}
free_many(data);
exit(errno);
}

/**
* our_cd - change the current directory
* @data: struct for the program's data
* Return: zero if sucess, or other number if its declared in the arguments
*/
int our_cd(data_of_program *data)
{
char *dir_home = our_get_env("HOME", data), *dir_old = NULL;
char old_dir[128] = {0};
int error = 0;

if (data->tokens[1])
{
if (our_str_cmp(data->tokens[1], "-", 0))
{
dir_old = our_get_env("OLDPWD", data);
if (dir_old)
error = our_set_dir(data, dir_old);
our_print(our_get_env("PWD", data));
our_print("\n");

return (error);
}
else
{
return (our_set_dir(data, data->tokens[1]));
}
}
else
{
if (!dir_home)
dir_home = getcwd(old_dir, 128);

return (our_set_dir(data, dir_home));
}
return (0);
}

/**
* our_set_dir - set the work directory
* @data: struct for the program's data
* @new_dir: path to be set as work directory
* Return: zero if sucess, or other number if its declared in the arguments
*/
int our_set_dir(data_of_program *data, char *new_dir)
{
char old_dir[128] = {0};
int error = 0;

getcwd(old_dir, 128);

if (!our_str_cmp(old_dir, new_dir, 0))
{
error = chdir(new_dir);
if (error == -1)
{
error = 2;
return (3);
}
_set_env("PWD", new_dir, data);
}
_set_env("OLDPWD", old_dir, data);
return (0);
}

/**
* our_bui_help - shows the environment shell runs
* @data: struct for the program's data
* Return: zero if sucess, or other number if its declared in the arguments
*/
int our_bui_help(data_of_program *data)
{
int k, length = 0;
char *mensajes[6] = {NULL};

mensajes[0] = HELP_MSG;

if (data->tokens[1] == NULL)
{
our_print(mensajes[0] + 6);
return (1);
}
if (data->tokens[2] != NULL)
{
errno = E2BIG;
perror(data->command_name);
return (5);
}
mensajes[1] = HELP_EXIT_MSG;
mensajes[2] = HELP_ENV_MSG;
mensajes[3] = HELP_SETENV_MSG;
mensajes[4] = HELP_UNSETENV_MSG;
mensajes[5] = HELP_CD_MSG;

for (k = 0; mensajes[k]; k++)
{
length = our_str_len(data->tokens[1]);
if (our_str_cmp(data->tokens[1], mensajes[k], length))
{
our_print(mensajes[k] + length + 1);
return (1);
}
}
errno = EINVAL;
perror(data->command_name);
return (0);
}

