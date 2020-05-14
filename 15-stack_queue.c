#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the satack
 * @line_number: line number
 *
 * Return: nothing
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	e_vars.stack_mode = STACK;
}
/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the satack
 * @line_number: line number
 *
 * Return: nothing
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	e_vars.stack_mode = QUEUE;
}
