#include "monty.h"

/**
 * get_opcode - function that returns a function pointer to buildin function
 * @opcode: string with the opcode
 *
 * Return: fucntion pointer to function
 */
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			break;
	}
	return (instructions[i].f);
}
/**
 * init_vars - initializates tthe variables of a vars_t structure
 * @vars: pointer to a vars_t estructure
 *
 * Return: nothing
 */
void init_vars(vars_t *vars)
{
	vars->line = NULL;
	vars->len_line = 0;
	vars->fp = NULL;
	vars->opcode = NULL;
	vars->op = NULL;
	vars->stack = NULL;
	vars->lines = 1;
}
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of srings with the arguments
 *
 * Return: 0 on succes
 */
int main(int argc, char *argv[])
{
	vars_t vars;

	init_vars(&vars);
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	vars.fp = fopen(argv[1], "r");
	if (vars.fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; getline(&(vars.line), &(vars.len_line), vars.fp) != -1; vars.lines++)
	{
		vars.opcode = strtok(vars.line, " \n\t\r");
		if (vars.opcode == NULL || vars.opcode[0] == '#')
			continue;
		vars.op = get_opcode(vars.opcode);
		if (vars.op != NULL)
			vars.op(&(vars.stack), vars.lines);
		else
		{
			printf("L%d: unknown instruction %s\n", vars.lines, vars.opcode);
			/*free_stack(stack)*/
			free(vars.line);
			fclose(vars.fp);
			exit(EXIT_FAILURE);
		}
		free(vars.line);
		vars.line = NULL;
	}
	/*free_stack(stack)*/
	free(vars.line);
	fclose(vars.fp);
	return (EXIT_SUCCESS);
}