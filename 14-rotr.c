#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	if (*stack)
	{
		if ((*stack)->prev)
		{
			(*stack = (*stack)->prev);
			return;
		}
		for (; tmp->next; tmp = tmp->next)
			continue;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		/*stack circularized*/
		*stack = (*stack)->prev;
		/*moved head to prev position*/
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
