#include "our_shell.h"

/**
* our_env - shows the environment where the shell runs
* @data: struct for the program's data
* Return: zero if sucess, or other number if its declared in the arguments
*/
int our_env(data_of_program *data)
{
int k;
char cpname[50] = {'\0'};
char *copy_v = NULL;

/* if not arguments */
if (data->tokens[1] == NULL)
print_env(data);
else
{
for (k = 0; data->tokens[1][k]; k++)
{
if (data->tokens[1][k] == '=')
{
copy_v = our_str_dup(our_get_env(cpname, data));
if (copy_v != NULL)
_set_env(cpname, data->tokens[1] + k + 1, data);

print_env(data);
if (our_get_env(cpname, data) == NULL)
{
our_print(data->tokens[1]);
our_print("\n");
}
else
{
_set_env(cpname, copy_v, data);
free(copy_v);
}
return (0);
}
cpname[k] = data->tokens[1][k];
}
errno = 2;
perror(data->command_name);
errno = 127;
}
return (0);
}

/**
* our_set_env - sets environment variable
* @data: struct for the program's data
* Return: zero if sucess, or other number if its declared in the arguments
*/
int our_set_env(data_of_program *data)
{
if (data->tokens[1] == NULL || data->tokens[2] == NULL)
return (0);
if (data->tokens[3] != NULL)
{
errno = E2BIG;
perror(data->command_name);
return (5);
}

_set_env(data->tokens[1], data->tokens[2], data);

return (0);
}

/**
* our_unset_env - unsets environment variables 
* @data: struct for the program's data'
* Return: 
*/
int our_unset_env(data_of_program *data)
{
if (data->tokens[1] == NULL)
return (0);
if (data->tokens[2] != NULL)
{
errno = E2BIG;
perror(data->command_name);
return (5);
}
_remove_env(data->tokens[1], data);

return (0);
}
