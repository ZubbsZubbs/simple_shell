#include "our_shell.h"

/**
* our_getline - read one line from the prompt.
* @data: struct for the program's data
*
* Return: reading counting bytes.
*/
int our_getline(data_of_program *data)
{
char buff[BUFFER_SIZE] = {'\0'};
static char *array_commands[10] = {NULL};
static char array_operators[10] = {'\0'};
ssize_t bytes_read, i = 0;

if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
(array_operators[0] == '|' && errno == 0))
{
for (i = 0; array_commands[i]; i++)
{
free(array_commands[i]);
array_commands[i] = NULL;
}

bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
if (bytes_read == 0)
return (-1);

i = 0;
do {
array_commands[i] = our_str_dup(our_strtok(i ? NULL : buff, "\n;"));
i = check_logic_ops(array_commands, i, array_operators);
} while (array_commands[i++]);
}

data->input_line = array_commands[0];
for (i = 0; array_commands[i]; i++)
{
array_commands[i] = array_commands[i + 1];
array_operators[i] = array_operators[i + 1];
}

return (our_str_len(data->input_line));
}


/**
* check_logic_ops - checks and split for && and || operators
* @array_commands: array of the commands.
* @i: index in the array_commands to be checked
* @array_operators: array of the logical operators for each previous command
*
* Return: index of the last command in the array_commands.
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
char *temp = NULL;
int j;

for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
{
if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
{
temp = array_commands[i];
array_commands[i][j] = '\0';
array_commands[i] = our_str_dup(array_commands[i]);
array_commands[i + 1] = our_str_dup(temp + j + 2);
i++;
array_operators[i] = '&';
free(temp);
j = 0;
}
if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
{
temp = array_commands[i];
array_commands[i][j] = '\0';
array_commands[i] = our_str_dup(array_commands[i]);
array_commands[i + 1] = our_str_dup(temp + j + 2);
i++;
array_operators[i] = '|';
free(temp);
j = 0;
}
}
return (i);
}
