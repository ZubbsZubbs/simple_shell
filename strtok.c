#include "our_shell.h"
/**
* _strtok - separates strings with delimiters
* @line: It´s pointer to array we receive in getline.
* @delim: It´s characters we mark off string in parts.
* Return: A pointer to the created token
*/
char *our_strtok(char *buf, char *delim)
{
int k;
static char *s;
char *str;
if (buf != NULL)
s = buf;
for (; *s != '\0'; s++)
{
for (k = 0; delim[k] != '\0'; k++)
{
if (*s == delim[k])
break;
}
if (delim[k] == '\0')
break;
}
str = s;
if (*str == '\0')
return (NULL);
for (; *s != '\0'; s++)
{
for (k = 0; delim[k] != '\0'; k++)
{
if (*s == delim[k])
{
*s = '\0';
s++;
return (str);
}
}
}
return (str);
}
