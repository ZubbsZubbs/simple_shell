#include "our_shell.h"
/**
* main - initialize the variables of the program
* @argc: number of values received from the command line
* @argv: values received from the command line
* @env: number of values received from the command line
* Return: zero on succes.
*/
int main(int argc, char *argv[], char *env[])
{
data_of_program data_struct = {NULL}, *data = &data_struct;
char *prompt = "";
initializer(data, argc, argv, env);
signal(SIGINT, _ctrl_c);
if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
{
errno = 2;
prompt = PROMPT_MSG;
}
errno = 0;
promptt(prompt, data);
return (0);
}
/**
* _ctrl_c - print the prompt in a new line
* when the signal SIGINT (ctrl + c) is send to the program
* @UNUSED: option of the prototype
*/
void _ctrl_c(int opr UNUSED)
{
our_print("\n");
our_print(PROMPT_MSG);
}
/**
* initializer- initialize the struct with the info of the program
* @data: pointer to the structure of data
* @argv: array of arguments pased to the program execution
* @env: environ pased to the program execution
* @argc: number of values received from the command line
*/
void initializer(data_of_program *data, int argc, char *argv[], char **env)
{
int k = 0;
data->program_name = argv[0];
data->input_line = NULL;
data->command_name = NULL;
data->exec_counter = 0;
/* define the file descriptor to be readed*/
if (argc == 1)
data->file_descriptor = STDIN_FILENO;
else
{
data->file_descriptor = open(argv[1], O_RDONLY);
if (data->file_descriptor == -1)
{
our_printe(data->program_name);
our_printe(": 0: Can't open ");
our_printe(argv[1]);
our_printe("\n");
exit(127);
}
}
data->tokens = NULL;
data->env = malloc(sizeof(char *) * 50);
if (env)
{
for (; env[k]; k++)
{
data->env[k] = our_str_dup(env[k]);
}
}
data->env[k] = NULL;
env = data->env;
data->alias_list = malloc(sizeof(char *) * 20);
for (k = 0; k < 20; k++)
{
data->alias_list[k] = NULL;
}
}
/**
* promptt - its a infinite loop that shows the prompt
* @prompt: prompt to be printed
* @data: its a infinite loop that shows the prompt
*/
void promptt(char *prompt, data_of_program *data)
{
int error = 0, len = 0;
while (++(data->exec_counter))
{
our_print(prompt);
error = len = our_getline(data);
if (error == EOF)
{
free_many(data);
exit(errno);
}
if (len >= 1)
{
expand_var(data);
toks(data);
if (data->tokens[0])
{
error = exec(data);
if (error != 0)
our_print_err(error, data);
}
free_repeat(data);
}
}
}
