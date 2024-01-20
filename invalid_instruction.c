#include "monty.h"

/**
 * invalid_instruction - prints out an error and exits the program
 * @line_number
 * Return: nothing
 */
void invalid_instruction(unsigned int line_number)
{
	printf("L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
