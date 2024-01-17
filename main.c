#include "monty.h"

/**
 * main: Entry point of program
 * @argc: The number of argument passed to the command-line
 * @argv: An array of strings of argument.
 *
 * Return: Always 0 success
 */

int main(int argc, char **argv)
{
	FILE *fd;
	char *file_name;
	char *line_string;
	size_t n = 0;
	(void) argv;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];
	fd = fopen(file_name, "r");

	while (getline(&line_string, &n, fd) != -1)
	{
		printf("%s", line_string);
	}
	return(0);
}
