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
	/*char *arg = strtok(NULL, " \n\t\r");*/
	char *arg = e_vars.op_arg;
	int i;
	stack_t *tmp;

	if (arg != NULL)
	{
		for (i = 0; arg[i]; i++)
		{
			if (arg[0] == '-')
				continue;
			if (isdigit(arg[i]) == 0)
				break;
		}
		if (arg[i] == '\0')
		{
			i = atoi(arg);
			tmp = add_dnodeint(stack, i);
			if (tmp == NULL)
			{
				printf("Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			e_vars.len_stack++;
			return;
		}
	}
	printf("L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
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
	stack_t *h = *stack;

	(void) line_number;
	for (; h; h = h->next)
	{
		printf("%d\n", h->n);
	}
}
