#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Used to print the pop error messages for empty stacks.
 * @line_number: The line number in script where error occured.
 *
 * Return: Always (EXIT_FAILURE).
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Used to print pint error messages for empty stacks.
 * @line_number:The line number in Monty bytecodes file where error occurred.
 *
 * Return: Always (EXIT_FAILURE).
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Used to Print monty math function error messages
 * for stacks/queues smaller than two nodes.
 * @line_number: The line number in Monty bytecodes file where error occurred.
 * @op: Operation where error occurred.
 *
 * Return:Always (EXIT_FAILURE).
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error -To print division error messages for division by 0.
 * @line_number:The line number in Monty bytecodes file where error occurred.
 *
 * Return: Always (EXIT_FAILURE).
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - To print pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number:The line number in Monty bytecodes file where error occurred.
 * @message: This is the corresponding error message to print.
 *
 * Return: Always(EXIT_FAILURE).
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
