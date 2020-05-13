#include "monty.h"

/**
 * _swap -  swaps the top two elements of the stack
 * @stack: double pointer to the satack
 * @line_number: line number
 *
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (e_vars.len_stack < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev = tmp->prev;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->prev = *stack;
	if ((*stack)->prev)
		(*stack)->prev->next = (*stack);
	if (tmp->next)
		tmp->next->prev = tmp;
}
