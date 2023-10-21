#include "our_shell.h"

/**
* _to_str - converts a number to a string.
* @number: number to be converten in an string.
* @string: buffer to save the number as string.
* @base: base to convert number
*
* Return: Nothing.
*/
void _to_str(long number, char *str, int base)
{
int idx = 0, neg = 0;
long cociente = number;
char alphabets[] = {"0123456789abcdef"};

if (cociente == 0)
str[idx++] = '0';

if (str[0] == '-')
neg = 1;

while (cociente)
{
if (cociente < 0)
str[idx++] = alphabets[-(cociente % base)];
else
str[idx++] = alphabets[cociente % base];
cociente /= base;
}
if (neg)
str[idx++] = '-';

str[idx] = '\0';
our_str_rev(str);
}


/**
* _atoi - convert a string to an integer.
*
* @s: pointer to str origen.
* Return: int of string or 0.
*/
int _atoi(char *str)
{
int flag = 1;
unsigned int num = 0;

while (!('0' <= *str && *str <= '9') && *str != '\0')
{
if (*str == '-')
flag *= -1;
if (*str == '+')
flag *= +1;
str++;
}

while ('0' <= *str && *str <= '9' && *str != '\0')
{

num = (num * 10) + (*str - '0');
str++;
}
return (num * flag);
}

/**
* char_count - count the coincidences of character in string.
*
* @str: pointer to str origen.
* @char: string with  chars to be counted
* Return: int of string or 0.
*/
int char_count(char *str, char *chara)
{
int k = 0, count = 0;

for (; str[k]; k++)
{
if (str[k] == chara[0])
count++;
}
return (count);
}
