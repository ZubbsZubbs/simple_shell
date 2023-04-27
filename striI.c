#include "myshell.h"

/**
 * _strlen - Return the length of a string
 * @s: Pointer to the string to evaluate
 *
 * Return: The length of the string
 */
char *_strcpy(char *dest, char *src)
{
	int k = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[k])
	{
		dest[k] = src[k];
		i++;
	}
	dest[k] = 0;
	return (dest);
}


/**
 * _strcmp - Compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: 0 if strings are equal, negative value if s1 < s2, positive value if s1 > s2
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * starts_with - Check if a string starts with a given prefix
 * @haystack: String to evaluate
 * @needle: Prefix to search for
 *
 * Return: Pointer to the first character of the prefix in the string, or NULL if not found
 */
void _puts(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
	}
}
/**
 * _strcat - Concatenate two strings
 * @dest: Destination string
 * @src: Source string to append to destination
 *
 * Return: Pointer to the destination string
 */
int _putchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

