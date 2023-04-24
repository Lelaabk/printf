#include "main.h"
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int size, int precision);
{
	char padd = ' ', c = 0;
	int i = BUFF_SIZE - 2, len = 2, padd_begin = 1;
	unsigned long n_addrs;
	char map[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	n_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[i--] = map[n_addrs % 16];
		n_addrs /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		c = '+', len++;
	else if (flags & F_SPACE)
		c = ' ', len++;
	i++;
	return (write_pointer(buffer, i, len, width, flags, padd, padd_begin, c));
}
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int size, int precision)
{
	int i = 0, offset = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		if (is_pritable(s[i]))
			buffer[i + offset] = s[i];
		else
			offset += append_hexa_code(s[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int size, int precision)
{
	int i, c = 0;
	char *s;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	s = va_arg(types, char *);
	if (s == NULL)
	{
		UNUSED(precision);
		s = ")NULL(";
	}
	for (i = 0; s[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char k = s[i];

		write(1, &k, 1);
		c++;
	}
	return (c);
}
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int size, int precision)
{
	char x, *s;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int c = 0;
	unsigned int i, j;

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == s[j])
			{
				x = out[j];
				write(1, &x, 1);
				c++;
				break;
			}
		}
		if (!in[j])
		{
			x = s[i];
			write(1, &x, 1);
			c++;
		}
	}
	return (c);
}
