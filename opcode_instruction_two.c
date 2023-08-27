#include "monty.h"

/**
 * add_instruction - For adding the top two elements of the stack
 * @stack:Stack
 * @line_number:Line number
 */
void add_instruction(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *top_Gun = NULL;
	stack_t *second_Gun = NULL;

	if (*stack && (*stack)->next)
	{
		top_Gun = *stack;
		second_Gun = (*stack)->next;
		sum = top_Gun->n + second_Gun->n;
		second_Gun->n = sum;
		second_Gun->prev = NULL;
		free(top_Gun);
		*stack = second_Gun;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_instruction - For doing nothing
 * @stack: Stack
 * @line_number: Line number
 */
void nop_instruction(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_instruction - subtracts the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
*/
void sub_instruction(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack && (*stack)->next)
	{
		topGun = *stack;
		secondGun = (*stack)->next;
		diff = topGun->n - secondGun->n;
		secondGun->n = diff;
		topGun->next->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_instruction - divides the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void div_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack && (*stack)->next)
	{
		topGun = *stack;
		secondGun = (*stack)->next;
		if (topGun->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		secondGun->n = secondGun->n / topGun->n;
		topGun->next->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	}
}

/**
 * mul_instruction - multiplies the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void mul_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack && (*stack)->next)
	{
		topGun = *stack;
		secondGun = (*stack)->next;

		secondGun->n = secondGun->n * topGun->n;
		topGun->next->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
