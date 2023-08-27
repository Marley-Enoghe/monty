#include "monty.h"
/**
 * op_check - The function that checks it a command
 * is an op-code
 * @str: The string to check
 * @line_number: The line number
 * Return: The function pointer or Void
 */

void (*op_check(char *str, unsigned int line_number))(stack_t **, unsigned int)
{

	int j;

	instruction_t instructions[] = {
		{"push", push_instruction},
		{"pall", pall_instruction},
		{"pint", pint_instruction},
		{"pop", pop_instruction},
		{"swap", swap_instruction},
		{"add", add_instruction},
		{"nop", nop_instruction},
		{"sub", sub_instruction},
		{"div", div_instruction},
		{"mul", mul_instruction},
		{"mod", mod_instruction},
		{"pchar", pchar_instruction},
		{NULL, NULL}};

	for (j = 0; instructions[j].opcode != NULL; j++)
	{
		if (strcmp(str, instructions[j].opcode) == 0)
		{
			return (instructions[j].f);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
	return (NULL);
}
