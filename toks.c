#include "our_shell.h"
/**
* toks - this function separate the string using a designed delimiter
* @data: a pointer to the program's data
* Return: an array of the different parts of the string
*/
void toks(data_of_program *data)
{
char *delim = " \t";
int k, l, count = 2, len;
len = our_str_len(data->input_line);
if (len)
{
if (data->input_line[len - 1] == '\n')
data->input_line[len - 1] = '\0';
}
for (k = 0; data->input_line[k]; k++)
{
for (l = 0; delim[l]; l++)
{
if (data->input_line[k] == delim[l])
count++;
}
}
data->tokens = malloc(count * sizeof(char *));
if (data->tokens == NULL)
{
perror(data->program_name);
exit(errno);
}
k = 0;
data->tokens[k] = our_str_dup(our_strtok(data->input_line, delim));
data->command_name = our_str_dup(data->tokens[0]);
while (data->tokens[k++])
{
data->tokens[k] = our_str_dup(our_strtok(NULL, delim));
}
}
