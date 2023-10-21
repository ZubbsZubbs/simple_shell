#include "our_shell.h"

/**
* expand_var - expand variables
* @data: a pointer to a struct of the program's data
*
* Return: nothing, but sets errno.
*/
void expand_var(data_of_program *data)
{
int k, l;
char len[BUFFER_SIZE] = {0}, exp[BUFFER_SIZE] = {'\0'}, *tmp;

if (data->input_line == NULL)
return;
buffer_add(len, data->input_line);
for (k = 0; len[k]; k++)
if (len[k] == '#')
len[k--] = '\0';
else if (len[k] == '$' && len[k + 1] == '?')
{
len[k] = '\0';
_to_str(errno, exp, 10);
buffer_add(len, exp);
buffer_add(len, data->input_line + k + 2);
}
else if (len[k] == '$' && len[k + 1] == '$')
{
len[k] = '\0';
_to_str(getpid(), exp, 10);
buffer_add(len, exp);
buffer_add(len, data->input_line + k + 2);
}
else if (len[k] == '$' && (len[k + 1] == ' ' || len[k + 1] == '\0'))
continue;
else if (len[k] == '$')
{
for (l = 1; len[k + l] && len[k + l] != ' '; l++)
exp[l - 1] = len[k + l];
tmp = our_get_env(exp, data);
len[k] = '\0', exp[0] = '\0';
buffer_add(exp, len + k + l);
tmp ? buffer_add(len, tmp) : 1;
buffer_add(len, exp);
}
if (!our_str_cmp(data->input_line, len, 0))
{
free(data->input_line);
data->input_line = our_str_dup(len);
}
}


/**
* buffer_add - append string at end of the buffer
* @buffer: buffer to be filled
* @str_to_add: string to be copied in the buffer
* Return: nothing, but sets errno.
*/
int buffer_add(char *buffer, char *str_to_add)
{
int len, k;

len = our_str_len(buffer);
for (k = 0; str_to_add[k]; k++)
{
buffer[len + k] = str_to_add[k];
}
buffer[len + k] = '\0';
return (len + k);
}
