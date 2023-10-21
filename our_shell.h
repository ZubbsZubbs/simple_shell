#ifndef OUR_SHELL_H
#define OUR_SHELL_H
#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /* for errno and perror */
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h> /* for use of stat function */
#include <signal.h> /* for signal management */
#include <fcntl.h> /* for open files*/
/************* MACROS **************/
#include "macros.h" /* for msg help and prompt */
/************* STRUCTURES **************/
/**
 * struct info- struct for the program's data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */
typedef struct info
{
    char *program_name;
    char *input_line;
    char *command_name;
    int exec_counter;
    int file_descriptor;
    char **tokens;
    char **env;
    char **alias_list;
} data_of_program;
/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
    char *builtin;
    int (*function)(data_of_program *data);
} builtins;
/************* MAIN FUNCTIONS *************/
/*========  shell.c  ========*/
/* Initialize the struct with the info of the program */
void initializer(data_of_program *data, int arc, char *argv[], char **env);
/* Makes the infinite loop that shows the prompt*/
void promptt(char *prompt, data_of_program *data);
/* Print the prompt in a new line */
void _ctrl_c(int opr UNUSED);
/*========  our_getline.c  ========*/
/* Read one line of the standar input*/
int our_getline(data_of_program *data);
/* split the each line for the logical operators if it exist */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);
/*======== expansions.c ========*/
/* expand variables */
void expand_var(data_of_program *data);
/* expand aliases */
void expand_alias(data_of_program *data);
/* append the string to the end of the buffer*/
int buffer_add(char *buffer, char *str_to_add);
/*======== str_tok.c ========*/
/* Separate the string in tokens using a designed delimiter */
void toks(data_of_program *data);
/* Creates a pointer to a part of a string */
char *our_strtok(char *buf, char *delim);
/*======== execute.c ========*/
/* Execute a command with its entire path */
int exec(data_of_program *data);
/*======== builtins_list.c ========*/
/* If match a builtin, executes it */
int our_builtin(data_of_program *data);
/*======== find_in_path.c ========*/
/* Creates an array of the path directories */
char **tokenize_path(data_of_program *data);
/* Search for program in path */
int get_prog(data_of_program *data);
/************** HELPERS FOR MEMORY MANAGEMENT **************/
/*======== helpers_free.c ========*/
/* Frees the memory for directories */
void free_pointers(char **directories);
/* Free the fields needed each loop */
void free_repeat(data_of_program *data);
/* Free all field of the data */
void free_many(data_of_program *data);
/************** BUILTINS **************/
/*======== builtins_more.c ========*/
/* Close the shell */
int our_exit(data_of_program *data);
/* Change the current directory */
int our_cd(data_of_program *data);
/* set the work directory */
int our_set_dir(data_of_program *data, char *new_dir);
/* show help information */
int our_bui_help(data_of_program *data);
/*======== builtins_env.c ========*/
/* Shows the environment where the shell runs */
int our_env(data_of_program *data);
/* create or override a variable of environment */
int our_set_env(data_of_program *data);
/* delete a variable of environment */
int our_unset_env(data_of_program *data);
/************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT **************/
/*======== env_management.c ========*/
/* Gets the value of an environment variable */
char *our_get_env(char *name, data_of_program *data);
/* Overwrite the value of the environment variable */
int _set_env(char *key, char *value, data_of_program *data);
/* Remove a key from the environment */
int _remove_env(char *key, data_of_program *data);
/* prints the current environ */
void print_env(data_of_program *data);
/************** HELPERS FOR PRINTING **************/
/*======== helpers_print.c ========*/
/* Prints a string in the standar output */
int our_print(char *string);
/* Prints a string in the standar error */
int our_printe(char *string);
/* Prints a string in the standar error */
int our_print_err(int errorcode, data_of_program *data);
/************** HELPERS FOR STRINGS MANAGEMENT **************/
/*======== helpers_string.c ========*/
/* Counts the number of characters of a string */
int our_str_len(char *str);
/* Duplicates an string */
char *our_str_dup(char *str);
/* Compares two strings */
int our_str_cmp(char *str, char *str2, int num);
/* Concatenates two strings */
char *our_str_cat(char *str1, char *str2);
/* Reverse a string */
void our_str_rev(char *string);
/*======== helpers_numbers.c ========*/
/* Cast from int to string */
void _to_str(long number, char *string, int base);
/* convert an string in to a number */
int _atoi(char *s);
/* count the coincidences of character in string */
int char_count(char *string, char *character);
#endif /* SHELL_H */
