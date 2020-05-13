#include "monty.h"

/**
 * _mul - multiplies the second top element of
 * the stack with the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (e_vars.len_stack < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}
