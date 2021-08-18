#include "head.h"
/**
 * __printstring - function that print a string
 * @s: pointer to value of each simbol of string
 * Return: counter.
 */
int __printstring(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		__putchar(*s);
		s++;
		i++;
	}
	return (i);
}
