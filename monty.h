#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct variables_s - structure with all the main's variables
 * @line: buffer for getline function
 * @len_line: length of buffer for getline function
 * @fp: file pointer
 * @opcode: name of opcode
 * @op: function pointer to opcodes functions
 * @stack: pointer to a double linked list
 * @lines: number of lines
 *
 * Description: estructure that contains the
 * variables of the main program
 */
typedef struct variables_s
{
	char *line;
	size_t len_line;
	FILE *fp;
	char *opcode;
	void (*op)(stack_t **stack, unsigned int line_number);
	stack_t *stack;
	unsigned int lines;
} vars_t;

/**
 * struct extern_variables_s - estruct of external variables
 * @op_arg: argument of the actual opcode in main program
 * @len_stack: stack length
 *
 * Description: structure that contains all the external variables
 * because it can be declared only one external variable, in this
 * case a instance of this structure
 */
typedef struct extern_variables_s
{
	char *op_arg;
	unsigned int len_stack;
} extern_variables_t;

extern_variables_t e_vars;

void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);
void init_vars(vars_t *vars);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_stack(stack_t *head);
void my_exit(int status, void *arg);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);

#endif
