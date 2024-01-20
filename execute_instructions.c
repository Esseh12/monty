#include "monty.h"
#include "push.c"
#include "pall.c"
#include "invalid_instruction.c"
/**
 * execute_instructions - holds all execution of instructions
 * @instructions_tok: array of string
 * Return: nothing
 */
void execute_instructions(char **instruction_tok, unsigned int line_number)
{
	int i = 0;
	unsigned int number;
	stack_t *stack = NULL;

	instruction_t instructions[1024] = {
		{"push", &push}, /*{"pop", &pop},
		{"pint", &pint}, {"swap", &swap},
		{"nop", &nop}, {"add", &add},*/
		{"pall", &pall}, /*{"sub", &sub},
		{"div", &_div}, {"mul", &mul},
		{"rot1", &rot1}, {"rotr", &rotr},
		{"stack", &stack}, {"queue", &queue},
		{"pstr", &pstr}, {"pchar", &pchar},
		{"mod", &mod},*/ {NULL, NULL}
	};

	for (; instructions[i].opcode != NULL; i++)
	{
		/* compare opcode of instruction against first value of instruction_tok */
		if (strcmp(instructions[i].opcode, instruction_tok[0]) == 0)
		{
			number = atoi(instruction_tok[1]);

			if (number == 0)
			{
				invalid_instruction(line_number);
			}
			instructions[i].f(&stack, atoi(instruction_tok[1]));
		}
		else
			invalid_instruction(line_number);
	}
}
