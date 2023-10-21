#include "our_shell.h"

/**
* our_get_env - gets the value of an environment variable
* @key: the environment variable of interest
* @data: struct of the program's data
* Return: a pointer to the value of the variable or NULL if it doesn't exist
*/
char *our_get_env(char *key, data_of_program *data)
{
int k, 
len = 0;

if (key == NULL || data->env == NULL)
return (NULL);

len = our_str_len(key);

for (k = 0; data->env[k]; k++)
{
if (our_str_cmp(key, data->env[k], len) &&
data->env[k][len] == '=')
{
return (data->env[k] + len + 1);
}
}
return (NULL);
}

/**
* _set_env - overwrite the value of the environment variable
* or create it if does not exist.
* @key: name of the variable to set
* @value: new value
* @data: struct of the program's data
* Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
*/

int _set_env(char *key, char *value, data_of_program *data)
{
int k, len = 0, new_key = 1;

if (key == NULL || value == NULL || data->env == NULL)
return (1);

len = our_str_len(key);

for (k = 0; data->env[k]; k++)
{
if (our_str_cmp(key, data->env[k], len) &&
data->env[k][len] == '=')
{
new_key = 0;
free(data->env[k]);
break;
}
}
data->env[k] = our_str_cat(our_str_dup(key), "=");
data->env[k] = our_str_cat(data->env[k], value);

if (new_key)
{
data->env[k + 1] = NULL;
}
return (0);
}

/**
* _remove_env - remove a key from the environment
* @key: the key to remove
* @data: the sructure of the program's data
* Return: 1 if the key was removed, 0 if the key does not exist;
*/
int _remove_env(char *key, data_of_program *data)
{
int k, len = 0;

if (key == NULL || data->env == NULL)
return (0);

len = our_str_len(key);

for (k = 0; data->env[k]; k++)
{
if (our_str_cmp(key, data->env[k], len) &&
data->env[k][len] == '=')
{
free(data->env[k]);

k++;
for (; data->env[k]; k++)
{
data->env[k - 1] = data->env[k];
}
data->env[k - 1] = NULL;
return (1);
}
}
return (0);
}


/**
* print_env - prints the current environ
* @data: struct for the program's data
* Return: nothing
*/
void print_env(data_of_program *data)
{
int k;

for (k = 0; data->env[k]; k++)
{
our_print(data->env[k]);
our_print("\n");
}
}
