#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: double pointer to the satack
 * @line_number: line number
 *
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == 0)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
