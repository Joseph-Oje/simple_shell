#include "shell.h"

#define MAX_INPUT_LENGTH 1024

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("($) ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		size_t len = strlen(input);

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
