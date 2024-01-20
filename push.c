#include "monty.h"

/**
 * push - the opcode push pushes an element to the stack.
 * @stack: the doubly linked list
 * Return: nothing
 */
void push(stack_t **stack, unsigned int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	new_node->n = data;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		new_node->prev = *stack;
		*stack = new_node;
	}

	else
	{
		while ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
		}
		(*stack)->next = new_node;
		new_node->prev = *stack;
	}
}
