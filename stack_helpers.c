#include "monty.h"

/**
 * free_stack - function that free a stack_t list
 * @head: pointer to the head of a stack_t list
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *next = NULL;

	for (; head; head = next)
	{
		next = head->next;
		free(head);
	}
	e_vars.len_stack = 0;
}

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list
 * @head: double pointer to the head of a stack_t list
 * @n: data
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
