#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;
	for (; head && isascii(head->n) && head->n != '\0'; head = head->next)
	{
		printf("%c", head->n);
	}
	printf("\n");
}
