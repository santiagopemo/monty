#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (e_vars.len_stack < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	_pop(stack, line_number);
}
