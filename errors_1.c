include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage_error - To Print the usage error messages.
 *
 * Return:Always (EXIT_FAILURE).
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Used to print malloc error messages.
 *
 * Return: Always (EXIT_FAILURE).
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - To print the file opening error messages w/ file name.
 * @filename: The name of file failed to open
 *
 * Return: Always (EXIT_FAILURE).
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - To print the unknown instruction error messages.
 * @opcode:The opcode where error occurred.
 * @line_number: The line number in Monty bytecodes file where error occured.
 *
 * Return:Always (EXIT_FAILURE).
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - To prints invalid monty_push argument error messages.
 * @line_number: The line number in Monty bytecodes file where error occurred.
 *
 * Return: Always (EXIT_FAILURE).
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
