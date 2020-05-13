#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	if (*stack)
	{
		if ((*stack)->prev)
		{
			(*stack = (*stack)->next);
			return;
		}
		for	(; tmp->next; tmp = tmp->next)
			continue;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		/*stack circularized*/
		*stack = (*stack)->next;
		/*moved head to next position*/
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
