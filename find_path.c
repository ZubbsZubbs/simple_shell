#include "our_shell.h"

int checker(char *full_path);

/**
* get_prog - find a program in path
* @data: a pointer to the program's data
* Return: 0 if success, errcode otherwise
*/
int get_prog(data_of_program *data)
{
int k = 0, r_val = 0;
char **dir;

if (!data->command_name)
return (2);

/**if is a full_path or an executable in the same path */
if (data->command_name[0] == '/' || data->command_name[0] == '.')
return (checker(data->command_name));

free(data->tokens[0]);
data->tokens[0] = our_str_cat(our_str_dup("/"), data->command_name);
if (!data->tokens[0])
return (2);

dir = tokenize_path(data);/* search in the PATH */

if (!dir || !dir[0])
{
errno = 127;
return (127);
}
for (k = 0; dir[k]; k++)
{/* appends the function_name to path */
dir[k] = our_str_cat(dir[k], data->tokens[0]);
r_val = checker(dir[k]);
if (r_val == 0 || r_val == 126)
{/* the file was found, is not a directory and has execute permisions*/
errno = 0;
free(data->tokens[0]);
data->tokens[0] = our_str_dup(dir[k]);
free_pointers(dir);
return (r_val);
}
}
free(data->tokens[0]);
data->tokens[0] = NULL;
free_pointers(dir);
return (r_val);
}

/**
* tokenize_path - tokenize the path in directories
* @data: a pointer to the program's data
* Return: array of path directories
*/
char **tokenize_path(data_of_program *data)
{
int i = 0;
int counter_directories = 2;
char **tokens = NULL;
char *PATH;

PATH = our_get_env("PATH", data);
if ((PATH == NULL) || PATH[0] == '\0')
{
return (NULL);
}

PATH = our_str_dup(PATH);

for (i = 0; PATH[i]; i++)
{
if (PATH[i] == ':')
counter_directories++;
}

tokens = malloc(sizeof(char *) * counter_directories);

i = 0;
tokens[i] = our_str_dup(our_strtok(PATH, ":"));
while (tokens[i++])
{
tokens[i] = our_str_dup(our_strtok(NULL, ":"));
}

free(PATH);
PATH = NULL;
return (tokens);

}

/**
* check_file - checks if exists a file, if it is not a dairectory and
* if it has excecution permisions for permisions.
* @full_path: pointer to the full file name
* Return: 0 on success, or error code if it exists.
*/
int checker(char *full_path)
{
struct stat buf;

if (stat(full_path, &buf) != -1)
{
if (S_ISDIR(buf.st_mode) ||  access(full_path, X_OK))
{
errno = 126;
return (126);
}
return (0);
}
errno = 127;
return (127);
}
