#include "our_shell.h"
/**
* our_str_len - returns the length of a string.
* @string: pointer to string.
* Return: length of string.
*/
int our_str_len(char *str)
{
int len = 0;
if (str == NULL)
return (0);
while (str[len++] != '\0')
{
}
return (--len);
}
/**
* our_str_dup - duplicates an string
* @string: String to be copied
* Return: pointer to the array
*/
char *our_str_dup(char *str)
{
char *res;
int len, k;
if (str == NULL)
return (NULL);
len = our_str_len(str) + 1;
res = malloc(sizeof(char) * len);
if (res == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}
for (k = 0; k < len ; k++)
{
res[k] = str[k];
}
return (res);
}
/**
* our_str_cmp - Compare two strings
* @string1: String one, or the shorter
* @string2: String two, or the longer
* @number: number of characters to be compared, 0 if infinite
* Return: 1 if the strings are equals,0 if the strings are different
*/
int our_str_cmp(char *str1, char *str2, int num)
{
int loop;
if (str1 == NULL && str2 == NULL)
return (1);
if (str1 == NULL || str2 == NULL)
return (0);
if (num == 0) /* infinite longitud */
{
if (our_str_len(str1) != our_str_len(str2))
return (0);
for (loop = 0; str1[loop]; loop++)
{
if (str1[loop] != str2[loop])
return (0);
}
return (1);
}
else /* if there is a number of chars to be compared */
{
for (loop = 0; loop < num ; loop++)
{
if (str1[loop] != str2[loop])
return (0);
}
return (1);
}
}
/**
* our_str_cat - concatenates two strings.
* @string1: String to be concatenated
* @string2: String to be concatenated
*
* Return: pointer to the array
*/
char *our_str_cat(char *str1, char *str2)
{
char *res;
int len1 = 0, len2 = 0;
if (str1 == NULL)
str1 = "";
len1 = our_str_len(str1);
if (str2 == NULL)
str2 = "";
len2 = our_str_len(str2);
res = malloc(sizeof(char) * (len1 + len2 + 1));
if (res == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}
/* copy of string1 */
for (len1 = 0; str1[len1] != '\0'; len1++)
res[len1] = str1[len1];
free(str1);
/* copy of string2 */
for (len2 = 0; str2[len2] != '\0'; len2++)
{
res[len1] = str2[len2];
len1++;
}
res[len1] = '\0';
return (res);
}
/**
* our_str_rev - reverses a string.
*
* @string: pointer to string.
* Return: void.
*/
void our_str_rev(char *str)
{
int k = 0, len = our_str_len(str) - 1;
char wait;
while (k < len)
{
wait = str[k];
str[k++] = str[len];
str[len--] = wait;
}
}
