#include "our_shell.h"
/**
* exec - execute a command.
* @data: a pointer to the program's data
* Return: If sucess returns zero, otherwise, return -1.
*/
int exec(data_of_program *data)
{
int r_val = 0, stat;
pid_t p;


r_val = our_builtin(data);
if (r_val != -1)
return (r_val);

r_val = get_prog(data);
if (r_val)
{
return (r_val);
}
else
{
p = fork(); 
if (p == -1)
{ 
perror(data->command_name);
exit(EXIT_FAILURE);
}
if (p == 0)
{
r_val = execve(data->tokens[0], data->tokens, data->env);
if (r_val == -1) 
perror(data->command_name), exit(EXIT_FAILURE);
}
else
{
wait(&stat);
if (WIFEXITED(stat))
errno = WEXITSTATUS(stat);
else if (WIFSIGNALED(stat))
errno = 128 + WTERMSIG(stat);
}
}
return (0);
}
