#include "our_shell.h"
/**
* _print - writes a array of chars in the standar output
* @string: pointer to the array of chars
* Return: the number of bytes writed or .
* On error, -1 is returned, and errno is set appropriately.
*/
int our_print(char *str)
{
return (write(STDOUT_FILENO, str, our_str_len(str)));
}
/**
* _printe - writes a array of chars in the standar error
* @string: pointer to the array of chars
* Return: the number of bytes writed or .
* On error, -1 is returned, and errno is set appropriately.
*/
int our_printe(char *str)
{
return (write(STDERR_FILENO, str, our_str_len(str)));
}
/**
* our_print_err - writes a array of chars in the standart error
* @data: a pointer to the program's data'
* @errorcode: error code to print
* Return: the number of bytes writed or .
* On error, -1 is returned, and errno is set appropriately.
*/
int our_print_err(int errorcode, data_of_program *data)
{
char n_as_string[10] = {'\0'};
_to_str((long) data->exec_counter, n_as_string, 10);
if (errorcode == 2 || errorcode == 3)
{
our_printe(data->program_name);
our_printe(": ");
our_printe(n_as_string);
our_printe(": ");
our_printe(data->tokens[0]);
if (errorcode == 2)
our_printe(": Illegal number: ");
else
our_printe(": can't cd to ");
our_printe(data->tokens[1]);
our_printe("\n");
}
else if (errorcode == 127)
{
our_printe(data->program_name);
our_printe(": ");
our_printe(n_as_string);
our_printe(": ");
our_printe(data->command_name);
our_printe(": not found\n");
}
else if (errorcode == 126)
{
our_printe(data->program_name);
our_printe(": ");
our_printe(n_as_string);
our_printe(": ");
our_printe(data->command_name);
our_printe(": Permission denied\n");
}
return (0);
}
