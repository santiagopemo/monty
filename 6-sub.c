#include "monty.h"

/**
 * _sub -  subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (e_vars.len_stack < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	_pop(stack, line_number);
}
