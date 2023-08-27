#ifndef MONTY
#define MONTY

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

extern int value;

/**
 * struct stack_s - The doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*opcode Instructions one*/
void push_instruction(stack_t **stack, unsigned int line_number);
void pall_instruction(stack_t **stack, unsigned int line_number);
void pint_instruction(stack_t **stack, unsigned int line_number);
void pop_instruction(stack_t **stack, unsigned int line_number);
void swap_instruction(stack_t **stack, unsigned int line_number);
void add_instruction(stack_t **stack, unsigned int line_number);
void nop_instruction(stack_t **stack, unsigned int line_number);
void sub_instruction(stack_t **stack, unsigned int line_number);
void div_instruction(stack_t **stack, unsigned int line_number);
void mul_instruction(stack_t **stack, unsigned int line_number);
void mod_instruction(stack_t **stack, unsigned int line_number);


/***/
void(*op_check(char *str, unsigned int line_number))(stack_t **, unsigned int);

#endif
