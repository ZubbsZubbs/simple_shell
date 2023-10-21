#include "our_shell.h"
/**
* our_builtin - execute the associate builtin after searching for match
* @data: struct for the program's data
* Return: Returns the return of the function executed is there is a match,
* otherwise returns -1.
**/
int our_builtin(data_of_program *data)
{
int loop;
builtins options[] = {
{"exit", our_exit},
{"help", our_bui_help},
{"cd", our_cd},
{"env", our_env},
{"setenv", our_set_env},
{"unsetenv",  our_unset_env},
{NULL, NULL}
};
for (loop = 0; options[loop].builtin != NULL; loop++)
{
if (our_str_cmp(options[loop].builtin, data->command_name, 0))
return (options[loop].function(data));
}
return (-1);
}
