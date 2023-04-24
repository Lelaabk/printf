#include "main.h"
/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int size, int precision)
{
	char ch = va_arg(types, int);

	return (handle_write_char(ch, buffer, flags, width, size, precision));
}

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	int i, len = 0;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}
	return (write(1, s, len));
}
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	int i = BUFF_SIZE - 2, neg = 0;
	unsigned long int n;
	long int x = va_arg(types, long int);

	x = convert_size_number(x, size);

	if (x == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '0';
	n = (unsigned long int)x;

	if (x < 0)
	{
		n = (unsigned long int)((-1) * x);
		neg = 1;
	}
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_number(neg, i, buffer, flags, width, size, precision));
}
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	int c;
	unsigned int n, m, i, res, arr[32];

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	arr[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		arr[i] = (n / m) % 2;
	}
	for (i = 0, res = 0, c = 0; i < 32; i++)
	{
		res += arr[i];
		if (res || i == 31)
		{
			char k = '0' + arr[i];

			write(1, &k, 1);
			c++;
		}
	}
	return (c);
}
