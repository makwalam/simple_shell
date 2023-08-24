#include <stdio.h>

/**
 * _print_string - Prints a string followed by a newline
 * @str: The input string to print
 *
 * Return: None
 */
void _print_string(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
	putchar('\n');
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	const char *message = "Hello, Betty!";
	
	_print_string(message);
	return (0);
}
