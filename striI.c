#include "myshell.h"
/**
 * _strcpy - Copies the string
 * @dest: Pointer to destination buffer
 * @src: Pointer to source string
 *
 * Return: Pointer to destination buffer
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
 * _strdup - duplicate string
 * @str: Pointer to string to be duplicated
 *
 * Return: Pointer to duplicated string on success, NULL on failure
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
 * _puts - Writes a string to standard output
 * @str: Pointer to string to be written
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
 * _putchar - Writes a character to standard output
 * @c: Character to be written
 *
 * Return: 1 on success, -1 on failure
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

