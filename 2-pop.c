#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to the satack
 * @line_number: line number
 *
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		(*stack)->next->prev = (*stack)->prev;
		if ((*stack)->prev)
			(*stack)->prev->next = (*stack)->next;
	}
	*stack = (*stack)->next;
	free(tmp);
	e_vars.len_stack--;
}
