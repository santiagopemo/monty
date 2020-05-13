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
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
}
