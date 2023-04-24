#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUSB 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
}

/**
 *typedef fmt_t - structure of format
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list,
		char buffer[], int flags, int width, int size, int precision);

int print_char(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_string(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_percent(va_list types, char buffer[],
	int flags, int width, int size, int precision);

int print_int(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_binary(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_octal(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int size, int precision);
int print_hexa(va_list types, char map[], char buffer[],
	int flags, char flags_ch, int width, int size, int precision);

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int size, int precision);

int print_pointer(va_list types, char buffer[],
	int flags, int width, int size, int precision);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);

int print_reverse(va_list types, char buffer[],
	int flags, int width, int size, int precision);

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int size, int precision);

int handle_write_char(char c, char buffer[],
		int flags, int int width, int size, int precision);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int size, int precision);
int write_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
		int width, int size, int precision);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
