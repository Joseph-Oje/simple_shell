#include "shell.h"

#define MAX_INPUT_LENGTH 1024

/**
 * _putchar - Custom function to print a character to stdout.
 * @c: The character to print.
 *
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	size_t len;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		len = strlen(input);

		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		system(input);
	}
	return (0);
}
