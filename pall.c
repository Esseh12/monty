#include "monty.h"

/**
 * pall -  prints all the values on the stack, starting from the top of the stack
 * @stack - the doubly linked list
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int data)
{
	if (*stack == NULL)
		return;

	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}

	while ((*stack)->prev != NULL)
	{
		printf("%d", (*stack)->n);
		*stack = (*stack)->next;
	}
}
