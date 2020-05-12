#include "monty.h"

/**
 * _push - push a element to the stack
 * @stack: double pointer to the satack
 * @line_number: line number
 *
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	printf("push %d!!\n", line_number);
}

/**
 * _pall - prints all the values on the stack
 * @stack: double pointer to the satack
 * @line_number: line number
 *
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	printf("pall %d!!\n", line_number);
}
