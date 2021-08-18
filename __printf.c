#include "head.h"
#include <stdarg.h>
#include <stdint.h>

/**
 * __withformat - fucntion for know format
 * @c: string by format
 * @count: integer counter
 * @valist: structure va list
 * Return: return to counter
 */

int __withformat(char c, int count, va_list valist)
{
	int j, i;
	char *s;
	char si[6] = "(null)";

	switch (c)
	{
	case 's':
		s = va_arg(valist, char *);
		if (!s)
		{
			for (i = 0; si[i]; i++, count++)
				__putchar(si[i]);
		}
		else
			count += __printstring(s);
		break;
	case 'd':
		j = va_arg(valist, int);

		if (!j)
		{
			count++;
			__putchar('0');
		} else
			count += print_number(j);
		break;
	default:
		count += 2;
		__putchar('%');
		__putchar(c);
	}
	return (count);
}

/**
 * __printf - Fuction that prints to the std output
 * @format: list of parameters passed
 * Return: @count the number of characters printed
 */
int __printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list valist;

	va_start(valist, format);

	if (!format)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count++;
			__putchar(format[i]);
		}
		else if (format[i + 1])
		{
			i++;
			count = __withformat(format[i], count, valist);
		}
		else
			return (-1);
	}
	va_end(valist);
	return (count);
}
