#include "monty.h"
#include "tokenize_line.c"
#include "execute_instructions.c"

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
	int line_number = 0;
	char *linecpy;

	char *instructions_tok[1024];

	if (argc != 2)
	{
		dprintf(2, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];
	fd = fopen(file_name, "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line_string, &n, fd) != -1)
	{
		/*linecpy = malloc(sizeof(char) * (strlen(line_string) + 1));
		strcpy(linecpy, line_string);*/

		line_number++;

		tokenize_line(line_string, instructions_tok);
		free(linecpy);

		execute_instructions(instructions_tok, line_number);
	}

	return (0);
}
