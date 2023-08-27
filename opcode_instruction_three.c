#include "monty.h"
/**
 * mod_instruction - The function that computes the rest of the division
 * @stack:stack
 * @line_number:line number
 */
void mod_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *top_Gun = NULL;
	stack_t *second_Gun = NULL;

	if (*stack && (*stack)->next)
	{
		top_Gun = *stack;
		second_Gun = (*stack)->next;

		if (top_Gun->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}

		second_Gun->n = second_Gun->n % top_Gun->n;
		top_Gun->next->prev = NULL;
		free(top_Gun);
		*stack = second_Gun;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar_instruction - The function that prints the char at the top of the stack
 * @stack: stack
 * @line_number: the line number
 */
void pchar_instruction(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->n)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			printf("%c\n", (char)(*stack)->n);
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
