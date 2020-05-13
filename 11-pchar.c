#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < -1 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
