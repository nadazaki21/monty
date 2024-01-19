#include "monty.h"
/**
 * monty_stack - sets the flag to being a stack
 * @stack: pointer to a slack
 * @line_number: the line number
*/

void monty_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	main_stack.flag = 0;
}
/**
 * monty_queue - sets the flag to being a queue
 * @stack: pointer to a slack
 * @line_number: the line number
*/

void monty_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	main_stack.flag = 1;
}
